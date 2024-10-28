class Solution {
    const int MOD = 1e9 + 7;
    typedef vector<vector<int>> Matrix;
    Matrix multiplyMatrix(const Matrix &A, const Matrix &B) {
        int rowsA = A.size();
        int colsA = A[0].size();
        int rowsB = B.size();
        int colsB = B[0].size();
        
        Matrix C(rowsA, vector<int>(colsB, 0));
        
        for (int i = 0; i < rowsA; ++i) {
            for (int j = 0; j < colsB; ++j) {
                for (int k = 0; k < colsA; ++k) {
                    C[i][j] = (C[i][j] + 1LL * A[i][k] * B[k][j] % MOD) % MOD;
                }
            }
        }
        
        return C;
    }
    
    Matrix powerMatrix(const Matrix &A, int n) {
        int size = A.size();
        Matrix result(size, vector<int>(size, 0));
        
        for (int i = 0; i < size; ++i) {
            result[i][i] = 1;
        }
        
        Matrix base = A;
        while (n > 0) {
            if (n % 2 == 1) {
                result = multiplyMatrix(result, base);
            }
            base = multiplyMatrix(base, base);
            n /= 2;
        }
        return result;
    }
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        long long count[300]{0};
        Matrix A(26, vector<int>(26, 0));
        Matrix B(1, vector<int>(26, 0));
        for (int i = 0; i < s.size(); i++)
            B[0][s[i] - 'a']++;
        int zPos = 'z' - 'a';
        for (int row = 0; row <= 25; row++)
            for (int col = 1; col <= nums[row]; col++)
                A[row][(row + col) % 26] = 1;
        
        for (int i = 0; i < 26; i++)
            {for (int j = 0; j < 26; j++)
                cout << A[i][j] << " ";
            cout << endl;}
        // for (int col = 0; col <= zPos; col++)
        //     for (int row = 1; row <= nums[col]; row++)
        //         A[(row + col) % 26][col] = 1;
        A = powerMatrix(A, t);
        long long returnVal = 0;
        if (t > 1)
        {
            Matrix C = multiplyMatrix(B, A);
            for (int i = 0; i < 26; i++)
                returnVal = (returnVal + C[0][i] % (1000000007)) % (1000000007);
        }
            
        // cout << C.size() << " " << C[0].size();
        else
            {
                for (int i = 0; i < t; i++)
                {
                    long long tmpCount[300]{0};
                    // for (int j = 'a'; j <= 'z'; j++)
                    //     cout << count[j] << " ";
                    // cout << endl;
                    for (int j = 0; j <= zPos; j++)
                        for (int k = 1; k <= nums[j]; k++)
                            tmpCount[(j + k)%(zPos + 1)] += B[0][j];

                    for (int j = 0; j <= zPos; j++)
                        B[0][j] = tmpCount[j] % (1000000007);
                }
                for (int i = 0; i < 26; i++)
                    returnVal = (returnVal + B[0][i] % (1000000007)) % (1000000007);
        }
        
        
        
        return (int)returnVal;
    }
};