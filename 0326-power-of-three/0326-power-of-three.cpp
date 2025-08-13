class Solution {
public:
    bool isPowerOfThree(int n) {
        
        int num=pow(3,19);

        if(n<=0)
            return false;

        if(num%n==0)
            return true;
        else
            return false;

    }
};