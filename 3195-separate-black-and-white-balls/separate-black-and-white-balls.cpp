class Solution {
public:
    long long minimumSteps(string s) {
        int start = 0, end = s.size() - 1;
        long long minSteps = 0;

        while (start < end)
        {
            while (start < s.size() && s[start] != '1')
                start++;
            while (end > -1 && s[end] != '0')
                end--;
            if (start < end)
            {
                minSteps += end - start;
                start++;
                end--;
            }
                
        }

        return minSteps;
    }
};