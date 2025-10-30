class Solution {
public:
    int robHelper(int i, vector<int>& nums, vector<int>& dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];

        int take = nums[i] + robHelper(i+2, nums, dp);
        int notTake = robHelper(i+1, nums, dp);

        return dp[i] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return robHelper(0, nums, dp);
    }
};