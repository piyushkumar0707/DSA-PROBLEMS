class LRUCache {
private:
    int capacity;
    list<pair<int, int>> dll; // Doubly linked list: {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> cache; // key -> iterator in dll

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;

        // Move accessed node to front
        auto it = cache[key];
        int value = it->second;
        dll.erase(it);
        dll.push_front({key, value});
        cache[key] = dll.begin();
        return value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key exists: remove old node
            dll.erase(cache[key]);
        } else if (dll.size() == capacity) {
            // Evict least recently used
            auto lru = dll.back();
            cache.erase(lru.first);
            dll.pop_back();
        }

        // Insert new node at front
        dll.push_front({key, value});
        cache[key] = dll.begin();
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */