//https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

//Sorting
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        return (nums[0]-1)*(nums[1]-1);
    }
};

//Can also use Heaps/Priority Queue
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        for (int i=0;i<nums.size();i++)
            pq.push(nums[i]);
        int a=pq.top()-1;
        pq.pop();
        a=a*(pq.top()-1);
        return a;
    }
};