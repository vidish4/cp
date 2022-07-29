Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.

 

Example 1:

Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 5000
0 <= nums[i] <= 5000

2-pointer: O(n^2)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for (int i=0;i<nums.size();i++)
        {
            for (int j=i+1;j<nums.size();j++)
            {
                if (nums[i]%2==1 && nums[j]%2==0)
                    swap(nums[i],nums[j]);
            }
        }
        return nums;
    }
};

O(n): make a new vector. go in old vector and search for even nos first then odd nos.
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> v;
        for (auto i:nums)
        {
            if (i%2==0)
                v.push_back(i);
        }
        for (auto i:nums)
        {
            if (i%2==1)
                v.push_back(i);
        }
        return v;
    }
};

O(n/2): take two pointers from edges to centre. 4 cases o-e,o-o,e-e,e-o and do as needed in every case
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        while (i<j)
        {
            if (nums[i]%2==1 && nums[j]%2==0)
            {
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            else if (nums[i]%2==0 && nums[j]%2==0)
                i++;
            else if (nums[i]%2==1 && nums[i]%2==1)
                j--;
            else
            {
                i++;
                j--;
            }
        }
        return nums;
    }
};