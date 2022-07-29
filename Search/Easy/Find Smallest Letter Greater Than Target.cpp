Given a characters array letters that is sorted in non-decreasing order and a character target, return the smallest character in the array that is larger than target.

Note that the letters wrap around.

For example, if target == 'z' and letters == ['a', 'b'], the answer is 'a'.
 

Example 1:

Input: letters = ["c","f","j"], target = "a"
Output: "c"
Example 2:

Input: letters = ["c","f","j"], target = "c"
Output: "f"
Example 3:

Input: letters = ["c","f","j"], target = "d"
Output: "f"
 

Constraints:

2 <= letters.length <= 104
letters[i] is a lowercase English letter.
letters is sorted in non-decreasing order.
letters contains at least two different characters.
target is a lowercase English letter.

Using Binary Search
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if ((target>=letters.at(letters.size()-1))||(target<letters.at((0))))
        {
            return letters.at(0);
        }
        else
        {
            int i=0,j=letters.size()-1,m,ans,k;
            while (i<=j)
            {
                m=(i+j)/2;
                
                if (letters.at(m)==target)
                {
                    ans =m;
                    break;
                    
                }
                else if (letters.at(m)>target)
                {
                    j=m-1;
                    ans=m;
                }
                else
                {
                    i=m+1;
                    ans=m;
                }
            }
            while (letters.at(ans)==letters.at((ans+1)%letters.size()))
            {
                ans++;
            }
            if (letters.at(ans)>target)
            {
                k=ans;
            }
            else
            {
               k=ans+1;
            }
            return letters.at(k);
        }
    }
};
OR using linear search
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (int i=0;i<letters.size();i++)
        {
            if(letters.at(i)>target)
            {
                return letters.at(i);
            }
        }
        return letters.at(0);
    }
};