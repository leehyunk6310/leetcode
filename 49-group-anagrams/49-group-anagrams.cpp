class Solution {
public:
     vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
         if (strs.size() == 1)
             return {strs};
         
         vector<vector<string>> ans;
         unordered_map<string, vector<string>> m;
         
         for (int i=0; i<strs.size(); i++)
         {
             string str = strs[i];
             sort(strs[i].begin(), strs[i].end());
             m[strs[i]].push_back(str);
         }
         
         for (auto mm : m)
             ans.push_back(mm.second);
         
         return ans;
    }
};