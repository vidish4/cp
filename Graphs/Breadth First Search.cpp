//https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
void bfs(int node,unordered_map<int, bool> &visited,vector<int> &v, unordered_map<int, set<int> > adj){
    queue<int> q;        //maintaining queue
    q.push(node);
    visited[node]=true;
    
    while (!q.empty())
    {
        int front=q.front();
        q.pop();
        
        //Storing front node in ans/v
        v.push_back(front);
        
        for (auto i:adj[front])     //Putting all neighbors of front node in q
        {
            if (!visited[i])
            {
                visited[i]=true;
                q.push(i);
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    //Making Adjacency List
    unordered_map<int, set<int> > adj;
    for (int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        
        adj[u].insert(v);
        adj[v].insert(u);
    }
    
    //Implementing bfs
    vector<int> v;        //Store in bfs
    unordered_map<int, bool> visited;
    for (int i=0;i<vertex;i++)
    {
        if (!visited[i])
        {
            bfs(i,visited,v,adj);
        }
    }
    return v;
}

//bfs is slightly better
class Solution {
public:
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
        queue<int> q;
        q.push(source);
        visited[source]=true;
        while (!q.empty())
        {
            int front =q.front();
            if (front==destination)
                return true;
            q.pop();
            for (auto i:adj[front])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
        return false;
    }
};