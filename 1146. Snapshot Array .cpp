// TIL : how to use upper_bound on a map
// Note : we've used a map, not an unordered_map

class SnapshotArray {
private:
    unordered_map<int, map<int, int>> hash_map;  // array index, snap #, data
    int snap_id;
public:
    SnapshotArray(int length) {
        this->snap_id = 0;
    }

    void set(int index, int val) {
        this->hash_map[index][this->snap_id] = val;
    }

    int snap() {
        return this->snap_id++;
    }

    int get(int index, int snap_id) {
        auto it = this->hash_map[index].upper_bound(snap_id);
        return it == this->hash_map[index].begin() ? 0 : prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */