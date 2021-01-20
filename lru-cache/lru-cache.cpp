class LRUCache {
public:
    struct Entry
    {
        int val;
        list<int>::iterator itr;
    };
    list<int> counter;
    unordered_map<int, Entry> cacheMap;
    int capacity;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        int res = -1;
        if(cacheMap.find(key) != cacheMap.end())
        {
            counter.erase(cacheMap[key].itr);
            res = cacheMap[key].val;
            counter.push_front(key);
            cacheMap[key].itr = counter.begin();
        }
        return res;
    }
    
    void put(int key, int value) {
        if(cacheMap.find(key) == cacheMap.end())
        {
            if(cacheMap.size() == capacity)
            {
                cacheMap.erase(counter.back());
                counter.pop_back();
            }
        }
        else{
            counter.erase(cacheMap[key].itr);
        }
        counter.push_front(key);
        cacheMap[key].val = value;
        cacheMap[key].itr = counter.begin();
    }
};
​
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
