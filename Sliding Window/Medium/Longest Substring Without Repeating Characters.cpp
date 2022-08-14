//https://leetcode.com/problems/longest-substring-without-repeating-characters/

//This will give Memory Limit Exceeded for last test case
class Solution {
public:
    int lengthOfLongestSubstring(string s,int i=0,int max=0) {
        if (i==s.size())
            return max;
        unordered_map<char,int> m;
        int j;
        for (j=i;j<s.size();j++)
        {
            if (m[s[j]]!=0)
                break;
            m[s[j]]++;
        }
        if (max<j-i)
            max=j-i;
        i++;
        return lengthOfLongestSubstring(s,i,max);
    }
};

//Bad Solution (You can improve the loops)
class Solution {
public:
    int lengthOfLongestSubstring(string s,int i=0,int max=0) {
        if (i==s.size())
            return max;
        unordered_map<char,int> m;
        int j;
        for (j=i;j<s.size();j++)
        {
            if (m[s[j]]!=0)
                break;
            m[s[j]]++;
        }
        if (max<j-i)
            max=j-i;
        i++;
        return lengthOfLongestSubstring(s,i,max);
    }
};