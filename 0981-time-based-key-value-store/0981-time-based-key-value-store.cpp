class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> tm;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        tm[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (tm.find(key) == tm.end()) return "";
        auto &v = tm[key];
        if (v.size() == 0) return "";
        int l = 0, r = v.size() - 1;
        
        while (l < r){ // find l such that l is the greatest time <= timestamp
            int m = (l + r + 1) / 2;
            int time = v[m].first;
            // if (timestamp == 4) cout << v << endl;
            if (time <= timestamp){
                l = m;
            } else {
                r = m - 1;
            }
        }
        
        return v[l].first <= timestamp ? v[l].second : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */