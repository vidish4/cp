Given an array of integers nums, half of the integers in nums are odd, and the other half are even.

Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.

Return any answer array that satisfies this condition.

 

Example 1:

Input: nums = [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
Example 2:

Input: nums = [2,3]
Output: [2,3]
 

Constraints:

2 <= nums.length <= 2 * 104
nums.length is even.
Half of the integers in nums are even.
0 <= nums[i] <= 1000
 

Follow Up: Could you solve it in-place?

O(n^2)..kinda? (in place): Use 3 pointers, i, jo=index even num odd and je=index odd num even
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i=0,jo=1,je=1;
        while (!(nums[jo]%2==1 && jo%2==0))
        {
            jo++;
            if (jo>=nums.size())
                        break;
        }
        while (!(nums[je]%2==0 && je%2==1))
        {
            je++;
            if (je>=nums.size())
                break;
        }
        cout<<jo<<" "<<je;
        if (nums[i]%2==1 && i%2==0)
        {
            swap(nums[i],nums[je]);
            while (!(nums[je]%2==0 && je%2==1))
            {
                je++;
                if (je>=nums.size())
                    break;
            }
        }
        else if (nums[i]%2==0 && i%2==1)
        {
            swap(nums[i],nums[jo]);
            while (!(nums[jo]%2==1 && jo%2==0))
            {
                jo++;
                if (jo>=nums.size())
                    break;
            }
        }
        while (i<nums.size())
        {
            if (i>=nums.size() || jo>=nums.size() || je>=nums.size())
                break;
            else if (nums[i]%2==i%2)
                i++;
            else if ((nums[jo]%2==1 && jo%2==0))
            {
                swap(nums[i],nums[je]);
                while (!(nums[jo]%2==1 && jo%2==0))
                {
                    jo++;
                    if (jo>=nums.size())
                        break;
                }
                while (!(nums[je]%2==0 && je%2==1))
                {
                    je++;
                    if (je>=nums.size())
                        break;
                }
                i++;
            }
            else if ((nums[je]%2==0 && je%2==1))
            {
                swap(nums[jo],nums[i]);
                while (!(nums[je]%2==0 && je%2==1))
                {
                    je++;
                    if (je>=nums.size())
                        break;
                }
                while (!(nums[jo]%2==1 && jo%2==0))
                {
                    jo++;
                    if (jo>=nums.size())
                        break;
                }
                i++;
            }
        }
        return nums;
    }
};

O(n): Making new vector. Saves time takes memory
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i,j=0;
        vector<int> arr(nums.size(),-1);
        for (i=0;i<nums.size();i++)
        {
            if ((nums[i]%2==0))
            {
                arr[j]=nums[i];
                j=j+2;
            }
        }
        j=1;
        for (i=0;i<nums.size();i++)
        {
            if ((nums[i]%2==1))
            {
                arr[j]=nums[i];
                j=j+2;
            }
        }
        return arr;
    }
};