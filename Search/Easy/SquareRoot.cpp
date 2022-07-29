Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.
Example 1:

Input: x = 4
Output: 2
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
 

Constraints:

0 <= x <= 2^31 - 1

cout<<"Enter x: ";
    int x;
    cin>>x;
    int i=1;
    while (i*i<=x)
    {
        i++;
    }
    cout<<i-1;
    return 0;
OR Using binary search:
long long i=1,j=x;
        long long k,l,m;
        while (i<=j)
        {
            m=(i+j)/2;
            k=m*m;
            l=(m+1)*(m+1);
            if ((k<=x)&&(x<l))
                {
                    return m;
                }
            else if (x<k)
                {
                    j=m-1;
                }
            else
                {
                    i=m+1;
                }
        }
        return m;