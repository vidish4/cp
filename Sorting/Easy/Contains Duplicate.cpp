Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109

Sorting + linear loop O(nlogn+n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for (int i=1;i<nums.size();i++)
            if (nums[i-1]==nums[i])
                return true;
        return false;
    }
};

Hashmaps O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for (int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
            if (m[nums[i]]==2)
                return true;
        }
        return false;
    }
};