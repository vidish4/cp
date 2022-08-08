//https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?leftPanelTab=0

//It's easy when base case and dynamic function is handled properly
int func(vector<int> &dp,int n)
{
    if (n==0 || n==1)
        return 1;
    if (dp[n]!=-1)
        return dp[n];
    dp[n]=func(dp,n-1)%1000000007+func(dp,n-2)%1000000007;
    return dp[n]%1000000007;
}
int countDistinctWays(int n) {
    vector<int> dp(n+1,-1);
    return func(dp,n)%1000000007;
}