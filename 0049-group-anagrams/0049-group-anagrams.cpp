class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0)
            return {};
        
        unordered_map<string, vector<string>> m;
        vector<vector<string>> answer;
        for (auto str : strs)
        {
            string s = str;
            sort(str.begin(), str.end());
            
            m[str].push_back(s);        
        }
        
        for (auto mm : m)
            answer.push_back(mm.second);
            
        return answer;
    }
};