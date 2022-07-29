Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

 

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100
 

Follow up: Could you find an O(n + m) solution?

Brute force:
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        for (int i=0;i<grid.size();i++)
        {
            for (int j=0;j<grid[i].size();j++)
            {
                if ((grid[i][j])<0)
                    count++;
            }
        }
        return count;
    }
};
Binary Search + loop O(nlogm)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int j,count=0,m,i1;
        for (int i=0;i<grid.size();i++)
        {
            if (grid[i][grid[i].size()-1]<0)
            {
                i1=0;
                j=grid[i].size()-1;
                while (i1<=j)
                {
                    m=(i1+j)/2;
                    if (grid[i][m]>0)
                        i1=m+1;
                    else if (grid[i][m]<0)
                        j=m-1;
                    else
                        break;
                }
                if (grid[i][m]>=0)
                {
                    while (grid[i][m]>=0)
                        m++;
                }
                
                count = count + grid[i].size()-m;
            }
        }
        return count;
    }
};
O(m+n): easy to understand, hard to click
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int i=0,j=grid[0].size()-1,count=0;
        while (i<grid.size()&&(j>=0))
        {
            if (grid[i][j]<0)
            {
                count += grid.size()-i;
                j--;
            }
            else
                i++;
        }
        return count;
    }
};