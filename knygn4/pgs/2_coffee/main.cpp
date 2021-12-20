// coffee machine
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> coffee_times) {
    vector<int> answer;
    vector<int> nums(N, 0);
    vector<int> machines(N, 0);

    int done = 0;
    while(done <= coffee_times.size()) {
        // find empty machines
        vector<int> empty;
        for(int i = 0; i < machines.size(); i++) {
            if(machines[i] == 0)
                empty.push_back(i);
        }

        // put orders into machines
        for(auto& machine : empty) {
            machines[machine] = coffee_times[done];
            done++;
            if(done <= coffee_times.size())
                nums[machine] = done;
            else   
                nums[machine] = 0;
        }

        // run 1 turn
        for(int i = 0; i < machines.size(); i++) {
            if(machines[i] > 0) {
                machines[i]--;
                if(machines[i] == 0)
                    answer.push_back(nums[i]);
            }
        }
    }

    // run left machine without adding coffee
    vector<pair<int, int> > left_pairs;
    for(int i = 0; i < machines.size(); i++) {
        if(machines[i] != 0) {
            left_pairs.push_back(pair<int,int>(machines[i],nums[i]));
        }
    }
    sort(left_pairs.begin(), left_pairs.end());
    for(const auto& number : left_pairs)
        answer.push_back(number.second); 

    return answer;
}

int main() {
    int N = 3;
    vector<int> coffe_times1 = {4, 2, 2, 5, 3};
    for (const auto& sol : solution(N, coffe_times1)) 
        cout << sol << ", ";
    cout << endl;

    N = 1;
    vector<int> coffe_times2 = {100, 1, 50, 1, 1};
    for (const auto& sol : solution(N, coffe_times1)) 
        cout << sol << ", ";
    cout << endl;

    return 0;
}