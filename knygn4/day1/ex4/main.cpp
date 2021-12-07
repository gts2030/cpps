// Add and Search Word - Data structure design
#include <string>
#include <map>

using namespace std;

struct Node {
    bool isword;
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
        cur->isword = true;
    }
    
    bool search(std::string word, Node* node) {
        Node *cur = node;
        for(int i = 0; i < word.length(); i++) {
            if(word.at(i) == '.') {
                if((cur->child).size() == 0)
                    return false;
                bool result = false;
                for(const auto& element : cur->child) {
                    result = result || search(word.substr(i+1, word.length()-i-1), element.second);
                }
                return result;
            }
            else if((cur->child).count(word.at(i)) == 0)
                return false;
            else
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

class WordDictionary {
public:
    Trie* dictionary; 
    WordDictionary() {
        dictionary = new Trie;
    }
    
    void addWord(string word) {
        dictionary->insert(word);
    }
    
    bool search(string word) {
        return dictionary->search(word, dictionary->root);
    }
};

int main() {
    WordDictionary wordDictionary;
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    wordDictionary.search("pad"); // return False
    wordDictionary.search("bad"); // return True
    wordDictionary.search(".ad"); // return True
    wordDictionary.search("b.."); // return True
}