//https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

//bfs
#include<iostream>
#include<queue>
#include<list>
#include<vector>
#include<unordered_map>
void bfs(int node, unordered_map<int,list<int>> &g, unordered_map<int,bool> &visited, unordered_map<int,int> &parent)
{
    queue<int> q;
    visited[node]=true;
    q.push(node);
    parent[node]=-1;
    while (!q.empty())
    {
        int temp=q.front();
        q.pop();
        for (auto i:g[temp])
        {
            if (!visited[i])
            {
                parent[i]=temp;
                visited[i]=true;
                q.push(i);
            }
        }
    }
}
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	unordered_map<int,list<int>> g;
    //Adjacency List
    for (auto i:edges)
    {
        int u=i.first;
        int v=i.second;
        
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    //bfs
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    bfs(s,g,visited,parent);
    
    //Go from t -> s in parent
    vector<int> ans;
    int curr=t;
    while (curr!=-1)
    {
        ans.push_back(curr);
        curr=parent[curr];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}