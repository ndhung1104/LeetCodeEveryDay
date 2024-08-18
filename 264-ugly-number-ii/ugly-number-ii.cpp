class Solution {
public:
    int nthUglyNumber(int n) {
        
        int count = 1;
        long long currUglyNum = 1;
        // int uglyList[169000]{0};
        map<long long, long long> uglyList;
        uglyList[1] = 1;
        auto i = uglyList.begin();
        // uglyList[1] = 1;
        // int prime[3]{2, 3, 5};
        while (count < n)
        {
            uglyList[currUglyNum * 2] = 1;
            uglyList[currUglyNum * 3] = 1;
            uglyList[currUglyNum * 5] = 1;
            i++;
            currUglyNum = i->first;
            count++;
            // cout << countPrime[0] << " " << countPrime[1] << " " << countPrime[2] << " " << count << " " << currUglyNum << endl;
        }
        // while (count < n)
        // {
        //     if ()
        // }
        return int(currUglyNum);
    }
};