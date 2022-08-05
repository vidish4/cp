//https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/

//Heaps for Odd and Even numbers
class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> odd,even;
        string s;
        while (num>0)
        {
            if ((num%10)%2==1)
            {
                odd.push(num%10);
                num/=10;
                s.push_back('1');
            }
            else
            {
                even.push(num%10);
                num/=10;
                s.push_back('0');
            }
        }
        reverse(s.begin(),s.end());
        int largest=0;
        for (auto i:s)
        {
            if (i=='0')
            {
                largest=10*largest+even.top();
                even.pop();
            }
            else if (i=='1')
            {
                largest=10*largest+odd.top();
                odd.pop();
            }
        }
        return largest;
    }
};