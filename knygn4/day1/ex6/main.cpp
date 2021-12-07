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
    
    string search(char word, Node* cur, Node* next) {
        for(int i = 0; i < word.length(); i++) {
            if((cur->child).count(word.at(i)) == 0)
                return "";
            cur = cur->child[word.at(i)];
        }
        return cur->word;
    }
};


class Solution {
public:
    Trie trie;
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        for(const auto& word : words) {
            trie.insert(word);
        }

        int w = board.size();
        int h = board[0].size();
        for(int i = 0; i < w; i++) {
            for(int j = 0; j < h; j++) {

            }
        }

    }

    string check(int x, int y) {

    }
};

int main() {
    return 0;
}
