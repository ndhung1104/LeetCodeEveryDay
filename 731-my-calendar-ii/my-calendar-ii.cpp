class MyCalendarTwo {
    vector<pair<int, int>> booking, overlap;

public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        for (int i = 0; i < overlap.size(); i++)
        {
            if ((start <= overlap[i].first && end > overlap[i].first) || (start >= overlap[i].first && start < overlap[i].second))
                return false;
            // cout << overlap[i].first << " " << overlap[i].second << endl;
        }
            

        for (int i = 0; i < booking.size(); i++)
            if ((start <= booking[i].first && end > booking[i].first) || (start >= booking[i].first && start < booking[i].second))//(booking[i].first <= start && booking[i].second > start)
                overlap.push_back({max(booking[i].first, start),
                                   min(booking[i].second, end)});

        booking.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */