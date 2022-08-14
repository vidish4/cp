//https://leetcode.com/problems/reverse-pairs/
//This is also my second Hard Problem
//Diving and Conquer babyyy
class Solution {
public:
    void merge(vector<int>& nums,int l,int m,int r,int &count)
    {
        vector<int> temp(r+1-l);        //Reduced memory cause memory limit exceeded
        int i=l,j=m+1,k=0;
        while (i<=m && j<=r)
        {
            if (nums[i]>2LL*nums[j])        //Typecasted cause int overflow
            {
                count=count+m+1-i;
                temp[k]=nums[j];
                j++;
                k++;
                //cout<<count;
            }
            else
            {
                temp[k]=nums[i];
                i++;
                k++;
            }
            
        }
        while (i<=m)
        {
            temp[k]=nums[i];
            i++;
            k++;
        }
        while (j<=r)
        {
            temp[k]=nums[j];
            j++;
            k++;
        }
        sort(temp.begin(),temp.end());
        for (int p=l;p<=r;p++)
        {
            nums[p]=temp[p-l];
        }
    }
    void mergesort(vector<int>& nums,int i,int j,int &count)
    {
        if (i<j)
        {
            int m=i-(i-j)/2;
            mergesort(nums,i,m,count);
            mergesort(nums,m+1,j,count);
            merge(nums,i,m,j,count);
        }
    }
    int reversePairs(vector<int>& nums) {
        int count=0;
        mergesort(nums,0,nums.size()-1,count);
        // for (int i=0;i<nums.size();i++)
        //     cout<<nums[i]<<" ";
        return count;
    }
};