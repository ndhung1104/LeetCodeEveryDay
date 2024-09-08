class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> countingArray(1002, 0);
        int h = 0;
        int size = citations.size();
        for (int i = 0; i < size; i++)
            countingArray[citations[i]]++;
        
        for (int i = 1000; i > -1; i--)
        {
            countingArray[i] += countingArray[i + 1];
            if (countingArray[i] >= i)
            {
                h = i;
                break;
            }
        }

        return h;
    }
};