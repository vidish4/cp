//https://leetcode.com/problems/find-the-town-judge/

//You don't have to implement graph entirely. Just abstraction is enough.
//Use a counter which keeps track of number of occurences of each node.
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> counter(n+1,0);
        for (auto i:trust)
        {
            counter[i[0]]--;
            counter[i[1]]++;
        }
        for (int i=1;i<=n;i++)
        {
            if (counter[i]==n-1)
                return i;
        }
        return -1;
    }
};