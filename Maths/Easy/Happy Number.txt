Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false
 

Constraints:

1 <= n <= 231 - 1

Sum of squares will either converge to 1 or 4
class Solution {
public:
    bool isHappy(int n) {
        if (n==1)
            return true;
        long long d,next=0;
        while (n>=4)
        {
            while (n>=1)
            {
                d=n%10;
                d=d*d;
                n=n/10;
                next=next+d;
            }
            n=next;
            if (n==1)
                return true;
            next=0;
            if (n==4)
                return false;
        }
        return false;
    }
};

Floyd's Cycle detection algorithm
