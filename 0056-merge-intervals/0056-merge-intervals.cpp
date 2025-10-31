class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });
        vector<int> prev = intervals[0];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] > prev[1]){
                ans.push_back(prev);
                prev = intervals[i];
            }
            else{
                prev[1] = max(prev[1], intervals[i][1]);
            }
        }
        ans.push_back(prev);
        return ans;
    }
};