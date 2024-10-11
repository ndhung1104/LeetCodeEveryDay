class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int target_time = times[targetFriend][0];

        sort(times.begin(), times.end());

        cout << target_time << endl;
        for (int i = 0; i < times.size(); i++)
            cout << times[i][0] << "-" << times[i][1] << " ";
        cout << endl;

        int largest_chair = 0, i = 0, pos = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        priority_queue<int, vector<int>, greater<int>> chair_list;

        while ((times[i][0] != target_time ||  (times[i][0] == target_time && q.size() > 0 && q.top().first <= target_time)) && i < times.size())
        {
            // cout << i << " ";
            // if (q.size() > 0)
            //     cout << q.top().first << ":" << q.top().second;
            // cout << " ";
            // if (chair_list.size() > 0)
            //     cout << chair_list.top();
            // cout << endl;

            if (q.size() == 0)
            {
                if (chair_list.size() > 0) // existing chairs always smaller than new chair
                {
                    pair<int, int> tmp; // create new friend
                    int used_chair = chair_list.top(); // get used chair with the smallest number
                    chair_list.pop(); // remove that chair from queue

                    tmp.first = times[i][1];
                    tmp.second = used_chair;

                    q.push(tmp);
                    i++;
                }
                else
                {
                    pair<int, int> tmp; // new chair

                    tmp.first = times[i][1];
                    tmp.second = largest_chair;
                    largest_chair++;

                    q.push(tmp);
                    i++;
                }
            }
            else
            {
                pair<int, int> tmp = q.top();
                if (tmp.first <= times[i][0]) // expired chair
                {
                    q.pop(); // remove friend
                    int used_chair = tmp.second;
                    chair_list.push(used_chair); // get used chair and push to the queue
                }
                else // new arrival
                {
                    if (chair_list.size() > 0) // existing chairs always smaller than new chair
                    {
                        pair<int, int> tmp; // create new friend
                        int used_chair = chair_list.top(); // get used chair with the smallest number
                        chair_list.pop(); // remove that chair from queue

                        tmp.first = times[i][1];
                        tmp.second = used_chair;

                        q.push(tmp);
                        i++;
                    }
                    else
                    {
                        pair<int, int> tmp; // new chair

                        tmp.first = times[i][1];
                        tmp.second = largest_chair;
                        largest_chair++;

                        q.push(tmp);
                        i++;
                    }
                }
            }
        }
        // cout << i << " ";
        // if (q.size() > 0)
        //     cout << q.top().first << ":" << q.top().second;
        // cout << " ";
        // if (chair_list.size() > 0)
        //     cout << chair_list.top();
        // cout << endl;

        if (chair_list.size() == 0)
            return largest_chair;
        
        return chair_list.top();
    }
};