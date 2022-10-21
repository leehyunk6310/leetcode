class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        
        for (int i=0; i<nums.size(); i++)
        {
            // 같은 수가 등장했을때 이전 인덱스와 현재 인덱스를 비교한다.
            // 인덱스가 0인 경우 체크하기 위해 count를 사용
            if (m.count(nums[i]))
            {
                if (abs(m[nums[i]] - i) <= k)
                    return true;
            }
            
            // 인덱스를 저장한다.
            m[nums[i]] = i;
        }
        
        return false;
    }
};