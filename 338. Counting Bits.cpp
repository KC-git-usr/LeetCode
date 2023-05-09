// see leetcode dicussions for explanation
// idea : dp + bit manipulation
// (i & 1) is equivalent to determining if it's ODD or EVEN
// and
// (i >> 1) == (i / 2)

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);
        int copy;

        for (int i = 1; i <= n; i++) {
            //                 i / 2      i % 2
            result[i] = result[i >> 1] + (i & 1);
        }

        return result;
    }
};