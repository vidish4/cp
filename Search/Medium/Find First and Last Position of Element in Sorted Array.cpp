Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

Binary (O(2logn)) since you need to find 2 numbers, do 2 searches
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1,m,i1=-1,j1=-1;
        while (i<=j)
        {
            m=(i+j)/2;
            if (nums[m]==target)
            {
                i1=m;
                i=0;
                j=m-1;
            }
            else if (nums[m]>target)
                j=m-1;
            else
                i=m+1;
        }
        i=0;
        j=nums.size()-1;
        while (i<=j)
        {
            m=(i+j)/2;
            if (nums[m]==target)
            {
                j1=m;
                i=m+1;
                j=nums.size()-1;
            }
            else if (nums[m]>target)
                j=m-1;
            else
                i=m+1;
        }
        vector<int> ans{i1,j1};
        return ans;
    }
};