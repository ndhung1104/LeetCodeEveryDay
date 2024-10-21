class Solution {
    unordered_set<string> substringSet;
public:
    void maxSplitRecursive(string s, int &max, int curr)
    {
        if (s.size() + curr < max)
            return;

        if (s.size() == 0)
            if (curr > max)
                max = curr;
        
        for (int i = 1; i <= s.size(); i++)
        {
            string tmp = s.substr(0, i);
            // cout << tmp << " " << s << " " << max << " " << curr << endl;
            if (substringSet.find(tmp) == substringSet.end())
            {
                substringSet.insert(tmp);
                maxSplitRecursive(s.substr(i), max, curr + 1);
                substringSet.erase(substringSet.find(tmp));
            }
        }
        
    }
    int maxUniqueSplit(string s) {
        
        int maxSplit = 1;
        maxSplitRecursive(s, maxSplit, 0);

        return maxSplit;
    }
};