class Solution {
public:
    bool checkParenthese(char c1, char c2)
    {
        if (c1 == '(' && c2 == ')')
            return true;
        
        if (c1 == '{' && c2 == '}')
            return true;
        
        if (c1 == '[' && c2 == ']')
            return true;
        
        return false;
    }
    bool isValid(string s) {
        stack<char> cStack;
        int len = s.size();
        if (len % 2 == 1)
            return false;
        
        cStack.push(s[0]);

        for (int i = 1; i < len; i++)
        {
            if (cStack.size() == 0)
                cStack.push(s[i]);
            else if (checkParenthese(cStack.top(), s[i]))
                cStack.pop();
            else
                cStack.push(s[i]);
        }
            
        if (cStack.size() > 0)
            return false;
        
        return true;      
    }
};