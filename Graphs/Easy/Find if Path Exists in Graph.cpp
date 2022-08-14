//https://leetcode.com/problems/find-if-path-exists-in-graph/

//dfs for source node and check if destination exists. Bad complexities
class Solution {
public:
    void dfs(int node, unordered_map<int, list<int> > &adj,unordered_map<int,bool> &visited,vector<int> &component)
    {
        if (!visited[node])
        {
            visited[node]=true;
            component.push_back(node);
            for (auto i:adj[node])
            {
                if (!visited[i])
                {
                    dfs(i,adj,visited,component);
                }
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (edges.size()==0 && source==destination)
            return true;
        //Adjacency List
        unordered_map<int, list<int> > adj;
        for (int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v= edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        unordered_map<int,bool> visited;
        vector<int> component;
        if (!visited[source])
        {
            dfs(source,adj,visited,component);     
        }
        for (int i=0;i<component.size();i++)
        {
            if(component[i]==destination)
            {
                return true;
            }
        }
        return false;   
    }
};