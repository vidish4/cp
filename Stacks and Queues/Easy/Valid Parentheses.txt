Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

Stacks
class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		//char expected;
         for (char i:s)
         {
             if ( i=='(' || i=='{' || i=='[')
             {
                 st.push(i);
             }
             else 
             {
                 if (st.empty())
                     return false;
                 else if ( i==')' && st.top()=='(' )
                     st.pop();
                 else if ( i=='}' && st.top()=='{' )
                     st.pop();
                 else if ( i==']' && st.top()=='[' )
                     st.pop();
                 else
                     return false;
             }
         }
        return st.empty();
	}
};