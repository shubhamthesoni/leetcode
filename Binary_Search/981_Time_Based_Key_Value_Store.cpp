class TimeMap {
    map<string, vector<pair<int, string>>> M;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        M[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        //cout<<"test"<<endl;
        if(M.find(key) == M.end()) return "";
        int low = 0;
        int high = M[key].size()-1;
        int mid = 0;

        //cout << M[key][low].first << ":"<<timestamp <<endl;
        //if((M[key][low].first)  > timestamp)  { return ""; }

        while(low <= high)
        {
            mid = low + (high -low)/2;
            if(M[key][mid].first == timestamp) return M[key][mid].second;
            else if (M[key][mid].first < timestamp) low = mid+1;
            else high = mid-1;
            //cout << low <<":"<<mid<<":"<<high<<endl;
        }
        
        if(high >= 0) return M[key][high].second;
        //if(low < 0) low = 0;
        //if(low >= M[key].size()) low= M[key].size() -1 ;
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
