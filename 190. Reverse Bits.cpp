// 00000010100101000001111010011100
// 00111001011110000010100101000000

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        int n_iterations = 0;

        for(int i = 0; i < 32; ++i) {
            result <<= 1;
            result |= (n & 1);
            n >>= 1;
        }

        return result;
    }
};