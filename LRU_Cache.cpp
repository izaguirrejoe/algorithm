#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    LRUCache (int capacity) : c{capacity} {}
    
    int get(int key){
        auto it = cache.find(key);
        if(it == cache.end()) return -1;
        touch(it);
        return it->second.first;
    }
    
    void put(int key, int value){
        auto it = cache.find(key);
        if(it != cache.end())
            touch(it);
        else{
            if(cache.size() == c){
                cache.erase(used.back());
                used.pop_back();
            }
            used.push_front(key);
        }
        cache[key] = {value,used.begin()};
    }
    
private:
    using list_iterator = list<int>::iterator;
    using Hash_int_to_pair = unordered_map<int, pair<int, list_iterator>>;
    
    int c;
    Hash_int_to_pair cache;
    list<int> used;
    
    void touch(Hash_int_to_pair::iterator it){
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }
};
