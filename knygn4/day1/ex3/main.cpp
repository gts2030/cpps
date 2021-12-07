// Replace Words
#include <iostream>
#include <string>
#include <vector>
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

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // sentence to words
        vector<string> words;
        string space_delimiter = " ";
        size_t pos = 0;
        while ((pos = sentence.find(space_delimiter)) != string::npos) {
            words.push_back(sentence.substr(0, pos));
            sentence.erase(0, pos + space_delimiter.length());
        }
        words.push_back(sentence);

        // sort dictionary from long word
        std::sort(dictionary.begin(), dictionary.end(), [] (const std::string& first, const std::string& second) {
            return first.size() > second.size();
        });

        // Replace words
        string result = "";
        for(const auto& word : words) {
            string input = " ";
            Trie trie;
            trie.insert(word);
            for(const auto& dic : dictionary) {
                if(trie.startsWith(dic))
                    input = dic;
            }
            
            if(input == " ")
                result += (word + " ");
            else
                result += (input + " ");
        }

        return result.substr(0, result.size() -1);
    }
};

int main() {
    Solution sol;
    vector<string> dic;
    dic.push_back("cat");
    dic.push_back("bat");
    dic.push_back("rat");
    cout << sol.replaceWords(dic, "the cattle was rattled by the battery") << endl;

    return 0;
}