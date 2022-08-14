//https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

//Recursion
class Solution {
public:
    int numberOfSteps(int num,int steps=0) {
        if (num==0)
            return steps;
        if (num&1)
        {
            num--;
            steps++;
            return numberOfSteps(num,steps);
        }
        steps++;
        num = num >>1;
        return numberOfSteps(num,steps);
    }
};

