class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n<=0)
            return false;

        return !(n&n-1)&&(__builtin_ctz(n)%2==0);
        
    }
};