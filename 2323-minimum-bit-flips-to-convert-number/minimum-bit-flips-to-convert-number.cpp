class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;

        while (start != 0 || goal != 0)
        {
            int startR = start % 2, goalR = goal % 2;
            start = start / 2;
            goal = goal / 2;
            if (startR != goalR)
                count++;
        }

        return count;
    }
};