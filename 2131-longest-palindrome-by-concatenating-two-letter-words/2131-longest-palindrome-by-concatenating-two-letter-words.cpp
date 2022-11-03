// 앞뒤가 같은 word와 그렇지 않은 word로 나누어서 생각한다.
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> m;
        int answer = 0;
        int unpaired = 0;
        
        for (auto word : words)
        {            
            if (word[0] == word[1])
            {
                if (m[word] == 0)
                {
                    m[word]++;
                    unpaired++;
                }
                else
                {
                    m[word]--;
                    unpaired--;
                    answer += 4;
                }
            }
            // word와 rev의 짝이 맞으면 += 4
            else
            {
                string rev = word;
                reverse(rev.begin(), rev.end());
                
                if (m[rev] > 0)
                {
                    answer += 4;
                    m[rev]--;
                }
                else
                    m[word]++;
            }
        }
        
        if (unpaired > 0)   answer += 2;
        
        return answer;
        
    }
};