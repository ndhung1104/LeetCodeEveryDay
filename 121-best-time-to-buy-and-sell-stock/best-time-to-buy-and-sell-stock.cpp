class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<int> maxArray(size, 0);
        vector<int> minArray(size, 0);
        minArray[0] = prices[0];
        maxArray[size - 1] = prices[size - 1];
        
        for (int i = 1; i < size; i++)
            if (prices[i] < minArray[i - 1])
                minArray[i] = prices[i];
            else
                minArray[i] = minArray[i - 1];
        
        for (int i = size - 2; i > -1; i--)
            if (prices[i] > maxArray[i + 1])
                maxArray[i] = prices[i];
            else
                maxArray[i] = maxArray[i + 1];
        
        int max = 0;
        for (int i = 0; i < size; i++)
            if (max < maxArray[i] - minArray[i])
                max = maxArray[i] - minArray[i];
        
        return max;
    }
};