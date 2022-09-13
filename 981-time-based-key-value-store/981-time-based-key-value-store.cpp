class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> tm; // map: key -> [timestamp -> value]
    
    TimeMap() {
    } 
    
    void set(string key, string value, int timestamp) {
        tm[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (tm[key].empty()) return ""; // no values
        int l = 0;
        int r = tm[key].size();
        // binary search
        while (l < r){
            int m = l + (r - l)/2;
            if (tm[key][m].first > timestamp){
                r = m;
            } else {
                l = m + 1;
            }
        }
        if (l == 0) return "";
        return tm[key][l-1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */