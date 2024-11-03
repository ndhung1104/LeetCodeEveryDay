class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
            return false;
        
        int count = 0;
        for (int i = 0; i < s.size(); i++)
            count = count + s[i] - goal[i];
        if (count)
            return false;
        
        for (int i = 0; i < s.size(); i++)
        {
            int posCount = 0;
            while (posCount < s.size() && s[(i + posCount) % s.size()] == goal[posCount])
                posCount++;
            if (posCount == s.size())
                return true;
        }

        return false;
    }
};