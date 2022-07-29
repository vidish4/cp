Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104

Binary search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1,m,ans;
        while (i<=j)
        {
            m=(i+j)/2;
            if (nums.at(m)==target)
                return m;
            else if (nums.at(m)>target)
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
        if(nums.at(ans)<target)
            return ans+1;
        return ans;
    }
};