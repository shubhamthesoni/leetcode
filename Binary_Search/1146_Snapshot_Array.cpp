class SnapshotArray {
    vector<vector<pair<int, int>>> V;
    int snap_id;
public:
    SnapshotArray(int length) {
        V = vector<vector<pair<int, int>>>(length);
        snap_id = 0;
    }
    
    void set(int index, int val) {
        if(V[index].size() == 0) {V[index].push_back({snap_id, val}); return ; }
        int low = 0;
        int high = V[index].size() - 1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(V[index][mid].first == snap_id) { V[index][mid].second = val; return; }
            else if(V[index][mid].first < snap_id) low = mid + 1;
            else high = mid - 1;
        }
        V[index].push_back({snap_id, val});
        return ;
    }
    
    int snap() {
        snap_id++;
        return snap_id-1;
    }
    
    int get(int index, int snap_id) {
        if(V[index].size() == 0) return 0;
        int low = 0;
        int high = V[index].size() - 1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(V[index][mid].first == snap_id) return V[index][mid].second;
            else if(V[index][mid].first < snap_id) low = mid + 1;
            else high = mid - 1;
        }
        if(high >= 0) return V[index][high].second;
        return 0;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
