//https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    void dfs(int node, unordered_map<int, list<int> > &adj, vector<int> &components, vector<vector<int>> &ans,int n)
    {
        components.push_back(node);
        if (node==n-1)
        {
            ans.push_back(components);
            components.pop_back();
            return;
        }
        for (auto i:adj[node])
        {
            dfs(i,adj,components,ans,n);
        }
        components.pop_back();
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        
        //Adjacency List
        unordered_map<int, list<int> > adj;
        int n=g.size();
        for (int i=0;i<g.size();i++)
        {
            for (int j=0;j<g[i].size();j++)
            {
                adj[i].push_back(g[i][j]);
            }
        }
        
        vector<vector<int>> ans;
        //dfs
        vector<int> components;
        dfs(0,adj,components,ans,n);
        return ans;
    }
};