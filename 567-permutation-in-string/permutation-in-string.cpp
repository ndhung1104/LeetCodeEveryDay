class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1_count[125]{0}, s2_count[125]{0};

        int s1_size = s1.size(), s2_size = s2.size();

        if (s1_size > s2_size)
            return false;
        long long s1_sum = 0, s2_sum = 0;
        for (int i = 0; i < s1_size; i++)
        {
            s1_sum += s1[i];
            s1_count[s1[i]]++;
            s2_sum += s2[i];
            s2_count[s2[i]]++;
        }
        for (int i = 0; i < s2_size - s1_size + 1; i++)
        {
            if (s1_sum == s2_sum)
            {
                bool equal = true;
                for (int j = 'a'; j < 'z' + 1; j++)
                    if (s1_count[j] != s2_count[j])
                        equal = false;
                
                if (equal)
                    return true;
            }
            if (s1_size + i < s2_size)
            {
                s2_sum = s2_sum - s2[i] + s2[s1_size + i];
                s2_count[s2[i]]--;
                s2_count[s2[s1_size + i]]++;
            }
        }

        return false;
    }
};