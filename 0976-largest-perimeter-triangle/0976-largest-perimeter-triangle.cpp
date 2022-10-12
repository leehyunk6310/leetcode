// 가장 긴 변의 길이가 다른 두 변의 합보다 크거나 같으면 0을 return
// a + b > c
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int answer = 0;    
                 
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<nums.size()-2; i++)
        {
            if (nums[i] + nums[i+1] > nums[i+2])
                answer = nums[i] + nums[i+1] + nums[i+2];
        }
        
        
        return answer;
    }
};