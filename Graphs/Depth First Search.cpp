//https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

void dfs(int node, unordered_map<int, list<int> > &adj, unordered_map<int,bool> &visited, vector<int> &component)
{
    if (!visited[node])     //If node is already visited, we won't do anything
    {
        visited[node]=true;
        component.push_back(node);
        for (auto i:adj[node])
        {
            if (!visited[i])
            {
                dfs(i,adj,visited,component);   //dfs on those neighbors of node which aren't visited
            }
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    //Making Adjacency List
    unordered_map<int, list<int> > adj;
    for (int i=0;i<E;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    //Implementing dfs
    unordered_map<int,bool> visited;
    vector<vector<int>> ans;
    
    for (int i=0;i<V;i++)        //Since Disconnected
    {
        vector<int> component;  //We need component as we will try to go deep into one specific neighbor paths of i out of many such neighbor paths
        if (!visited[i])
        {
            dfs(i,adj,visited,component);
            ans.push_back(component);
        }
    }
    return ans;
}