class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> parenthese_stack;

        for (int i = 0; i < s.size(); i++)
            if (parenthese_stack.size() > 0 && s[i] == ')' && parenthese_stack.top() == '(')
                parenthese_stack.pop();
            else
                parenthese_stack.push(s[i]);
        
        return parenthese_stack.size();
            
    }
};