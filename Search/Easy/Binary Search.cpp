//https://leetcode.com/problems/binary-search/
//Using Recursion
class Solution {
public:
    int bin(vector<int>& nums, int target,int i,int j)
    {
        if (i<=j)
        {
            int m=j-(j-i)/2;
            if (nums[m]==target)
                return m;
            else if (nums[m]>target)
            {
                m=bin(nums,target,i,m-1);
                return m;
            }
            else
            {
                m=bin(nums,target,m+1,j);
                return m;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return bin(nums,target,0,nums.size()-1);
    }
};

//Using Loops
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1,m;
        while (i<=j)
        {
            m=(i+j)/2;
            if (nums[m]==target)
                return m;
            else if (nums[m]>target)
                j=m-1;
            else
                i=m+1;
        }
        return -1;
    }
};