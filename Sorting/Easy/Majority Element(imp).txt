Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
 

Follow-up: Could you solve the problem in linear time and in O(1) space?

Moore's voting algo O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,key;
        for (int i=0;i<nums.size();i++)
        {
            if (count==0)
                key=nums[i];
            if (nums[i]==key)
                count++;
            else
                count--;
        }
        return key;
    }
};

Hashmaps O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        for (int i=0;i<nums.size();i++)
            m[nums[i]]++;
        int maxfreq=0,max=0;
        for (auto i:m)
        {
            if (maxfreq<i.second)
            {
                maxfreq=i.second;
                max=i.first;
            }
        }
        return max;
    }
};

Sorting + loop to find majority (O(nlogn + n))
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort (nums.begin(),nums.end());
        int count=0;
        for (int i=0;i<nums.size()-1;i++)
        {
            count++;
            if (nums[i+1]!=nums[i])
                count=0;
            if (count>=nums.size()/2)
                return nums[i]; 
        }
        if (nums.size()==1)
            return nums[0];
        return -1;
    }
};