class Solution {
public:
    vector<vector<int>> ans;
    vector<int> visited;
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // 11:41
        // backtracking
        dfs(graph, 0);
        
        return ans;
        
    }
    
    void dfs(vector<vector<int>> graph, int node)
    {
        visited.push_back(node);
        
        if (node == graph.size()-1)
            ans.push_back(visited);
        
        for (int i=0; i<graph[node].size(); i++)
            dfs(graph, graph[node][i]);
        
        // for backtracking
        visited.pop_back();  
    }
};