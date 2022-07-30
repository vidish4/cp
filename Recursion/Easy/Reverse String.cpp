https://leetcode.com/problems/reverse-string/

//Using Loops
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0,j=s.size()-1;
        while (i<=j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
};

//Using Recursion
class Solution {
public:
    void rev(vector<char>& s,int i,int j)
    {
        if (i<=j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
            rev(s,i,j);
        }
        return;
    }
    void reverseString(vector<char>& s) {
        rev(s,0,s.size()-1);
    }
};