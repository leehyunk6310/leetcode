// start에서 bank에 있는 원소 첫번째부터 bfs를 실시한다.
// 매 bfs마다 bank의 문자와 현재 문자가 1개의 차이만 있음을 체크한다.
// 
// 방문하지 않은 bank안에서 다시 찾아본다.
class Solution {
public:
    int answer = 1e9;
    
    // 1개의 문자열만 차이가 있는지 확인한다.
    bool check(string s1, string s2)
    {
        int cnt = 0;
        for (int i=0; i<s1.size(); i++)
        {
            if (s1[i] != s2[i])
                cnt++;
            if (cnt >= 2)
                return false;
        }
        
        if (cnt == 1)
            return true;
        
        return false;
    }
    
    void bfs(string s, int bankSize, int pos, vector<string>& bank, string& end)
    {
        int cnt = 1;
        queue<pair<string, int>> q;
        int visited[10] = {0, };
        visited[pos] = 1;
        bool flag = false;
        
        q.push({s, pos});
        while (!q.empty())
        {
            s = q.front().first;
            pos = q.front().second;
            
            if (s == end)
                break;
            
            q.pop();
            for (int i=0; i<bankSize; i++)
            {
                if (!visited[i] && check(s, bank[i]))
                {
                    q.push({bank[i], i});
                    visited[i] = visited[pos] + 1;
                } 
            }
        }
        
        for (int i=0; i<bank.size(); i++)
        {
            if (bank[i] == end)
            {
                answer = min(answer, visited[i]);       
                flag = true;
            }
        }
        
        if (answer == 0 || !flag)
            answer = -1;
        
        
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        // start와 bank의 원소와 차이가 1나면 bfs실시
        for (int i=0; i<bank.size(); i++)
        {
            if (check(start, bank[i]))
            {
                bfs(bank[i], bank.size(),i, bank, end);
                
            }
                
        }
        
        if (bank.size() == 0)
            answer = -1;
        
        return answer;
    }
};