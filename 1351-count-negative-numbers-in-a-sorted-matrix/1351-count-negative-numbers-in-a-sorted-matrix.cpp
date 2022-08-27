class Solution {
public:
    // 10:51
    int solve(vector<int> v)
    {
        int low = 0;
        int high = v.size() - 1;
                
        while (low <= high)
        {
            int mid = low + (high-low)/2;
            
            if (v[mid] >= 0)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return v.size() - low;
    }
    
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        
        for (int i=0; i<grid.size(); i++)
            ans += solve(grid[i]);
        
        return ans;
    }
};