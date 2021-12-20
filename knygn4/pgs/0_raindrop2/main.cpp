#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <array>

using namespace std;

struct Node {
    pair<int,int> root;
    vector<pair<int, int>> child; 
};

int solution(vector<vector<int>> bricks) {
    int answer = 0;
    int n = bricks.size();
    int m = bricks[0].size();

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    for(int i = 1; i < m-1; i++) {
        for(int j = 1; j < n-1; j++) {
            bool visit[n][m];
            for(int a = 0; a < n; a++)
                for(int b = 0; b < m; b++)
                    visit[a][b] = false;
                    
            queue<pair<int, int>> Q;
            stack<Node> S;
            vector<vector<int>> copy = bricks;

            visit[j][i] = true;
            Q.push({i, j});

            while(!Q.empty()) {
                pair<int, int> cur = Q.front();
                Q.pop();
                Node tmp;
                tmp.root = cur;

                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if(!(nx < 0 || nx > m || ny < 0 || ny > n) && !visit[ny][nx]) 
                        tmp.child.push_back({nx,ny});
                    if(nx < 1 || nx >= m-1 || ny < 1 || ny >= n-1) continue;
                    if(visit[ny][nx]) continue;
                    visit[ny][nx] = true;
                    Q.push({nx, ny});
                }
                S.push(tmp);
            }

            while(!S.empty()) {
                Node cur = S.top();
                S.pop();
                int min = 2000;
                
                for(auto & elem:cur.child) 
                    if(min > copy[elem.second][elem.first]) 
                        min = copy[elem.second][elem.first];

                if(copy[cur.root.second][cur.root.first] < min)
                    copy[cur.root.second][cur.root.first] = min;

                if(S.size() == 0) 
                    answer += copy[j][i] - bricks[j][i];
            }
        }
    }
    if(answer == 0) answer = -1;
    return answer;
}

int main() {
    vector<vector<int>> bricks1 = {{2,4,3,2,3,2}, {3,1,1,4,1,3}, {2,2,2,3,3,1}};
    vector<vector<int>> bricks2 = {{2, 2, 2}, {1,2,2}, {1,2,1}};
    vector<vector<int>> bricks3 = {{4,4,4,4}, {4,1,2,3}, {2,3,3,1}};
    vector<vector<int>> bricks4 = {{5,5,5,5}, {4,1,1,5}, {3,1,1,5}, {5,5,5,5}};
    vector<vector<int>> bricks5 = {{4,1,1,3,1}, {4,1,2,0,2}, {4,1,1,2,2}};

    cout << solution(bricks1) << endl; // 4
    cout << solution(bricks2) << endl; // -1
    cout << solution(bricks3) << endl; // 3
    cout << solution(bricks4) << endl; // 8
    cout << solution(bricks5) << endl; // 2

    return 0;
}