//https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

//Just like normal bfs but only additional condition is that parent one
#include<bits/stdc++.h>
void bfs(int node,unordered_map <int, list<int> > &g, unordered_map<int,bool> &visited,unordered_map<int,int> &parent, string &s)
{
    queue<int> q;
    q.push(node);
    visited[node]=true;
    parent[node]=-1;
    
    while (!q.empty())
    {
        int temp=q.front();
        q.pop();
        
        for (auto i:g[temp])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i]=true;
                parent[i]=temp;
            }
            else if (visited[i]==true && parent[temp]!=i)       //Additional Condition  Ulta hoga cuz undirected graph hai. Parent of temp!=i
            {
                s="Yes";
                return;
            }
        }
    }
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    string s="No";
    
    //Adjacency List
    unordered_map <int, list<int> > g;
    for (int i=0;i<m;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    //bfs
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    for (int i=0;i<n;i++)
    {
        if (!visited[i])
            bfs(i,g,visited,parent,s);
    }
    return s;
}



//dfs also has the same logic
#include<bits/stdc++.h>
void dfs(int node, unordered_map <int, list<int> > &g, unordered_map<int,bool> &visited,int &parent, string &s)
{
    visited[node]=true;
    for (auto i:g[node])
    {
        
        if (!visited[i])
        {
            visited[i]=true;
            dfs(i,g,visited,node,s);
        }
        else if (visited[node] && i!=parent)        //Node ke next ka parent vo khud hi hona chahiye tha for acyclic
        {
            s="Yes";
            return;
        }
    }
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    string s="No";
    
    //Adjacency List
    unordered_map <int, list<int> > g;
    for (int i=0;i<m;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    //dfs
    unordered_map<int,bool> visited;
    for (int i=0;i<n;i++)
    {
        
        if (!visited[i])
        {
            int parent =-1;
            dfs(i,g,visited,parent,s);
        }
    }
    return s;
}