class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        bool remember = true;
        for (int i = size - 1; i >= 0; i--)
        {
            if (digits[i] == 9)
                digits[i] = 0;
            else
            {
                remember = false;
                digits[i]++;
                break;
            }
        }

        if (remember)
            digits.insert(digits.begin(), 1);
        
        return digits;
    }
};