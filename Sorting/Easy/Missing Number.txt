Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
 

Constraints:

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.
 

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?

Math O(n)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        for (int i=0;i<nums.size();i++)
            sum=sum+nums[i];
        return ((nums.size()*(nums.size()+1)/2)-sum);
    }
};

loop + loop O(n^2) (too much runtime
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // sort(nums.begin(),nums,end());
        for (int i=0;i<nums.size()+1;i++)
        {
            int j=0;
            for (j=0;j<nums.size();j++)
            {
                if (nums[j]==i)
                    break;
            }
            if (j==nums.size())
                return i;
        }
        return -1;
    }
};

sort + linear saearch O(nlogn+n)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for (int i=0;i<nums.size();i++)
            if (nums[i]!=i)
                return i;
        return nums.size();
    }
};

sort + binary search O(nlogn+logn)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1,m,ans;
        while (i<=j)
        {
            m=(i+j)/2;
            if (nums[m]>m)
            {
                ans=m;
                j=m-1;
            }
            else if(nums[m]==m)
                i=m+1;
        }
        if (i>nums.size()-1)
            return nums.size();
        return ans;
        
    }
};

Hashmaps O(n)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        for (int i=0;i<nums.size();i++)
            m[nums[i]]++;
        for (int i=0;i<nums.size();i++)
            if (m[i]==0)
                return i;
        return nums.size();
    }
};