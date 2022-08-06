//https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

//Use one priority_queue p for arranging according to num[i] and other priority_queue q for arranging according to index i
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue< pair<int,int> > p;
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
        pair<int,int> r;
        for (int i=0;i<nums.size();i++)
        {
            r.first=nums[i];
            r.second=i;
            p.push(r);
        }
        vector<int> v;
        pair<int,int> s;
        pair<int,int> t;
        for (int i=0;i<k;i++)
        {
            t=p.top();
            s.first=t.second;
            s.second=t.first;
            q.push(s);
            p.pop();
        }
        for (int i=0;i<k;i++)
        {
            v.push_back(q.top().second);
            q.pop();
        }
        return v;
    }
};