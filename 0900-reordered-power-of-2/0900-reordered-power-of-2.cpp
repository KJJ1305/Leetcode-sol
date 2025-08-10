class Solution {
public:
    bool reorderedPowerOf2(int n) {
        // digit frequency of n
        array<int, 10> freqN = {};
        while (n > 0) {
            freqN[n % 10]++;
            n /= 10;
        }
        
        // check powers of 2
        int num = 1;
        for (int m = 0; m <= 30; m++) {
            array<int, 10> freqP = {};
            int temp = num;
            while (temp > 0) {
                freqP[temp % 10]++;
                temp /= 10;
            }
            if (freqP == freqN) return true;
            num <<= 1; // multiply by 2
        }
        return false;
    }
};
