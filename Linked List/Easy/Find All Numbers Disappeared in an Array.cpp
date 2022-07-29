Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Example 2:

Input: nums = [1,1]
Output: [2]
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
 

Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Hashmaps Time: O(n) Space: O(n)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> ans;
        for (int i=0;i<nums.size();i++)
            m[nums[i]]++;
        for (int i=1;i<nums.size()+1;i++)
            if (m.count(i)==0)
                ans.push_back(i);
        return ans;
    }
};

Godly Solution: Say in ideal case, 1 to n are present in nums. In such case each element can be mapped to corresponding index. So if you map and make corresponding elements negative, the position of elements which remain positive will tell you which elements are absent.
Time: O(n) Space: O(1)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for (int i=0;i<nums.size();i++)
        {
            int temp=nums[i];
            if (temp<0)
                temp*=-1;
            if (nums[temp-1]>0)
                nums[temp-1]*=-1;
        }
        for (int i=0;i<nums.size();i++)
            if (nums[i]>0)
                ans.push_back(i+1);
        return ans;
    }
};