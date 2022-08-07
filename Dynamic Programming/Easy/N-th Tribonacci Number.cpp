//https://leetcode.com/problems/n-th-tribonacci-number/


//Just like Fibo
class Solution {
public:
    int tribo (int n,vector<int> &dp)
    {
        if (n==0 || n==1)
            return n;
        if (n==2)
            return 1;
        if (dp[n]!=-1)
            return dp[n];
        dp[n]=tribo(n-1,dp) + tribo(n-2,dp) + tribo (n-3,dp);
        return dp[n];
    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return tribo(n,dp);
    }
};