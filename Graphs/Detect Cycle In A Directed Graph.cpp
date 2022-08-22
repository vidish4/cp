//https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

//dfs 
#include<bits/stdc++.h>
void dfs(int &flag,int node,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsvisited,unordered_map<int, list<int> > &g)
{
    visited[node]=true;
    dfsvisited[node]=true;
    for (auto i: g[node])
    {
        if (!visited[i])
        {
            dfs(flag,i,visited,dfsvisited,g);
        }
        else if (visited[i] && dfsvisited[i])
        {
            flag=1;
            return;
        }
    }
    dfsvisited[node]=false;
    return;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    int flag=0;
    //Adjacency List
    unordered_map<int, list<int> > g;
    for (auto i:edges)
    {
        int u=i.first;
        int v=i.second;
        
        g[u].push_back(v);
    }
    
    //dfs
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsvisited;
    for (int i=0;i<n;i++)
    {
        if (!visited[i])
        {
            dfs(flag,i,visited,dfsvisited,g);
        }
    }
    return flag;
}

//bfs using Topological Sort
#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    
    //Adjacency List
    unordered_map<int, list<int> > g;
    for (auto i:edges)
    {
        int u=i.first-1;
        int v=i.second-1;
        
        g[u].push_back(v);
    }
    
    //Indegree
    vector<int> indegree(n,0);
    for (auto i:g)
    {
        for (auto j:i.second)
        {
            indegree[j]++;
        }
    }
    
    //putting all nodes with indegree==0 in queue
    queue<int> q;
    for (int i=0;i<n;i++)
    {
        if (indegree[i]==0)
            q.push(i);
    }
    
    //bfs
    int count=0;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        count++;
        
        for (auto i:g[temp])
        {
            indegree[i]--;
            if (indegree[i]==0)
                q.push(i);
        }
    }
    if (count!=n)       //Valid Topological Sort is when count==n
    {
        return true;
    }
    return false;
}