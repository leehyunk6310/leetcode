class Solution {
public:
    vector<vector<int>> ans;
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // 11:41
        // backtracking
        vector<int> visited;
        
        dfs(graph, visited, 0);
        
        return ans;
        
    }
    
    void dfs(vector<vector<int>> graph, vector<int> visited, int node)
    {
        visited.push_back(node);
        
        if (node == graph.size()-1)
            ans.push_back(visited);
        
        for (int i=0; i<graph[node].size(); i++)
            dfs(graph, visited, graph[node][i]);
        
        
        
    }
};