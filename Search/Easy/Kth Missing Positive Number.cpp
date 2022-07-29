Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

 

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
 

Constraints:

1 <= arr.length <= 1000
1 <= arr[i] <= 1000
1 <= k <= 1000
arr[i] < arr[j] for 1 <= i < j <= arr.length

Binary Search + loop (O(nlogn))
class Solution {
public:
    int BinarySearch (vector<int> arr, int i, int j, int x)
    {
        while (i<=j)
        {
            int m=(i+j)/2;
            if (arr.at(m)==x)
                return 1;
            else if (arr.at(m)>x)
                j=m-1;
            else
                i=m+1;
        }
        return 0;
    }
    int findKthPositive(vector<int>& arr, int k) {
        int i=1,j=0;
        while (j<k)
        {
            if (!BinarySearch(arr,0,arr.size()-1,i))
            {
                j++;
                if (j==k)
                    break;
            }
            i++;
        }
        return i;
    }
};
