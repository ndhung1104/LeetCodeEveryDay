class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count[2];
        count[0] = 0;
        count[1] = 0;
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
            {
                count[0]++;
            }
            else if (bills[i] == 10)
            {
                if (count[0] == 0)
                    return false;
                count[0]--;
                count[1]++;
            }
            else
            {
                if (count[0] == 0)
                    return false;
                else if (count[1] == 0)
                    if (count[0] > 2)
                        count[0] = count[0] - 3;
                    else
                        return false;
                else
                {
                    count[0]--;
                    count[1]--;
                }

            }
        }
        return true;
    }
};