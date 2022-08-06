//https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/

//Basic Heaps
class Solution {
public:
    int fillCups(vector<int>& amount) {
        int i=0;
        priority_queue<int> pq;
        for (auto i:amount)
            pq.push(i);
        int a,b;
        while (pq.top()!=0)
        {
            a=pq.top();
            pq.pop();
            b=pq.top();
            pq.pop();
            a--;
            b--;
            i++;
            pq.push(a);
            pq.push(b);
        }
        return i;
    }
};