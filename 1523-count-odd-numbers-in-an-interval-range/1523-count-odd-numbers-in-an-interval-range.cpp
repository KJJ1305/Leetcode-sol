class Solution {
public:
    int countOdds(int low, int high) {
        if(high%2==0)
            high=high/2;
        else
            high=(high+1)/2;

        if(low%2==0)
            low=low/2;
        else
            low=(low+1)/2-1;

           
        return high-low;
    }
};