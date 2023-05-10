// see leetcode discussion for explanation

class Solution {
public:
    int getSum(int a, int b) {
        int c = 0;

        while(b) {
            c = a & b; // determine the carry over
            a = a ^ b;
            b = (unsigned)c << 1; // assign the carry over after left shifting to b
            // without unsigned we get an error
        }

        return a;
    }
};