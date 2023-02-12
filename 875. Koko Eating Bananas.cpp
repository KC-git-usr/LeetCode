// TIL : ceil of (0.01) is 1
// TIL : binary search, the target element may not be found, but return the closest smaller element
// use ceil(double(a) / b) AND use long int to store this
// don't use ceil((a + 0.0f) / b)

// idea to solve this problem: binary search for k within [1, max_element from piles]
// k >= 1 is possible if there is 1 banana per pile
// k <= max_element from piles is possible if every banana in pile is max

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        const int n = piles.size();
        if(n == 1)
            return ceil(double(piles[0]) / h);
        auto it_max = max_element(piles.begin(), piles.end());
        if(n == h)
            return *it_max;

        int left = 1, right = *it_max;
        int k = left + (right - left) / 2;
        int result = right;
        long int hours_taken = 0;
        while(left <= right) {
            hours_taken = 0;
            for(int i = 0; i < n; ++i)
                hours_taken += ceil(double(piles[i]) / k);
            if(hours_taken <= h) {
                right = k - 1;
                result = min(result, k);
            } else
                left = k + 1;
            k = left + (right - left) / 2;
        }

        return result;
    }
};