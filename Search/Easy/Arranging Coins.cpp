You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.

 

Example 1:


Input: n = 5
Output: 2
Explanation: Because the 3rd row is incomplete, we return 2.
Example 2:


Input: n = 8
Output: 3
Explanation: Because the 4th row is incomplete, we return 3.
 

Constraints:

1 <= n <= 231 - 1
class Solution {
public:
    int arrangeCoins(int n) {
        long long i=1;
        long long j=n;
        long long m;
        while (i<=j)
        {
            m=(i+j)/2;
            long long k=m*(m+1)/2;
            long long l=(m+1)*(m+2)/2;
            if ((l>n)&&(n>=k))
            {
                return m;
            }
            else if (k>n)
            {
                j=m-1;
            }
            else
            {
                i=m+1;
            }
        }
        return m;
    }
};