class Solution {
public:
    bool isPalindrome(int x) {
        
        string a = to_string(x);
        
        for (int i = 0; i < a.size(); i++)
            if (a[i] != a[a.size() - i - 1])
                return false;
        
        return true;
    }
};