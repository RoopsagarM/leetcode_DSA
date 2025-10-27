class Solution {
public:
    void helper(int row, int col, vector<vector<int>>& grid, int& count){
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size()) return;
        if(grid[row][col] == 0) return;
        grid[row][col] = 0;
        count++;

        helper(row-1, col, grid, count);
        helper(row, col+1, grid, count);
        helper(row+1, col, grid, count);
        helper(row, col-1, grid, count);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count = 0, maxLen = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int count = 0;
                    helper(i, j, grid, count);
                    maxLen = max(maxLen, count);
                }
            }
        }
        return maxLen;
    }
};