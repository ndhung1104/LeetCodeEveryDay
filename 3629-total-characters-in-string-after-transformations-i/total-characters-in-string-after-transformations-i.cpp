class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        long long count[300]{0};
        for (int i = 0; i < s.size(); i++)
            count[s[i]]++;
        for (int i = 0; i < t; i++)
            {
                // for (int j = 'a'; j <= 'z'; j++)
                //     cout << count[j] << " ";
                // cout << endl;
                long long tmp = count['z'];
                for (int j = 'z'; j > 'a'; j--)
                    count[j] = count[j - 1];
                count['a'] = tmp % (1000000007);
                count['b'] += tmp;
            }
        long long returnVal = 0;
        for (int i = 'a'; i <= 'z'; i++)
            returnVal = (returnVal + count[i] % (1000000007)) % (1000000007);
        
        return (int)returnVal;
    }
};