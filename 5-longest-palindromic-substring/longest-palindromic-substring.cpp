class Solution {
public:
    string longestPalindrome(string s) {
        int strLen = s.size();
        int** dP = new int*[strLen];
        for (int i = 0; i < strLen; i++)
        {
            dP[i] = new int[strLen]{0};
            dP[i][i] = 1;
        }

        for (int col = 1; col < strLen; col++)
            for (int row = 0; row < col; row++)
            {
                if (s[row] == s[col])
                {
                    if (col > row + 1)
                    {
                        dP[row][col] = dP[row + 1][col - 1];
                    }
                    else
                        dP[row][col] = 1;
                }
                else
                    dP[row][col] = 0;
            }   
        
        // for (int i = 0; i < strLen; i++)
        // {
        //     for (int j = 0; j < strLen; j++)
        //         cout << dP[i][j] << " ";
        //     cout << endl;
            
        // }
        int start = 0, end = 0, maxLen = 1;

        for (int i = 0; i < strLen; i++)
        {
            for (int j = 0; j < strLen; j++)
            {
                if (dP[i][j])
                {
                    int tmpLen = j - i + 1;
                    if (tmpLen > maxLen)
                    {
                        start = i;
                        end = j;
                        maxLen = tmpLen;
                    }
                }
            }
            
        }

        for (int i = 0; i < strLen; i++)
            delete [] dP[i];
        
        delete [] dP;
        
        return s.substr(start, maxLen);
    }
};