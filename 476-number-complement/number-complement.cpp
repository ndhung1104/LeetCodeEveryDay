class Solution {
public:
    int findComplement(int num) {
        long long factor2 = 1, temp = num;
        while (temp > 0)
        {
            factor2 *= 2;
            temp = temp / 2;
        }
        return int(factor2 - num - 1);
    }
};