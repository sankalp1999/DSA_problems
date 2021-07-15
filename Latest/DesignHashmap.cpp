class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector< list< pair<int,int> >> v;
    MyHashMap() {
        v.resize(100000);
    }
    
    /** value will always be non-negative. */   
    int hashCode(int key)
    {
        const int mod = 10000;
        key = key % mod;
        return key;
    }
    
    void put(int key, int value) {

        key = hashCode(key);
        
        for(auto &it : v[key])
        {
            if(it.first == key)
            {
                it.second = value;
                return;
            }
        }
        v[key].push_back({key,value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        key = hashCode(key);
        for(auto it : v[key])
        {
            if(it.first == key)
                return it.second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        key = hashCode(key);
        auto& pairs = v[key];
        for(auto i = pairs.begin(); i != pairs.end(); i++)
        {
            if(i->first == key)
            {
                pairs.erase(i);
                return;
            }
        }
    
    }
};
