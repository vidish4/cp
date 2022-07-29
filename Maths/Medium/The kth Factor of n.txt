You are given two positive integers n and k. A factor of an integer n is defined as an integer i where n % i == 0.

Consider a list of all factors of n sorted in ascending order, return the kth factor in this list or return -1 if n has less than k factors.

 

Example 1:

Input: n = 12, k = 3
Output: 3
Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.
Example 2:

Input: n = 7, k = 2
Output: 7
Explanation: Factors list is [1, 7], the 2nd factor is 7.
Example 3:

Input: n = 4, k = 4
Output: -1
Explanation: Factors list is [1, 2, 4], there is only 3 factors. We should return -1.
 

Constraints:

1 <= k <= n <= 1000
 

Follow up:

Could you solve this problem in less than O(n) complexity?

Using loop O(n)
class Solution {
public:
    int kthFactor(int n, int k) {
        int l=1;
        if (k==1)
            return 1;
        for (int i=2;i<=n;i++)
            if (n%i==0)
            {
                l++;
                if (l==k)
                    return i;
            }
        return -1;
    }
};

O(sqrt(n)): Use i*i<=n to store half factors and normal loop to store the other half
class Solution {
public:
    int kthFactor(int n, int k) {
        vector <int> v;
        v.push_back(1);
        for (int i=2;i*i<=n;i++)
            if (n%i==0)
                v.push_back(i);
        for (int i=v.size()-1;i>=0;i--)
            if (v[i]!=n/v[i])
                v.push_back(n/v[i]);
        if (k>v.size())
            return -1;
        return v[k-1];
    }
};