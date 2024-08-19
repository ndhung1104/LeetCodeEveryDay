class Solution {
public:
    int minSteps(int n) {
        int count = 0, size = n + 1;
        if (n == 1)
            return 0;
        int *primeArray = new int[size]{0};
        for (int i = 2; i < size; i++)
            while (n % i == 0 && n > 1)
            {
                n = n / i;
                primeArray[i]++;
            }
        for (int i = 2; i < size; i++)
            count += i * primeArray[i];
        
        delete [] primeArray;
        
        return count;

    }
};