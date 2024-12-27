class LFUCache {
public:
    
    int cacheCapacity;
    int currentSize;
    unordered_map<int, list<vector<int>>::iterator> keyToIteratorMap; //key -> address of list of vector{key, value, freq}
    map<int, list<vector<int>>> frequencyMap; //freq -> list of vector{key, value, freq}
    
    LFUCache(int capacity) {
         cacheCapacity = capacity;
        currentSize = 0;
    }
    void promoteFrequency(int key) {
        auto &vec = *(keyToIteratorMap[key]);
        int value = vec[1];
        int f = vec[2];
        frequencyMap[f].erase(keyToIteratorMap[key]);
        if(frequencyMap[f].empty())
            frequencyMap.erase(f);
        f++;
        frequencyMap[f].push_front(vector<int>({key, value, f}));
        keyToIteratorMap[key] = frequencyMap[f].begin();
    }
    
    int get(int key) {
        if(keyToIteratorMap.find(key) == keyToIteratorMap.end())
            return -1;
        auto &vec = (*(keyToIteratorMap[key]));
        int value = vec[1];
        promoteFrequency(key);
        return value;
    }
    
    
    void put(int key, int value) {
         if(cacheCapacity == 0)
            return;
        if(keyToIteratorMap.find(key) != keyToIteratorMap.end()) {
            auto &vec = (*(keyToIteratorMap[key]));
            vec[1] = value;
            promoteFrequency(key);
        }
        else if(currentSize < cacheCapacity) {
            currentSize++;
            frequencyMap[1].push_front(vector<int>({key, value, 1}));
            keyToIteratorMap[key] = frequencyMap[1].begin();
        }
        else { // Time to remove LFU or LRU if tie
            auto &leastFreqList = frequencyMap.begin()->second;
            int keyToRemove = (leastFreqList.back())[0]; // ordered_map ensures that the begin() will be the least frequency
            leastFreqList.pop_back();
            if(leastFreqList.empty())
                frequencyMap.erase(frequencyMap.begin()->first);
            frequencyMap[1].push_front(vector<int>({key, value, 1}));
            keyToIteratorMap.erase(keyToRemove);
            keyToIteratorMap[key] = frequencyMap[1].begin();
        }
    }
};
