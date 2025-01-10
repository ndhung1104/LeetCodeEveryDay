class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_set<string> w2List;
        vector<string> words2RemoveDup(words2);
        // for (int i = 0; i < words2.size(); i++)
        //     if (w2List.find(words2[i]) == w2List.end())
        //     {
        //         words2RemoveDup.push_back(words2[i]);
        //         w2List.insert(words2[i]);
        //     }
        
        int count2[300]{0};
        vector<string> ans, tmp;
        vector<vector<int>> words2Count(words2RemoveDup.size(), vector<int>(300, 0)), words1Count;
        
        for (int i = 0; i < words2RemoveDup.size(); i++)
            {
                for (int j = 0; j < words2RemoveDup[i].size(); j++)
                {
                    // count2[words2RemoveDup[i][j]]++;
                    words2Count[i][words2RemoveDup[i][j]++]++;
                }
                for (int k = 'a'; k <= 'z'; k++)
                    count2[k] = max(count2[k], words2Count[i][k]);
            }   
        
        for (int i = 0; i < words1.size(); i++)
        {
            // int count2[300]{0};
            vector<int> w1Count(300, 0);
            for (int j = 0; j < words1[i].size(); j++)
            {
                // count2[words2[i][j]]++;
                w1Count[words1[i][j]]++;
            }
            bool flag = true;
            for (int j = 'a'; j <= 'z'; j++)
                if (w1Count[j] < count2[j])
                    flag = false;
            if (flag == true)
            {
                tmp.push_back(words1[i]);
                words1Count.push_back(w1Count);
            }
        }

        return tmp;

        // for (int i = 0; i < words1.size(); i++)
        //     {for (int k = 'a'; k <= 'z'; k++)
        //         cout << words1Count[i][k] << " ";
        //     cout << endl;
        //         }
        // for (int i = 0; i < tmp.size(); i++)
        // {
        //     bool flag1 = true;
        //     for (int j = 0; j < words2RemoveDup.size() && flag1; j++)
        //     {
        //         for (int k = 'a'; k <= 'z'; k++)
        //             if (words1Count[i][k] < words2Count[j][k])
        //                 flag1 = false;
        //     }
        //     if (flag1)
        //         ans.push_back(tmp[i]);
        // }
            
        return ans;
    }
};