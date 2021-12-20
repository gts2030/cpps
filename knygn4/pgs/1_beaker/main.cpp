// Beaker
#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

int solution(int a, int b, int c, int d) {
    int answer = 0;
    int precnt = -1;
    int cnt = 3;

    array<int, 101> volume = {0};
    volume[a] = 1;
    volume[b] = 1;
    volume[c] = 1;
    
    while(true) {
        precnt = cnt;
        vector<int> tmp;

        // insert volumes to tmp
        for(int i = 0; i < volume.size(); i++)
            if(volume[i]>0) {
                tmp.push_back(i);
            }
                
        // calculate volumes and add to tmp
        
        for(const auto& num1 : tmp) {
            for(const auto& num2 : tmp) {
                int diff = num1 - num2;
                if(diff > 0) {
                    if(volume[diff] == 0) {
                        cnt++;
                        volume[diff] = volume[num1] + volume[num2];
                    }
                    if(diff == d) {
                        answer = volume[diff] + 1;
                        return answer;
                    }
                }
            }
        }

        if(precnt >= cnt) {
            answer = -1;
            break;
        }
    }
    return answer;
}

int main() {
    cout << solution(2,5,7,1) << endl;
    cout << solution(3,6,9,4) << endl;
    cout << solution(2,6,13,1) << endl;
    return 0;
}