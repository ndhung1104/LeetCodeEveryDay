class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int count = gas[0] - cost[0], minCount = count, minPos = 0, size = gas.size();

        for (int i = 1; i < size; i++)
        {
            count += gas[i] - cost[i];
            if (count < minCount)
            {
                minCount = count;
                minPos = i;
            }
        }
            
        if (count >= 0)
            return (minPos + 1) % size;

        return -1;
    }
};