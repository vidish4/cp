Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

O(2*logn): Used 1 BS to shortlist row then other to shortlist column

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0,j=matrix.size()-1,m;
        while (i<=j)
        {
            m=(i+j)/2;
            if (matrix[m][0]<=target && matrix[m][matrix[m].size()-1]>=target)
                break;
            else if(matrix[m][0]>target)
                j=m-1;
            else if (matrix[m][matrix[m].size()-1]<target)
                i=m+1;
        }
        i=0,j=matrix[m].size()-1;
        int n;
        while (i<=j)
        {
            n=(i+j)/2;
            if (matrix[m][n]==target)
                return true;
            else if (matrix[m][n]>target)
                j=n-1;
            else
                i=n+1;
        }
        return false;
    }
};