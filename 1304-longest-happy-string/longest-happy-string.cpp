class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> q;
        q.push({a, 'a'});
        q.push({b, 'b'});
        q.push({c, 'c'});

        string ans = "";

        while (q.size() > 0)
        {
            pair<int, char> tmp, tmp1;
            tmp = q.top();
            q.pop();
            if (tmp.first > 0)
            {
                if (ans.size() < 2)
                {
                    ans += tmp.second;
                    tmp.first--;
                }
                else if (ans[ans.size() - 1] != tmp.second || (ans[ans.size() - 2] != tmp.second))
                {
                    ans += tmp.second;
                    tmp.first--;
                }
                else
                {
                    if (q.size() == 0)
                        break;
                    tmp1 = q.top();
                    q.pop();
                    if (tmp1.first < 1)
                        break;
                    ans += tmp1.second;
                    tmp1.first--;
                    if (tmp1.first > 0)
                        q.push(tmp1);
                }
                if (tmp.first > 0)
                    q.push(tmp);
            }
            
        }

        return ans;
    }
};