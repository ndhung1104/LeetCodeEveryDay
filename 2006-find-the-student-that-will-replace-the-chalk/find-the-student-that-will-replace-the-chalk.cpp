class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int studentNum = chalk.size();
        long long sum = 0, tempK = k;
        for (int i = 0; i < studentNum; i++)
            sum += chalk[i];
        
        tempK = tempK % sum;
        int pos = 0;
        
        tempK = tempK - chalk[0];

        while (tempK > -1)
        {
            pos++;
            tempK -= chalk[pos];
        }

        return pos;
    }
};