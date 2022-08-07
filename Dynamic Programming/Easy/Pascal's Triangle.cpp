//https://leetcode.com/problems/pascals-triangle/

//In this case, the dp array is also the answer
//Line 36 is what makes it dp
class Solution {
public:
    void func(vector<vector<int>> &ans,int n)
    {
        vector<int> v;
        if (n==1)
        {
            v.push_back(1);
            ans.push_back(v);
            v.clear();
            return;
        }
        if (n==2)
        {
            n=n-1;
            func(ans,n);
            v.push_back(1);
            v.push_back(1);
            ans.push_back(v);
            v.clear();
            return;
        }
        if (n>2)
        {
            n--;
            func(ans,n);
        }
        v.push_back(1);
        int i=0,j=1;
        while (j<ans[ans.size()-1].size())
        {
            v.push_back(ans[ans.size()-1][i]+ans[ans.size()-1][j]);
            i++;
            j++;
        }
        v.push_back(1);
        ans.push_back(v);
        return;
    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        func(ans,n);
        return ans;
    }
};