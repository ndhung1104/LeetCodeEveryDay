class RandomizedSet {
    unordered_map<int, int> randMap;
    vector<int> randMapArray;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (randMap.find(val) == randMap.end())
        {
            randMapArray.push_back(val);
            randMap[val] = randMapArray.size() - 1;
            return true;
        }

        return false;
    }
    
    bool remove(int val) {
        if (randMap.find(val) == randMap.end())
        {
            return false;
        }
        int valPos = randMap[val];
        int lastValue = randMapArray[randMapArray.size() - 1];
        randMap[lastValue] = valPos; // swap position of the deleted value and the last value to not change the position of others when delete
        randMapArray[valPos] = lastValue;
        randMapArray.pop_back();
        randMap.erase(val);
        return true;
    }
    
    int getRandom() {
        int size = randMapArray.size(), ranPos = rand() % size;
        
        return (randMapArray[ranPos]);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */