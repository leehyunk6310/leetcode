class Solution {
public:
    string breakPalindrome(string palindrome) {                   
        if (palindrome.size() <= 1)
            return "";
        
        // 중간까지 이동하면서 a가 아닌 부분이 있으면 a로 교체하고 return
        for (int i = 0; i < palindrome.size() / 2; i++)
        {
            if(palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                return palindrome;                
            }
        }
        palindrome[palindrome.size() - 1] = 'b';
        return palindrome;        
        }
    
};