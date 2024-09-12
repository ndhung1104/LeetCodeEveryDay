class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> allowedChar(256, 0);
        for (int i = 0; i < allowed.size(); i++)
            allowedChar[allowed[i]] = 1;
        
        int count = 0, size = words.size();

        for (int i = 0; i < size; i++)
        {
            int wordSize = words[i].size();
            bool consistent = true;
            for (int j = 0; j < wordSize; j++)
                if (!allowedChar[words[i][j]])
                {
                    consistent = false;
                    break;
                }
            
            if (consistent)
                count++;
        }

        return count;
    }
};