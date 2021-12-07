// Map Sum Pairs

#include <string>
#include <map>

struct Node {
    int val = 0;
    std::map<char, Node*> child;
};

class MapSum {
public:
    Node* root;
    MapSum() {
        root = new Node();
    }
    
    void insert(std::string key, int val) {
        Node* cur = root;
        for (int i = 0; i < key.length(); i++) {
            if((cur->child).count(key.at(i)) == 0)
                (cur->child).insert(std::pair<char, Node*>(key.at(i), new Node()));
            cur = cur->child[key.at(i)];
        }
        cur->val = val;
    }

    int dfs(Node* root) {
        int sum = 0;
        for (const auto &node : root->child) {
            sum += node.second->val;
            sum += dfs(node.second);
        }
        return sum;
    }

    int sum(std::string prefix) {
        Node *cur = root;
        
        for(int i = 0; i < prefix.length(); i++) {
            if((cur->child).count(prefix.at(i)) == 0)
                return 0;
            cur = cur->child[prefix.at(i)];
        }
        // sum below nodes (dfs)
        if((cur->child).size() == 0)
            return cur->val;
        else
            return dfs(cur) + cur->val;
    }
};

int main() {
    MapSum mapSum;
    mapSum.insert("apple", 3);  
    mapSum.sum("ap");           // return 3 (apple = 3)
    mapSum.insert("app", 2);    
    mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)

    return 0;
}