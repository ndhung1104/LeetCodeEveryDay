class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int size = arr.size();
        vector<int> k_remainder(k, 0);
        for (int i = 0; i < size; i++)
        {
            int remainder = (arr[i] % k + k) % k;
            // cout << remainder << " ";
            k_remainder[remainder]++;
        }
        // cout << endl;
        // for (int i = 0; i < k; i++)
        //     cout << k_remainder[i] << " ";
        
        for (int i = 1; i <= k/2; i++)
            if (k_remainder[i] != k_remainder[k - i])
                return false;
        
        if (k % 2 == 0)
            if (k_remainder[k/2] % 2 == 1)
                return false;
        
        return true;
    }
};