//https://leetcode.com/problems/arranging-coins/

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
