class Solution {
public:
    string addBinary(string a, string b) {
        // 각 문자열을 뒤집는다
        // 더해서 벡터에 넣는다
        // carry를 사용한다.
        int minlen = min(a.size(), b.size());
        int carry = 0;
        vector<char> v;
        
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        for (int i=0; i<minlen; i++)
        {
            if (carry == 0)
            {
                if (a[i] == '0' && b[i] == '0')
                {
                    v.push_back('0');
                    carry = 0;
                }                    
                if (a[i] == '1' && b[i] == '0')
                {
                    v.push_back('1');
                    carry = 0;
                }
                    
                if (a[i] == '0' && b[i] == '1')
                {
                    v.push_back('1');
                    carry = 0;
                }
                if (a[i] == '1' && b[i] == '1')
                {
                    v.push_back('0');
                    carry = 1;
                }
                    
            }
            else
            {
                if (a[i] == '0' && b[i] == '0')
                {
                    v.push_back('1');
                    carry = 0;
                }                    
                if (a[i] == '1' && b[i] == '0')
                {
                    v.push_back('0');
                    carry = 1;
                }
                    
                if (a[i] == '0' && b[i] == '1')
                {
                    v.push_back('0');
                    carry = 1;
                }
                if (a[i] == '1' && b[i] == '1')
                 {
                    v.push_back('1');
                    carry = 1;
                }
            }  
        }
        
        
        if (a.size() > b.size())
        {
            for (int i=minlen; i<a.size(); i++)
            {
                if (carry == 0)
                {
                    if (a[i] == '0')
                    {
                        v.push_back('0');
                        carry = 0;
                    }
                    if (a[i] == '1')
                    {
                        v.push_back('1');
                        carry = 0;
                    }
                }
                else
                {
                    if (a[i] == '0')
                    {
                        v.push_back('1');
                        carry = 0;
                    }
                    if (a[i] == '1')
                    {
                        v.push_back('0');
                        carry = 1;
                    }
                }
            }
        }
        else
        {
            for (int i=minlen; i<b.size(); i++)
            {
                if (carry == 0)
                {
                    if (b[i] == '0')
                    {
                        v.push_back('0');
                        carry = 0;
                    }
                    if (b[i] == '1')
                    {
                        v.push_back('1');
                        carry = 0;
                    }
                }
                else
                {
                    if (b[i] == '0')
                    {
                        v.push_back('1');
                        carry = 0;
                    }
                    if (b[i] == '1')
                    {
                        v.push_back('0');
                        carry = 1;
                    }
                }
            }
        }
        
        if (carry == 1)
            v.push_back('1');
        reverse(v.begin(), v.end());
        
        string ans(v.begin(), v.end());
        
        return ans;
    }
};