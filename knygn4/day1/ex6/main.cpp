// Word Search 2
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Node {
    string word = "";
    map<char, Node*> child; 
};

class Trie {
public:
    Node *root;
    Trie() {
        root = new Node();
    }
    
    void insert(std::string word) {
        Node *cur = root;
        for(int i = 0; i < word.length(); i++) {
            if((cur->child).count(word.at(i)) == 0) // if cur char doesn't exist in map
                (cur->child).insert(pair<char, Node*>(word.at(i), new Node())); // insert
            cur = cur->child[word.at(i)];
        }
        cur->word = word;
    }
};


class Solution {
public:
    Trie trie;
    vector<vector<char> > totalboard;
    int w, h;
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        totalboard = board;
        vector<string> result;
        for(const auto& word : words) {
            trie.insert(word);
        }

        w = board.size();
        h = board[0].size();
        for(int i = 0; i < w; i++) {
            for(int j = 0; j < h; j++) {
                string tmp = check(i, j, trie.root);
                if(tmp != "")
                    result.push_back(tmp);
            }
        }

    }

    string check(int x, int y, Node* node) {
        Node* cur = node;
    
        for(const auto& next : node->child) {
            if(totalboard[x][y] == next.first) {
                if(next.second->word != "")
                    return next.second->word;
                else {
                    // up
                    if(y - 1 > 0) {
                        if(check(x, y-1, next.second) != "") {
                            
                        }
                    }
                    // right
                    if(x + 1 < w) {

                    }
                    // down
                    if(y + 1 < h) {

                    }
                    // left
                    if(x - 1 > 0) {

                    }
                }
            }
            else return "";
        }
    }
};

int main() {
    return 0;
}
