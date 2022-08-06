//https://leetcode.com/problems/relative-ranks/

//Using Heaps/Priority Queue
class Solution {
public:
    string its(int i)
    {
        string st;
        while (i>0)
        {
            st.push_back('0'+i%10);
            i/=10;
        }
        reverse(st.begin(),st.end());
        cout<<st;
        return st;
    }
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue< pair<int,int> > pq;
        for (int i=0;i<score.size();i++)
        {
            pair<int,int> p;
            p.first=score[i];
            p.second=i;
            pq.push(p);
        }
        vector<string> v(score.size(),"-1");
        string s;
        int i=1;
        while(!pq.empty())
        {
            //cout<<i;
            if (i==1)
            {
                s="Gold Medal";
            }
            if (i==2)
            {
                s="Silver Medal";
            }
            if (i==3)
            {
                s="Bronze Medal";
            }
            if (i>3)
            {
                s=its(i);
            }
            v[pq.top().second]=s;
            pq.pop();
            i++;
            s="";
        }
        return v;
    }
};