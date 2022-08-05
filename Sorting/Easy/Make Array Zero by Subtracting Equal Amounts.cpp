//https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amou

//Using Sorting
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,cnt=0;
        if (nums.size()==1 && nums[0]!=0)
            return 1;
        if (nums.size()==1 && nums[0]==0)
            return cnt;
        if (nums[0]!=0)
        {
            int l=nums[0];
            for (int j=0;j<nums.size();j++)
                {
                    nums[j]=nums[j]-l;
                }
                cnt++;
        }
        while (nums[i]==0)
        {
            i++;
            if (nums[i]!=0)
            {
                int l=nums[i];
                for (int j=i;j<nums.size();j++)
                {
                    nums[j]=nums[j]-l;
                }
                cnt++;
            }
            if (i==nums.size()-1)
                break;
        }
        return cnt;
    }
};