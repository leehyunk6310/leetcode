class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        priority_queue<int> pq;
        int ans = 0;
        int count = 0;
        
        for (auto a : arr) m[a]++;
        for (auto mm : m) pq.push(mm.second);
        
        while (count < arr.size() / 2)
        {
            ans += 1;
            count += pq.top();
            pq.pop();
        }
        
        return ans;
    }
};