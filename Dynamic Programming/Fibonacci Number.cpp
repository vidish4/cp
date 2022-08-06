//https://leetcode.com/problems/fibonacci-number/

//Top-Down Approach
class Solution {
public:
    int fibo(int n, vector<int> &dp)
    {
        if (n==0 || n==1)
            return n;
        if (dp[n]!=-1)
            return dp[n];
        dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
        return dp[n];
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return fibo(n,dp);
    }
};

//Bottom-Up Approach
class Solution {
public:
    int fibo(int n, vector<int> &dp)
    {
        dp[0]=0;
        if (n==0)
            return dp[n];
        dp[1]=1;
        for (int i=2;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return fibo(n,dp);
    }
};

//Space Optimization
class Solution {
public:
    int fib(int n) {
        int prev1=1,prev2=0,curr;
        if (n==0 || n==1)
            return n;
        for (int i=2;i<=n;i++)
        {
            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
};