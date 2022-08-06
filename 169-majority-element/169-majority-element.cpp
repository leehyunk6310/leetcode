class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int ,int> m;
        int idx = 0;
        int val = 0;
        
        for (int i=0; i<nums.size(); i++)
        {
            if (m[nums[i]] == 0)
                m[nums[i]] = 1; 
            else
                m[nums[i]]++;
        }
        
        for (auto e : m)
        {
            if (e.second > val)
            {                
                val = e.second;
                idx = e.first;
            }
        }
        
        return idx;
        
    }
};