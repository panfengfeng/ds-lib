#ifndef _LOUDS_H_
#define _LOUDS_H_

#include <iostream>
#include <vector>


namespace louds {

using namespace std;

class BitVector {
    public:
        int operator[](int pos) {
            return (bv[pos] == true ? 1 : 0);
        }

        void push(int elem) {
            if (elem == 1 || elem == 0) {
                bv.push_back((bool) elem);
            }
        }

        void push_n(int elem, int n) {
            if (elem == 1 || elem == 0) {
                for (int i = 0; i < n; i++) {
                    bv.push_back((bool) elem);
                }
            }
        }

        int size() const {
            return bv.size();
        }
    private:
        vector<bool> bv;
};

class SuccinctBitVector {
    public:
        SuccinctBitVector() { }
        ~SuccinctBitVector() { }
        int operator[](int pos) {
            return bv[pos];
        }

        void push(int elem) {
            bv.push(elem);
        }

        void push_n(int elem, int n) {
            bv.push_n(elem, n);
        }

        int size() const {
            return bv.size();
        }

        int rank(int pos, int b) {  // 在位置pos之前等于b的个数
            int count = 0;
            for (int i = 0; i <= pos; i++) {
                if (bv[i] == b) {
                    count++;
                }
            }
            return count;
        }

        int select(int count, int b) { // 第count个等于b的位置
            if (count <= 0) {
                return -1;
            }

            for (int i = 0; i < bv.size(); i++) {
                if (bv[i] == b) {
                    count--;
                }
                if (count == 0) {
                    return i;
                }
            }
            return -1;
        }

        int rank0(int pos) {
            return rank(pos, 0);
        }

        int rank1(int pos) {
            return rank(pos, 1);
        }

        int select0(int count) {
            return select(count, 0);
        }

        int select1(int count) {
            return select(count, 1);
        }

        void debug() {
            for (int i = 0; i < bv.size(); i ++) {
                cout << bv[i] << endl;
            }
        }
    private:
        BitVector bv;
};

class LOUDSTrie {
    public:
       LOUDSTrie(vector<string>& words) {
            build(words);
       }

       LOUDSTrie(SuccinctBitVector lbs,
               SuccinctBitVector terminal,
               vector<char> edge) {
           this->lbs = lbs;
           this->terminal = terminal;
           this->edge = edge;
       }

       vector<int> common_prefix_search(const string& str) {
           vector<int> result;
           int n = 0;
           for(int i = 0; i < str.size(); i++) {
               char c = str[i];
               n = traverse(n, c);
               if (n == -1) {
                   break;
               }

               int m = lbs.rank1(n) - 2;
               if (terminal[m] != 0) {
                   result.push_back(m);
               }
           }
           return result;
       }

       int parent(int x) {
           return lbs.select1(lbs.rank0(x));
       }

       int first_child(int x) {
           int y = lbs.select0(lbs.rank1(x)) + 1;
           if (lbs[y] == 0) {
               return -1;
           }
           else {
               return y;
           }
       }

       int traverse(int pos, char c) {
           int child_pos = first_child(pos);
           if (child_pos == -1) {
               return -1;
           }

           int m = lbs.rank1(child_pos) - 2;
           while (child_pos < lbs.size() && lbs[child_pos] == 1 && m < edge.size()) {
               if (edge[m] == c) {
                   return child_pos;
               }
               child_pos++;
               m++;
           }
           return -1;
       }

       string id2word(int id) {
           string result = "";
           int pos = lbs.select1(id + 2);

           do {
               int m = lbs.rank1(pos) - 2;
               result = edge[m] + result;
               pos = parent(pos);
           } while(pos != 0);
           return result;
       }

    private:
       SuccinctBitVector lbs;
       SuccinctBitVector terminal;
       vector<char> edge;

       void build(vector<string>& words) {
            sort(words.begin(), words.end());
            words.erase(unique(words.begin(), words.end()), words.end());
            lbs.push(1);
            lbs.push(0);

            map<char,bool> dict;
            for (int i = 0; i < words.size(); i++) {
                dict[words[i][0]] = true;
            }
            lbs.push_n(1, dict.size());
            lbs.push(0);
            bfs(words);
       }
}

}


#endif
