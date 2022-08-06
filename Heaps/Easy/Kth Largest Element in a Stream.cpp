//https://leetcode.com/problems/kth-largest-element-in-a-stream/

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

//Think in reverse
//Since we are just pushing numbers here we don't care about the numbers which get lost (think why)
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int> > pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        for (auto i:nums)
            pq.push(i);
        K=k;
    }
    
    int add(int val) {
        pq.push(val);
        int size=pq.size();
        for (int i=0;i<size-K;i++)
        {
            pq.pop();
        }
        return pq.top();
    }
};