#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Node {
    int node;
    int len;
};

int solution(vector<vector<int>> bomb, vector<vector<int>> box, int K) {
    int answer = 0;

    vector<queue<Node>> list;
    for(int i = 0; i < bomb.size(); i++) {
        queue<Node> t;
        Node tmp;
        tmp.node = -1;
        tmp.len = -1;
        t.push(tmp);
        list.push_back(t);
    }

    // make graph
    for(int i = 0; i < bomb.size(); i++) {
        list[i].pop();
        for(int j = 0; j < bomb.size(); j++) {
            if(i == j) continue;
            if(bomb[i][0] == bomb[j][0]) {
                int len = abs(bomb[i][1] - bomb[j][1]);
                // check box occlusion
                bool valid = true;
                for(const auto& bx : box) {
                    if(bx[0] == bomb[i][0] && (bx[1]-bomb[i][1])*(bx[1]-bomb[j][1]) < 0)
                        valid = false;
                }

                // if no occlusion, input to graph
                if(valid) {
                    Node tmp;
                    tmp.node = j;
                    tmp.len = len;
                    list[i].push(tmp);
                }
            }

            if(bomb[i][1] == bomb[j][1]) {
                int len = abs(bomb[i][0] - bomb[j][0]);
                // check box occlusion
                bool valid = true;
                for(const auto& bx : box) {
                    if(bx[1] == bomb[i][1] && (bx[0]-bomb[i][0])*(bx[0]-bomb[j][0]) < 0)
                        valid = false;
                }

                // if no occlusion, input to graph
                if(valid) {
                    Node tmp;
                    tmp.node = j;
                    tmp.len = len;
                    list[i].push(tmp);
                }
            }
        }
    }

    // BFS
    for(int i = 0; i < list.size(); i++) {
        queue<Node> Q;
        if(list[i].size() > 0) 
            answer++;
        
        while(!list[i].empty()) {
            Node cur = list[i].front();
            list[i].pop();
            if(cur.len <= K) {
                Q.push(cur);
            }
        }

        while(!Q.empty()) {
            Node cur = Q.front();
            Q.pop();

            while(!list[cur.node].empty()) {
                Node tmp = list[cur.node].front();
                list[cur.node].pop();
                if(tmp.len <= K) {
                    Q.push(tmp);
                }
            }
        }
    }


    return answer;
}

int main() {
    vector<vector<int>> bomb = {{3, 1}, {0, 1}, {5, 1}, {0, 4}, {4, 4}, {5, 3}};
    vector<vector<int>> box = {{1, 1}, {2, 2}};
    int K1 = 3, K2 = 1;
    cout << solution(bomb, box, K1) << endl;
    cout << solution(bomb, box, K2) << endl;
    
    return 0;
}