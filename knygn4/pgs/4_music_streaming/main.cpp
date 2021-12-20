#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// left cnt right cnt sliding window
int solution(vector<int> play_list, int listen_time) {
    int answer = 0;
    int idx_f = 0, idx_b = 0;
    vector<int> list;
    list.reserve(play_list.size() * 20000);

    int tmp = 1;
    int sum = 0;
    for(int x = 0; x < 2; x++)
        for(const auto& time : play_list) {
            sum += time;
            for(int i = 0; i < time;  i++)
                list.push_back(time);
        }

    if(sum <= listen_time) {
        return play_list.size();
    }
    
    while(idx_f < sum + listen_time) {
        // initialize
        if(idx_f < listen_time - 1) {
            if(list[idx_f] != list[idx_f+1])
                tmp++;
            idx_f++;
        }
        else {
            if(list[idx_f] != list[idx_f+1])
                tmp++;
            if(list[idx_b] != list[idx_b+1])
                tmp--;
            idx_f++;
            idx_b++;
        }
        if(tmp > answer)
            answer = tmp;
        // cout << "(idx_f, idx_b, tmp, answer) : " << idx_f << ", " << idx_b << ", " << tmp << ", " << answer << endl;
    }

    return answer;
}

int main() {
    vector<int> play_list = {2, 3, 1, 4};
    int listen_time = 3;
    cout << "result : " << solution(play_list, listen_time) << endl;

    vector<int> play_list2 = {1, 2, 3, 4};
    int listen_time2 = 5;
    cout << "result : " << solution(play_list2, listen_time2) << endl;

    vector<int> play_list3 = {1, 2, 3, 4};
    int listen_time3 = 20;
    cout << "result : " << solution(play_list3, listen_time3) << endl;
    return 0;
}