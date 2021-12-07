// Maximum XOR of Two Numbers in an Array

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

string reverse(string str) {
    string result = "";
    for (int i=str.length()-1; i>=0; i--)
        result += str[i];

    return result;
}

string toBinary(int n) {
    string r;
    while (n != 0){
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
    return r;
}

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

    int insertwithcalc(std::string word, int maxlen) {
        Node *cur = root;
        Node *comp = root;
        int maxnum = 0;
        for(int i = 0; i < word.length(); i++) {
            int num = word[i]- '0';
            // cout << "num : " << num << endl;
            char num2char = num % 2 == 0 ? '0' : '1';
            char flipped = num % 2 == 0 ? '1' : '0';
            // cout << "num2char / flipped : " << num2char << " / " << flipped << endl;
            if(comp->child.count(flipped) > 0) { // check fliped num exists in child node
                maxnum += pow(2, maxlen - i - 1);
                comp = comp->child[flipped];
            }
            else {
                comp = comp->child[num2char];
            }

            if((cur->child).count(word.at(i)) == 0) // if cur char doesn't exist in map
                (cur->child).insert(pair<char, Node*>(word.at(i), new Node())); // insert
            cur = cur->child[word.at(i)];
            // cout << "maxnum calculated : " << maxnum << endl;
        }
        cur->isword = true;
        return maxnum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int maxnum = 0;
        int maxlen = 0;

        vector<string> snums;
        vector<string> inputs;
        for(const auto& num : nums) {
            string s = toBinary(num);
            if(s.length() > maxlen)
                maxlen = s.length();
            snums.push_back(s);
        }
        // cout << "maxlen : " << maxlen << endl;
        
        // make binary nums to full length nums
        for(auto& snum : snums) {
            int len = snum.length();
            for(int i = 0; i < maxlen - len; i++)
                snum += "0";
            inputs.push_back(reverse(snum));
        }

        for(const auto& input : inputs) {
            if(trie.root->child.size() == 0) {
                trie.insert(input);
                // cout << input << " inserted!" << endl;
            }
            else {
                int max = trie.insertwithcalc(input, maxlen);
                if(max > maxnum)
                    maxnum = max;
                // cout << input << "inserted" << endl;
            }
        }
        return maxnum;
    }
};

int main() {
    return 0;
}