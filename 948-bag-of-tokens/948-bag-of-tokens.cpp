class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // up => lose power => +1 score
        // down -> get power -> -1 score
        int answer = 0;        
        
        if (tokens.size() == 0)
            return 0;
        
        sort(tokens.begin(), tokens.end());
        
        int l = 0; 
        int r = tokens.size()-1;
        
        if (tokens[l] > power) 
            return 0;
        
        
        while (l <= r)
        {                        
            if (tokens[l] <= power)
            {
                power -= tokens[l];
                answer++;
                l++;
            }
            else if (tokens[r] >= tokens[l] && answer !=0 && r != l)
            {
                power += tokens[r];
                r--;
                answer--;
            }        
            else if (l==r)
                break;
        }
        
        return answer;
        
        
    }
};