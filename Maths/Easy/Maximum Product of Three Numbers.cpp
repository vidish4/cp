Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

 

Example 1:

Input: nums = [1,2,3]
Output: 6
Example 2:

Input: nums = [1,2,3,4]
Output: 24
Example 3:

Input: nums = [-1,-2,-3]
Output: -6
 

Constraints:

3 <= nums.length <= 104
-1000 <= nums[i] <= 1000


PnC Cases
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort (nums.begin(),nums.end());
        int i=0;
        while (nums[i]<0)
        {
            i++;
            if (i==nums.size())
                break;
        }
        if (i==nums.size())
            return nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
        if ((i>=2 && i!=nums.size()))
        {
            if (nums[0]*nums[1]>nums[nums.size()-2]*nums[nums.size()-3])
                return nums[0]*nums[1]*nums[nums.size()-1];
            else 
                return nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
        }
        return nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
    }
};