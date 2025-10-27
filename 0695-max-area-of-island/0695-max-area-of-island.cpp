class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, int& count){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
        if(grid[i][j] == 0) return;
        grid[i][j] = 0;
        count++;
        dfs(i-1, j, grid, count);
        dfs(i+1, j, grid, count);
        dfs(i, j-1, grid, count);
        dfs(i, j+1, grid, count);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxCount = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]){
                    int count = 0;
                    dfs(i, j, grid, count);
                    maxCount = max(count, maxCount);
                }
            }
        }
        return maxCount;
    }
};