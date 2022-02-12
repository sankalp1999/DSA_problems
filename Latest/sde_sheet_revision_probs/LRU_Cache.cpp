class LRUCache {
public:
    int total;
    list< int > l;
    
    // need to access the value also in O(1)
    
    // List consists of list<key>
    // structure is  map< key, pair<list<key>, val> >
    unordered_map< int,pair < list< int >::iterator, int > > cache;
    LRUCache(int capacity) {
        total = capacity;
    }
    
    /*
    If I get the key, it has been used. 
    So update?
    */
    
    int get(int key) {
        if(cache.find(key) != cache.end())
        {
            auto node = cache[key]; // Get the node 
            auto it = node.first; // iterator
            int val = node.second;
            l.erase(it); // remove the iterator
            l.push_front(key); // push in front the val
            cache[key] = {l.begin(), val};
            return cache[key].second;
        }
        else return -1;
    }
    
    /*
    If I find the key, then
    1. Replace and put to front.
    2. Delete old one.
    3. Capacity? Need not be changed.
    
    
    ------
    If key not there,
    1. Add it.
    2. Increase capacity
    3. Evict last element from list if capacity exceeded
    
    */
    void put(int key, int value) {
        if(cache.find(key) != cache.end())
        {
            auto node = cache[key]; // Get the node 
            auto it = node.first; // iterator
            int val = node.second;
            l.erase(it); // remove the iterator
            l.push_front(key); // push in front the val
            cache[key] = {l.begin(), value};
        }
        else
        {
            if(total == cache.size())
            {
                auto node = l.back();
                l.pop_back();
                cache.erase(node);
            }
                 
                l.push_front(key);
                cache[key] = {l.begin(), value};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
