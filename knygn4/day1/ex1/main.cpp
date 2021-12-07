// Implement Trie (Prefix Tree)
#include <iostream>
#include <map>
#include <string>

struct Node {
    bool isword;
    std::map<char, Node*> child; 
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
                (cur->child).insert(std::pair<char, Node*>(word.at(i), new Node())); // insert
            cur = cur->child[word.at(i)];
        }
        cur->isword = true;
    }
    
    bool search(std::string word) {
        Node *cur = root;
        for(int i = 0; i < word.length(); i++) {
            if((cur->child).count(word.at(i)) == 0)
                return false;
            cur = cur->child[word.at(i)];
        }
        return cur->isword;
    }
    
    bool startsWith(std::string prefix) {
        Node *cur = root;
        for(int i = 0; i < prefix.length(); i++) {
            if((cur->child).count(prefix.at(i)) == 0)
                return false;
            cur = cur->child[prefix.at(i)];
        }
        return true;
    }
};

int main() {
    // Your Trie object will be instantiated and called as such:
    Trie trie;
    trie.insert("apple");
    std::cout << trie.search("apple") << std::endl;   // return True
    std::cout << trie.search("app") << std::endl;     // return False
    std::cout << trie.startsWith("app") << std::endl; // return True
    trie.insert("app");
    std::cout << trie.search("app") << std::endl;     // return True
    
    return 0;
}