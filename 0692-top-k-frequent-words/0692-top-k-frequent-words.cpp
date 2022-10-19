class Comparator
{
    public:
        bool operator() (pair<int, string> p1, pair<int, string> p2)
        {
            if (p1.first == p2.first) return p1.second > p2.second;
            
            return p1.first < p2.first;
        }
};


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string, int> m;
        priority_queue<pair<int, string>, vector<pair<int, string>>, Comparator> pq;    
        vector<string> answer;
        
        for (auto word : words)
            m[word]++;
        
        for (auto mm : m)
        {
            pq.push({mm.second, mm.first});
        }                
        
        for (int i=0; i<k; i++)
        {
            answer.push_back(pq.top().second);
            pq.pop();
        }
        
        return answer;
    }
};