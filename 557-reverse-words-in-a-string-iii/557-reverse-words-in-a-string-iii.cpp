class Solution {
public:
    string reverseWords(string s) {
        string temp = "";
        vector<string> v;
        string answer = "";
        
        for (int i=0; i<s.size(); i++)
        {
            if (i == s.size() - 1)
            {
                temp += s[i];
                v.push_back(temp);
            }
                
            
            if (s[i] != ' ')
                temp += s[i];
            else
            {
                v.push_back(temp);
                temp = "";
            }
        }
        
        for (auto& s : v)
        {
            reverse(s.begin(), s.end());
            answer += (s == v.back() ? s : (s + " "));
        }
        
        return answer;
    }
};