class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<int> ans;
        
        for (auto num : nums)
            m[num]++;
        
        while (k)
        {
            int maxVal = 0;
            int maxCount = 0;
            
            for (auto mm : m)
            {
                if (mm.second > maxCount)
                {
                    maxCount = mm.second;
                    maxVal = mm.first;
                }
            }
            
            ans.push_back(maxVal);
            m[maxVal] = 0;
            k--;
        }
        
        return ans;
    }
};