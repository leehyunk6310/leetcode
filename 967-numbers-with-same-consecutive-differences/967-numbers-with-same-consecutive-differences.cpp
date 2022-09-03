class Solution {
public:        
    vector<int> numsSameConsecDiff(int n, int k) {
        // 1:17
        vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        
        for (int i=0; i<n-1; i++)
        {
            vector<int> vv;
            
            for (auto num1 : v)
            {
                int num2 = num1 % 10;
                
                if (num2 + k < 10)
                    vv.push_back(num1*10 + num2 + k);
                if (num2 - k >= 0 && k != 0)
                    vv.push_back(num1*10 + num2 - k);                
            }
            v = vv;
            
        }
         
        return v;
    }       
};

