Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

 

Example 1:

Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
Example 2:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 3:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= num <= 3999

O(1): Using chronology
class Solution {
public:
    string intToRoman(int num) {
        string s;
        int i;
        if (num>=1000)
        {
            i=num/1000;
            num=num-i*1000;
            //cout<<num;
            while (i--)
                s.push_back('M');
        }
        //return s;
        i=0;
        if (num>=500)
        {
            if (num/100==9)
            {
                s.push_back('C');
                s.push_back('M');
                num=num-900;
            }
            else
            {
                i=num/500;
                num=num-i*500;
                s.push_back('D');
            }
        }
        //return s;
        i=0;
        if (num>=100)
        {
            if (num/100==4)
            {
                s.push_back('C');
                s.push_back('D');
                num=num-400;
            }
            else
            {
                i=num/100;
                num=num-i*100;
                while (i--)
                    s.push_back('C');
            }
        }
        i=0;
        if (num>=50)
        {
            if (num/10==9)
            {
                s.push_back('X');
                s.push_back('C');
                num=num-90;
            }
            else
            {
                i=num/50;
                num=num-i*50;
                while (i--)
                    s.push_back('L');
            }
        }
        i=0;
        if (num>=10)
        {
            if (num/10==4)
            {
                s.push_back('X');
                s.push_back('L');
                num=num-40;
            }
            else
            {
                i=num/10;
                num=num-i*10;
                while (i--)
                    s.push_back('X');
            }
        }
        i=0;
        if (num>=5)
        {
            if (num==9)
            {
                s.push_back('I');
                s.push_back('X');
                num=num-9;
            }
            else
            {
                i=num/5;
                num=num-i*5;
                s.push_back('V');
            }
        }
        i=0;
        if (num>0)
        {
            if (num==4)
            {
                s.push_back('I');
                s.push_back('V');
                num=num-4;
            }
            else
            {
                i=num;
                num=num-i;
                while (i--)
                    s.push_back('I');
            }
        }
        return s;
    }
};