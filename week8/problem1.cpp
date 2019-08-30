// O(N * 2^N)/O(1)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int id = 1 << nums.size();
        while(id > 0) {
            vector<int> tmp;
            int t = --id;
            for(int i = 0; i < nums.size(); i++) {
                if(t & 1) tmp.push_back(nums[i]);
                t = t >> 1;
            }
            result.push_back(tmp);
        }
        return result;
    }
};
