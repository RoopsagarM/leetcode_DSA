class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int count = 0;
        for(int dif = 0; dif < n; dif++){
            for(int i = 0, j = dif; j < n; i++, j++){
                if(dif==0){
                    // if(i == j){
                        dp[i][j] = true;
                    // }
                }
                else if(dif == 1){
                    if(s[i] == s[j]){
                        dp[i][j] = true;
                    }
                }
                else{
                    if(s[i] == s[j]){
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                if(dp[i][j] == true) count++;
            }
        }
        return count;
    }
};