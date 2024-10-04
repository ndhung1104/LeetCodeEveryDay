class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long skill_count[1001]{0}, size = skill.size();
        for (int i = 0; i < size; i++)
            skill_count[skill[i]]++;
        
        int sum_skill = 0, team_count = size / 2;

        for (int i = 1; i < 1001; i++)
            sum_skill += i * skill_count[i];
        
        if (sum_skill % team_count != 0)
            return -1;
        
        int target_skill = sum_skill / team_count;
        long long chemistry = 0;

        for (int i = 1; i < 1001; i++)
        {
            if (skill_count[i] != 0)
            {
                int counterpart = target_skill - i;
                if (counterpart > 1000)
                    return -1;
                if (counterpart == i)
                {
                    if (skill_count[i] % 2 == 1)
                        return -1;
                    chemistry += i * i * skill_count[i] / 2;
                    skill_count[i] = 0;
                }
                else
                {
                    if (skill_count[counterpart] != skill_count[i])
                        return -1;
                    chemistry += i * counterpart * skill_count[i];
                    skill_count[i] = 0;
                    skill_count[counterpart] = 0;
                }
            }
        }

        return chemistry;

    }
};