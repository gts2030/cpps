// Palindrome Pairs

#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// Function to reverse a string
string reverse(string str) {
    string result = "";
    for (int i=str.length()-1; i>=0; i--)
        result += str[i];

    return result;
}

bool isPalindrome(string input) {
    for(int i = 0; i < input.length(); i++) {
        if(input[i] != input[input.length() - i - 1])
            return false;
    }
    return true;
}

struct Node {
    int index = -1;
    map<char, Node*> child; 
};

class Trie {
public:
    Node *root;
    Trie() {
        root = new Node();
    }
    
    void insert(std::string word, int idx) {
        Node *cur = root;
        for(int i = 0; i < word.length(); i++) {
            if((cur->child).count(word.at(i)) == 0) // if cur char doesn't exist in map
                (cur->child).insert(pair<char, Node*>(word.at(i), new Node())); // insert
            cur = cur->child[word.at(i)];
        }
        cur->index = idx;
    }
    
    int search(std::string word) {
        Node *cur = root;
        for(int i = 0; i < word.length(); i++) {
            if((cur->child).size() == 0) {
                if(isPalindrome(word.substr(i, word.size() - i - 1)))
                    return cur->index;
            }
            else if((cur->child).count(word.at(i)) == 0)
                return -1;
            cur = cur->child[word.at(i)];
        }
        return cur->index;
    }
    
    bool startsWith(std::string prefix, Node *end) {
        Node *cur = root;
        for(int i = 0; i < prefix.length(); i++) {
            if((cur->child).count(prefix.at(i)) == 0)
                return false;
            cur = cur->child[prefix.at(i)];
        }
        end = cur;
        return true;
    }

    vector<int> findPalindrome(Node* input) {
        Node* cur = input;
        
    }
};



class Solution {
public:
    vector<vector<int> > palindromePairs(vector<string>& words) {
        vector<vector<int> > result;
        Trie trie;
        // input reversed words into trie
        for(int i = 0; i < words.size(); i++) {
            trie.insert(reverse(words[i]), i);
        }

        // search for exactly reversed word and longer word
        for(int i = 0; i < words.size(); i++) {
            int idx = trie.search(words[i]);
            if(i != idx && idx != -1) {
                vector<int> tmp = {i, idx};
                result.push_back(tmp);
            }
        }

        // prefix search and ispalindrome
        for(int i = 0; i < words.size(); i++) {
            Node* endpoint;
            if(trie.startsWith(words[i], endpoint)) {
                vector<int> idxs = trie.findPalindrome(endpoint);
                for(const auto& idx : idxs) {
                    if(i != idx && idx != -1) {
                    vector<int> tmp = {i, idx};
                    result.push_back(tmp);
                    } 
                }
            }
        }

        return result;
    }
};

int main() {
    return 0;
}