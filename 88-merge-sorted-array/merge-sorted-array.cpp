class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> sumNums;
        int mPos = 0, nPos = 0;
        while (mPos < m && nPos < n)
        {
            if (nums1[mPos] < nums2[nPos])
                sumNums.push_back(nums1[mPos++]);
            else
                sumNums.push_back(nums2[nPos++]);
        }
        if (mPos == m)
            while (nPos < n)
                sumNums.push_back(nums2[nPos++]);
        else if (nPos == n)
            while (mPos < m)
                sumNums.push_back(nums1[mPos++]);
        
        for (int i = 0; i < sumNums.size(); i++)
            nums1[i] = sumNums[i];
    }
};