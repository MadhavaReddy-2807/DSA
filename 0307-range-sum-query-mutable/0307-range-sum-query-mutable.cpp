class NumArray {
public:
    vector<int> seg;
    vector<int> rough;

    void build(int l, int r, int i, vector<int>& nums) {
        if (l == r) {
            seg[i] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, 2 * i + 1, nums);
        build(mid + 1, r, 2 * i + 2, nums);
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    NumArray(vector<int>& nums) {
        int n = nums.size();
        seg.resize(4 * n, 0);
        rough.assign(nums.begin(), nums.end());
        if (n > 0) build(0, n - 1, 0, nums);
    }

    void updateseg(int index, int val, int l, int r, int i) {
        if (l == r) {
            seg[i] += val;
            return;
        }
        seg[i] += val; // propagate delta
        int mid = (l + r) / 2;
        if (index <= mid) {
            updateseg(index, val, l, mid, 2 * i + 1);
        } else {
            updateseg(index, val, mid + 1, r, 2 * i + 2);
        }
    }

    void update(int index, int val) {
        // subtract old value
        updateseg(index, -rough[index], 0, rough.size() - 1, 0);
        // add new value
        updateseg(index, val, 0, rough.size() - 1, 0);
        rough[index] = val; // update original array
    }

    int sumrangeseg(int ql, int qr, int l, int r, int index) {
        if (qr < l || r < ql) return 0;         // no overlap
        if (ql <= l && r <= qr) return seg[index]; // total overlap

        int mid = (l + r) / 2;
        return sumrangeseg(ql, qr, l, mid, 2 * index + 1) +
               sumrangeseg(ql, qr, mid + 1, r, 2 * index + 2);
    }

    int sumRange(int left, int right) {
        return sumrangeseg(left, right, 0, rough.size() - 1, 0);
    }
};
