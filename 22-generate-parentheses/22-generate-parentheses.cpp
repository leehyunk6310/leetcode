class Solution {
public:
    vector<string> ans;
    
    vector<string> generateParenthesis(int n) {
        string s = "";
        solve(n, 0, 0, s);
        
        return ans;
        
    }
    
    void solve(int n, int open, int close, string s)
    {
        if (open < close)
            return;
        if (open == n && close == n)
        {
            ans.push_back(s);
            return;            
        }
            
        if (open < n)
            solve(n, open+1, close, s + '(');
        if (open > close)
            solve(n, open, close+1, s+')');
            
        
        
        
        
    }
};