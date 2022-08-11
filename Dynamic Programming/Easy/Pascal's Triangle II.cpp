//https://leetcode.com/problems/pascals-triangle-ii/

//Space Optimization O(RowIndex)
class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> prev{1};
        vector<int> curr{1,1};
        if (n==0)
            return prev;
        if (n==1)
            return curr;
        for (int k=2;k<=n;k++)
        {
            prev=curr;
            curr.clear();
            int j=1;
            curr.push_back(1);
            while (j<prev.size())
            {
                curr.push_back(prev[j-1]+prev[j]);
                j++;
            }
            curr.push_back(1);
        }
        return curr;
    }
};