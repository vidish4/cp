//https://leetcode.com/problems/counting-bits/

//O(nlogn)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0]=0;
        if (n==0)
            return ans;
        ans[1]=1;
        if (n==1)
            return ans;
        ans[2]=1;
        if (n==2)
            return ans;
        for (int i=3;i<=n;i++)
        {
            int d=0,num=i;
            while (num>0)
            {
                d=d+num%2;
                num/=2;
                
            }
            ans[i]=d;
        }
        return ans;
    }
};

//Tabulation O(n): Relation on Line 46 is important for this method. In Dynamic Programming you need to beable to find out such relations.
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0]=0;
        if (n==0)
            return ans;
        ans[1]=1;
        int x=1;
        for (int i=2;i<=n;i++)
        {
            if (!(i&(i-1)))
                x=i;
            ans[i]=1+ans[i-x];
        }
        return ans;
    }
};class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0]=0;
        if (n==0)
            return ans;
        ans[1]=1;
        int x=1;
        for (int i=2;i<=n;i++)
        {
            if (!(i&(i-1)))
                x=i;
            ans[i]=1+ans[i-x];
        }
        return ans;
    }
};