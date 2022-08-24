class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        
        for (auto num : nums)
            m[num]++;
        
        for (auto mm : m)
        {
            if (mm.second != 1)
                return mm.first;
        }
        
        return 0;
    }
};