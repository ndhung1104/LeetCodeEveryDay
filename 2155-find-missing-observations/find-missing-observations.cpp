class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> blankResult, result;

        int currSum = 0, currSize = rolls.size(), targetSum = mean * (n + currSize);

        for (int i = 0; i < currSize; i++)
            currSum += rolls[i];
        
        for (int i = n; i > 0; i--)
        {
            
            int value = (targetSum - currSum) / i;
            if (value < 1)
                value = 1;
            else if (value > 6)
                value = 6;
            // cout << targetSum << ":" << currSum << " " << value << endl;
            result.push_back(value);
            currSum += value;

        }

        if (currSum == targetSum)
            return result;
        
        return blankResult;

    }
};