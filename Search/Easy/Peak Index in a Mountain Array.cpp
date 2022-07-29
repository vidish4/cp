Let's call an array arr a mountain if the following properties hold:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]
Given an integer array arr that is guaranteed to be a mountain, return any i such that arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

 

Example 1:

Input: arr = [0,1,0]
Output: 1
Example 2:

Input: arr = [0,2,1,0]
Output: 1
Example 3:

Input: arr = [0,10,5,2]
Output: 1
 

Constraints:

3 <= arr.length <= 104
0 <= arr[i] <= 106
arr is guaranteed to be a mountain array.
 

Follow up: Finding the O(n) is straightforward, could you find an O(log(n)) solution?

Linear (O(n))
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i=0;
        while (arr.at(i)<arr.at(i+1))
            i++;
        return i;
        
    }
};
Binary (O(logn))	//since 1st and last element arent gonna be in the answer anyways, just skip them. it wont give you out of range error
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i=1,j=arr.size()-2,m;
        while (i<=j)
        {
            m=(i+j)/2;
            if ((arr.at(m-1)<arr.at(m))&&(arr.at(m)<arr.at(m+1)))
                i=m+1;
            else if ((arr.at(m-1)>arr.at(m))&&(arr.at(m)>arr.at(m+1)))
                j=m-1;
            else
                return m;
        }
        return -1;
    }
};