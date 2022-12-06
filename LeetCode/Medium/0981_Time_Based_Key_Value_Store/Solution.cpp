// 2022-10-05 (binary search map)
class TimeMap {
public:
    unordered_map<string, map<int, string>> storage;

    TimeMap() { 
    }
    
    void set(string key, string value, int timestamp) {
        this->storage[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        // equal range returns a pair with the second value being an iterator pointing
        // at the smallest value greater than the input (timestamp).
        auto range = this->storage[key].equal_range(timestamp);

        // if the iterator is pointing at the start, then our timestamp is smaller than
        // any existing timestamp in our storage. because we only want to return values
        // from a timestamp <= our input timestamp, we return "" instead.
        if (range.second == this->storage[key].begin()) 
            return "";

        // iterating backwards is guaranteed to get us a value equal or less than our 
        // input timestamp
        return prev(range.second)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */