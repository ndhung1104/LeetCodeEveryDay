class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int number = 1;
        for (int i = 1; i <= n; i++)
        {
            ans.push_back(number);
            if (number * 10 <= n)
                number = number * 10;
            else
            {
                while (number % 10 == 9 || number >= n)
                    number = number / 10;
                
                number++;
            }
        }

        return ans;
    }
};