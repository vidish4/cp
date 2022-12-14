//https://leetcode.com/problems/climbing-stairs/

//Tabulation
class Solution {
public:
    int solve(vector<int> &dp,int n)
    {
        dp[1]=1;
        if (n==1)
            return dp[n];
        dp[2]=2;
        for (int i=3;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(dp,n);
    }
};