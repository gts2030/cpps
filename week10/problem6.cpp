// O(N) / O(1)
class Solution {
public:
   int numDecodings(string s) {
       if(s[0] == '0') return 0;
       else if(s.length() == 1) return 1;
       else if(s.substr(s.size() - 2) == "00") return 0;
       else if(s.length() == 2) {
           if(stoi(s) > 29) {
               if(s[1] == '0') return 0;
               else return 1;
           } else if(stoi(s) > 10 && stoi(s) < 20) return 2;
           else if(stoi(s) > 20 && stoi(s) < 27) return 2;
           else return 1;
       } else {
           int prev1 = 0, prev2 = 0, tmp = 0;
           if(s[0] != 0) prev2 = 1;
           
           if(stoi(s.substr(0, 2)) > 29) {
               if(s[1] == '0') prev1 = 0;
               else prev1 = 1;
           } else if(stoi(s.substr(0, 2)) > 10 && stoi(s.substr(0, 2)) < 20) prev1 = 2;
           else if(stoi(s.substr(0, 2)) > 20 && stoi(s.substr(0, 2)) < 27) prev1 = 2;
           else prev1 = 1;
           
           for(int i = 2; i < s.size(); i++) {
               tmp = 0;
               if(s[i] == '0') {
                   if(stoi(s.substr(i-1, 2)) > 26 || s[i-1] == '0') return 0;
                   else {
                       tmp = prev2;
                       prev2 = prev1;
                       prev1 = tmp;
                   }
               } else if(stoi(s.substr(i-1, 2)) < 27 && stoi(s.substr(i-1, 2)) > 10) {
                   tmp = prev2 + prev1;
                   prev2 = prev1;
                   prev1 = tmp;
               } else prev2 = prev1;
           }
           return prev1;
       }
   }
};
