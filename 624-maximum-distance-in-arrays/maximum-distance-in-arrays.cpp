class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int max1 = arrays[0][arrays[0].size() - 1], max1Pos = 0;
        int max2 = arrays[1][arrays[1].size() - 1], max2Pos = 1;
        if (max1 < max2)
        {
            swap(max1, max2);
            swap(max1Pos, max2Pos);
        }
        
        int min1 = arrays[0][0], min1Pos = 0;
        int min2 = arrays[1][0], min2Pos = 1;
        if (min1 > min2)
        {
            swap(min1, min2);
            swap(min1Pos, min2Pos);
        }
        //cout << max1 << " " << max2 << " " << min1 << " " << min2 << endl;
        for (int i = 2; i < n; i++)
        {
            int max3 = arrays[i][arrays[i].size() - 1], max3Pos = i;
            int min3 = arrays[i][0], min3Pos = i;
            if (max3 > max1)
            {
                max2 = max1;
                max1 = max3;
                max2Pos = max1Pos;
                max1Pos = max3Pos;
            }
            else if (max3 > max2)
            {
                max2 = max3;
                max2Pos = max3Pos;
            }
            if (min3 < min1)
            {
                min2 = min1;
                min1 = min3;
                min2Pos = min1Pos;
                min1Pos = min3Pos;
            }
            else if (min3 < min2)
            {
                min2 = min3;
                min2Pos = min3Pos;
            }
            //cout << max1 << " " << max2 << " " << min1 << " " << min2 << endl;
        }
    int m = -100000;
    if (max1Pos != min1Pos)
        m = max(m, abs(max1 - min1));
    if (max1Pos != min2Pos)
        m = max(m, abs(max1 - min2));
    if (max2Pos != min1Pos)
        m = max(m, abs(max2 - min1));
    if (max2Pos != min2Pos)
        m = max(m, abs(max2 - min2));
    return m;
    }
};