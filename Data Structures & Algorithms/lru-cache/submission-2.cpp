class LRUCache {
public:
    list<int> dll;
    int n;
    unordered_map<int,pair<list<int>::iterator,int>> mp;
    LRUCache(int capacity) {
        n = capacity;
    }
    void makeRecentlyUsed(int key){
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }
    int get(int key) {
        if(mp.find(key) != mp.end()){
            makeRecentlyUsed(key);
            return mp[key].second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key].second = value;
            makeRecentlyUsed(key);
        }
        else{
            dll.push_front(key);
            mp[key] = {dll.begin(),value};
            n--;
        }
        if(n<0){
            int lastKey = dll.back();
            mp.erase(lastKey);
            dll.pop_back();
            n++;
        }
    }
};
