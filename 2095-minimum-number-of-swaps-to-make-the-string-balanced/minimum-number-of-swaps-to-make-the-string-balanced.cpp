class Solution {
public:
    int minSwaps(string s) {
        int str_len = s.size();

        stack<char> bracket_stack;
        
        for (int i = 0; i < str_len; i++)
        {
            if (bracket_stack.size() > 0 && bracket_stack.top() == '[' && s[i] == ']')
                bracket_stack.pop();
            else
                bracket_stack.push(s[i]);
        }

        return ((bracket_stack.size()) / 2 + 1) / 2;
    }
};