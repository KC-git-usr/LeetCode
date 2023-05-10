class Solution {
public:
    int reverse(int x) {
        int result = 0, new_result = 0, tail = 0;

        while(x) {
            tail = x % 10;
            x /= 10;
            // perform overflow check before assigning (algebra manipulation)
            if((result > INT_MAX / 10) || (result == INT_MAX / 10 && tail > 7))
                return 0;
            if((result < INT_MIN / 10) || (result == INT_MIN / 10 && tail < -8))
                return 0;
            result = result*10 + tail;
        }

        return result;
    }
};