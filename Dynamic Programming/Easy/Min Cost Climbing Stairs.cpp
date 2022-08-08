//https://leetcode.com/problems/min-cost-climbing-stairs/

//Recursion + Memorization
class Solution {
public:
    int solve(vector<int>& cost,vector<int>& dp,int n)
    {
        if (n==0 || n==1)
            return cost[n];
        if (dp[n]!=-1)
            return dp[n];
        if (n<cost.size())
            dp[n]=dp[n]+cost[n];
        dp[n]=min(solve(cost,dp,n-1),solve(cost,dp,n-2));
        if (n<cost.size())
            dp[n]=dp[n]+cost[n];
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        return solve(cost,dp,cost.size());
    }
};

//Slightly more optimized than above. Since here we don't have to add cost in the last part, only min is returned.
class Solution {
public:
    int solve(vector<int>& cost,vector<int>& dp,int n)
    {
        if (n==0 || n==1)
            return cost[n];
        if (dp[n]!=-1)
            return dp[n];
        if (n<cost.size())
            dp[n]=dp[n]+cost[n];
        dp[n]=cost[n]+min(solve(cost,dp,n-1),solve(cost,dp,n-2));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        return min(solve(cost,dp,cost.size()-1),solve(cost,dp,cost.size()-2));
    }
};

//