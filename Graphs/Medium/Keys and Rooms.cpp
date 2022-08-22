//https://leetcode.com/problems/keys-and-rooms/

//bfs
class Solution {
public:
    void bfs(int node,vector<vector<int>>& rooms,unordered_map<int,bool> &visited)
    {
        queue<int> q;
        q.push(node);
        visited[node]=true;
        
        while (!q.empty())
        {
            int temp=q.front();
            q.pop();
            for (auto i:rooms[temp])
            {
                if (!visited[i])
                {
                    visited[i]=true;
                    q.push(i);
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        unordered_map<int,bool> visited;
        bfs(0,rooms,visited);
        for (int i=0;i<n;i++)
        {
            if (!visited[i])
                return false;
        }
        return true;
    }
};