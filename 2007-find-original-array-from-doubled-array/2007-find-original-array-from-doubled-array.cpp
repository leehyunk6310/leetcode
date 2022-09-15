class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int, int> m;
        vector<int> ans;
        
        for (auto n : changed)
            m[n]++;
        
        sort(changed.begin(), changed.end());
        
        for (auto n : changed)
        {
            if (m[n] && m[2*n])
            {
                m[n]--;
                m[2*n]--;
                ans.push_back(n);
            }
        }
        
        for (auto mm : m)
            if (mm.second != 0)
                return {};
        
        return ans;
        
    }
};