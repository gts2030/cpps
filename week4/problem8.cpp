// O(N), O(1) 
#include <algorithm> 
#include <array>  
class Solution { 
public:     
	int leastInterval(vector<char>& tasks, int n) {         
		if(n == 0) return tasks.size();
		std::array<int, 26> cnts;
		cnts.fill(0);
		for(const auto &task : tasks)
			cnts[static_cast<int>(task) - 65]++;
		std::sort(cnts.begin(), cnts.end(), greater<int>()); 
		int idle;
		idle = (cnts[0] - 1) * n;
		for(int i = 1; i < cnts.size(); i++) {
			if(i <= n) idle -= std::min(cnts[i], cnts[0]-1);
			else idle -=cnts[i];
		}         
		std::cout << "idle : " << idle << std::endl;
		std::cout << "tasks : " << tasks.size() << std::endl;
		if(idle < 0) return tasks.size();
		else return idle + tasks.size();
	}
};