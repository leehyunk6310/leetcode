class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> answer;
        int dp=0;
        
        for (auto num : nums)
            if (num%2 == 0)
                dp += num;
        
        for (auto query : queries)
        {
            if (nums[query[1]]%2 == 0)
                dp -= nums[query[1]];
                
            nums[query[1]] += query[0];
            
            if (nums[query[1]]%2 == 0)
                dp += nums[query[1]];
            
            answer.push_back(dp);
        }
        
        return answer;
        
        
        
    }
};