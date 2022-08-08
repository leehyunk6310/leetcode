class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 1;
        int prev1 = 2;
        int sum = 0;
        int count = 3;
        
        while (1)
        {
            if (n == 1)
                return 1;
            if (n == 2)
                return 2;
            
            sum = prev1 + prev2;
            
            if (count == n)
                break;
            
            prev2 = prev1;
            prev1 = sum;
            count++;
        }
        return sum;
    }
};