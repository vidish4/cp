//https://www.codingninjas.com/codestudio/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

//dfs
//Used vector<bool> visited instead of unordered_map<int,bool> visited so as to save some time
#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
#include<stack>
void dfs(int node,stack<int> &s,vector<bool> &visited, unordered_map<int, list<int>> &g)
{
    visited[node]=1;
    
    for(auto i:g[node])
    {
        if (!visited[i])
        {
            dfs(i,s,visited,g);
        }
    }
    s.push(node);
    return;
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> ans;
    //Adjacency List
    unordered_map<int,list<int>> g;
    for (auto i:edges)
    {
        int u=i[0];
        int v=i[1];
        
        g[u].push_back(v);
    }
    
    //dfs
    vector<bool> visited(v,0);
    stack<int> s;
    for (int i=0;i<v;i++)
    {
        if (!visited[i])
        {
            dfs(i,s,visited,g);
        }
    }
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}


//Kahn's Algorithm (Topological + BFS)
#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
#include<queue>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> ans;
    //Adjacency List
    unordered_map<int,list<int>> g;
    for (auto i:edges)
    {
        int u=i[0];
        int v=i[1];
        
        g[u].push_back(v);
    }
    
    //find indegrees
    vector<int> indegree(v,0);
    for (auto i:g)
    {
        for (auto j:i.second)
        {
            indegree[j]++;
        }
    }
    
    //push 0 indegree in queue      //Since we push all starting nodes of different components of graph in queue. So no need of for loop 
    queue<int> q;
    for (int i=0;i<v;i++)
    {
        if (indegree[i]== 0)
            q.push(i);
    }
    
    //bfs
    while (!q.empty())
    {
        int temp=q.front();
        q.pop();
        ans.push_back(temp);
        
        for (auto i:g[temp])
        {
            indegree[i]--;
            if (indegree[i]==0)
                q.push(i);
        }
    }
    return ans;
}