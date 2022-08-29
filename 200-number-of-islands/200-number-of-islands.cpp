class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // 7:13
        int ans = 0;
        
        for (int i=0; i<grid.size(); i++)
        {
            for (int j=0; j<grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    solve(i, j, grid);
                    
                    ans++;
                }
            }
        }
                
        return ans;
    }
    
    // 동서남북 방향으로 방문한 지점을 2로 변경한다
    // 더이상 방문할 곳이 없을 때까지 함수를 호출
    void solve(int row, int col, vector<vector<char>>& grid)
    {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
            return;
        
        if (grid[row][col] == '2' || grid[row][col] == '0')
            return;
        
        grid[row][col] = '2';
        
        
        solve(row-1, col, grid);
        solve(row+1, col, grid);
        solve(row, col-1, grid);
        solve(row, col+1, grid);
    }
};