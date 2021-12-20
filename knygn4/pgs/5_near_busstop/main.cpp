#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<int>> solution(int N, vector<vector<int>> bus_stop) {
    vector<vector<int>> answer(N, std::vector<int>(N, -1));

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    // build bus_stop
    for(const auto& stop : bus_stop)
        answer[stop[0]-1][stop[1]-1] = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            vector<vector<int>> dist(N, std::vector<int>(N, -1));
            queue<pair<int, int>> que;

            // root init
            dist[i][j] = 0;
            que.push(pair<int, int>(i,j));

            while(!que.empty()) {
                pair<int, int> cur = que.front();
                que.pop();

                if(answer[cur.first][cur.second] == 0)  {
                    answer[i][j] = dist[cur.first][cur.second];
                    break;
                }

                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) 
                        continue;
                    if(dist[nx][ny] >= 0) 
                        continue;
                    dist[nx][ny] = dist[cur.first][cur.second] + 1; 
                    que.push({nx, ny});
                }
            }
        }
    }
    
    return answer;
}




int main() {
    int N1 = 3;
    vector<vector<int>> bus_stop1 = {{1,2}};
    vector<vector<int>> sol = solution(N1, bus_stop1);
    for(int i = 0; i < N1; i++) {
        for(int j = 0; j < N1; j++) {
            cout << sol[i][j] << ", ";
        }
        cout << endl;
    }

    cout << "--------------" << endl;;

    int N2 = 3;
    vector<vector<int>> bus_stop2 = {{1, 2}, {3, 3}};
    vector<vector<int>> sol2 = solution(N2, bus_stop2);
    for(int i = 0; i < N2; i++) {
        for(int j = 0; j < N2; j++) {
            cout << sol2[i][j] << ", ";
        }
        cout << endl;
    }
    return 0;
}