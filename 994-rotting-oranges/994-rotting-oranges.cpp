class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        pair<int, int> p;
        queue<pair<int, int>> q;
        int ans = 0;
        
        // 처음에 썩은 토마토 위치를 q에 담는다
        for (int i=0; i<grid.size(); i++)
        {
            for (int j=0; j<grid[0].size(); j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        
        
        
        // q가 빌때까지 check함수를 실행
        while(q.size())
        {
            p = q.front();
            int row = p.first;
            int col = p.second;
            
            q.pop();
            
            check(row+1, col, grid, q, grid[row][col]);
            check(row-1, col, grid, q, grid[row][col]);
            check(row, col+1, grid, q, grid[row][col]);
            check(row, col-1, grid, q, grid[row][col]);            
        }
        
        // fresh orange가 존재하면 -1 리턴
        // 아닌경우 ans-2를 리턴한다.
        for (int i=0; i<grid.size(); i++)
        {
            for (int j=0; j<grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                    return -1;
                if (ans < grid[i][j])
                    ans = grid[i][j];
            }
        }
        
        if (ans == 0)
            return 0;
        else if (ans == 1)
            return -1;
        
        return ans-2;
    }
    
    void check(int row, int col, vector<vector<int>>& grid, queue<pair<int, int>>& q, int val)
    {
        // 방문 못하면 return 해버린다
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
            return;
        
        if (grid[row][col] != 1)
            return;
        
        // 방문 가능하면 q에다 넣는다.
        q.push({row, col});
        
        // 방문했던 장소의 값을 추가해서 업데이트한다.
        val++;
        grid[row][col] = val;
    }
    
    
    
    
};