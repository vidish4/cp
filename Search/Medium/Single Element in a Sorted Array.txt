You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105

Basic for loop (O(n))
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i,j=nums.size(),m=nums[0],count;
        for (int i=1;i<j-1;i++)
        {
            if ((nums[i-1]<nums[i])&&(nums[i]<nums[i+1]))
                m=nums[i];
            else if ((nums[i-1]!=nums[i])&&(i-1==0))
                m=nums[i-1];
            else if ((nums[i]!=nums[i+1])&&(i+1==nums.size()-1))
                m=nums[i+1];
        }
        return m;
    }
};
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i=0;
        while (i<nums.size()-1)
        {
            if (nums[i]!=nums[i+1])
                return nums[i];
            i=i+2;
        }
        return nums[nums.size()-1];
    }
};
Binary Search (O(logn)) using odd and even m property
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i=0,j=nums.size()-1,m;
        while (i<=j)
        {
            m=(i+j)/2;
            if ((0<m)&&(m<nums.size()-1))
            {
                if ((nums[m-1]<nums[m])&&(nums[m]<nums[m+1]))
                    return nums[m];
                else if(m%2==1)
                {
                    if (nums[m-1]==nums[m])
                        i=m+1;
                    else if (nums[m]==nums[m+1])
                        j=m-1;
                }
                else if (m%2==0)
                {
                    if (nums[m-1]==nums[m])
                        j=m-2;
                    else if (nums[m]==nums[m+1])
                        i=m+2;
                }
            }
            else
                return nums[m];
            
        }
        return -1;
    }
};