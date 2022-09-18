class Solution {
public:
    int trap(vector<int>& height) {
        int dp[height.size()], currMax = -1, res = 0;
        
        for (int i=0; i<height.size(); i++)
        {
            int curr = height[i];
            currMax = max(currMax, curr);
            dp[i] = currMax - curr;
        }
        
        currMax = -1;
        
        for (int i=height.size()-1; i>=0; i--)
        {
            int curr = height[i];
            currMax = max(currMax, curr);
            res += min(dp[i], currMax - curr);
        }
        
        return res;
    }
};