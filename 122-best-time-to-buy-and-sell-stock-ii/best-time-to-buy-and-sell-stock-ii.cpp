class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size(), maxProfit = 0;
        for (int i = 0; i < size - 1; i++)
            if (prices[i + 1] > prices[i])
                maxProfit += prices[i + 1] - prices[i];
        
        return maxProfit;
        // int currMin = prices[0], currMax = prices[0], size = prices.size(), profit = 0;
        // bool minChanged = 0, maxChanged = 0;
        // for (int i = 1; i < size; i++)
        // {
        //     if (prices[i] < currMin)
        //     {
        //         currMin = prices[i];
        //         minChanged = 1;
        //     }
        //     if (prices[i] > currMax)
        //     {
        //         currMax = prices[i];
        //         maxChanged = 1;
        //     }
        // }
    }
};