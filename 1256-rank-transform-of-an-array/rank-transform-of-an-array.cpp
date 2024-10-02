class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int, int>> buffer;
        for (int i = 0; i < arr.size(); i++)
            buffer.push_back({arr[i], i});

        sort(buffer.begin(), buffer.end());
        int currRank = 1;
        for (int i = 0; i < buffer.size(); i++)
        {
            arr[buffer[i].second] = currRank;
            if (i != buffer.size() - 1 && buffer[i].first != buffer[i + 1].first)
                currRank++;
        }
        
        return arr;
    }
};