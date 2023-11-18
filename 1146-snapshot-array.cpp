class SnapshotArray {
public:
    int size;
    unordered_map<int,map<int,int>>history;
    int era = 0;
    
    SnapshotArray(int length) { }
    
    void set(int index, int val) {
        history[index][era]=val;
    }
    
    int snap() {
        era = era+1;
        return era-1;
    }
    
    int get(int index, int snap_id) {
        auto ans = history[index].upper_bound(snap_id);
        return ans == begin(history[index]) ? 0 : prev(ans)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */