class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt = 0;
        for (const auto& c : data) {
            if (cnt == 0) {
                if ((c >> 5) == 6) cnt = 1;
                else if ((c >> 4) == 14) cnt = 2;
                else if ((c >> 3) == 30) cnt = 3;
                else if ((c >> 7) == 0) cnt = 0;
                else return false;
            } else {
                if ((c >> 6) != 2) return false;
                cnt--;
            }
        }
        if(cnt > 0) return false;
        else return true;
    }
};
