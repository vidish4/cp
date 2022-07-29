Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnNumber = 1
Output: "A"
Example 2:

Input: columnNumber = 28
Output: "AB"
Example 3:

Input: columnNumber = 701
Output: "ZY"
 

Constraints:

1 <= columnNumber <= 231 - 1

While loop carry method: write n as a polynomial in 26 as x
class Solution {
public:
    string convertToTitle(int n) {
        string s;
        n--;
        int b;
        while (n>=0)
        {
            b=n%26;
            s.push_back(b+65);
            n=n/26;
            n--;
        }
        int i=0,j=s.size()-1;
        while (i<j)
        {
            int t=s[i];
            s[i]=s[j];
            s[j]=t;
            i++;
            j--;
        }
        return s;
    }
};