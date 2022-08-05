//https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

//Use Priority Queue of Pair.
//It will queue according to first integer of pair and if they are same then second.
//Since we are using min heap, it will arrange smallest above
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        for (int i=0;i<mat.size();i++)
        {
            int i1=0,j1=mat[i].size()-1,m;
            while (i1<=j1)
            {
                m=i1-(i1-j1)/2;
                if (mat[i][m]==1)
                {
                    i1=m+1;
                }
                else if (mat[i][m]==0)
                {
                    j1=m-1;
                }
            }
            pair<int,int> p;
            p.second=i;
            if (mat[i][m]==1)
                p.first=m+1;
            else if (mat[i][m]==0)
                p.first=m;
            pq.push(p);
        }
        vector<int> ans(k,-1);
        for (int i=0;i<k;i++)
        {
            ans[i]=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};