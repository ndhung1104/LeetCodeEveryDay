class Solution {
public:
    int candy(vector<int>& ratings) {
        int rSize = ratings.size();
        vector<int> candies(rSize, 1);

        for (int i = 1; i < rSize; i++)
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        
        for (int i = rSize - 2; i >= 0; i--)
            if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
                candies[i] = candies[i + 1] + 1;
            
        int sum = 0;
        for (int i = 0; i < rSize; i++)
            sum += candies[i];
        
        return sum;
    }
};