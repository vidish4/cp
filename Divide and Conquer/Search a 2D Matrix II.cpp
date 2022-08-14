//https://leetcode.com/problems/search-a-2d-matrix-ii/

//O(nlogn): Trivial
class Solution {
public:
    bool searchrow(vector<vector<int>>& matrix,int target)
    {
        bool k;
        for (int i=0;i<matrix.size();i++)
        {
            if (matrix[i][0]<=target && matrix[i][matrix[i].size()-1]>=target)
                k=searchcol(matrix[i],target);
            if (k==true)
                return k;
            if (matrix[i][0]>target)
                return false;
        }
        return false;
    }
    bool searchcol(vector<int>& row,int target)
    {
        int i=0,j=row.size()-1,m;
        while (i<=j)
        {
            m=i-(i-j)/2;
            if (row[m]==target)
                return true;
            else if (row[m]>target)
                j=m-1;
            else
                i=m+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchrow(matrix,target);
    }
};

//O((logn)^2): 2 Binary Search
class Solution {
public:
    bool searchrow(vector<vector<int>>& matrix,int target,int i,int j)
    {
        int m;
        bool k=false;
        while (i<=j)
        {
            m=i-(i-j)/2;
            // if (m<0 || m>=matrix[0].size())
            //     return false;
            if (matrix[m][0]==target)
                return true;
            if (matrix[m][0]<=target && matrix[m][matrix[m].size()-1]>=target)
                k=searchcol(matrix[m],target);
            if (k==true)
                return true;
            else
            {
                if (m-1<0)
                    return searchrow(matrix,target,m+1,j);
                else if(m+1>=matrix.size())
                    return searchrow(matrix,target,i,m-1);
                else
                    return searchrow(matrix,target,m+1,j) || searchrow(matrix,target,i,m-1);
            }
        }
        return false;
    }
    bool searchcol(vector<int>& row,int target)
    {
        int i=0,j=row.size()-1,m;
        while (i<=j)
        {
            m=i-(i-j)/2;
            if (row[m]==target)
                return true;
            else if (row[m]>target)
                j=m-1;
            else
                i=m+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchrow(matrix,target,0,matrix.size()-1);
    }
};

//Why is this better? Probably because it is O(m+n)?
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m=matrix.size(); int n=matrix[0].size();
        int r=0;int c=n-1;
        while(r<m && c>=0)
        {
            if(target==matrix[r][c])
                return true;
           else if(target<matrix[r][c])
                c--;
            else
                r++;
        }
        return false;
    }
};