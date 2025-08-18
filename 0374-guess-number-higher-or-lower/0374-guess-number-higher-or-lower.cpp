/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long st=1;
        long long end=n;
        long long mid;
        while(st<=end){
            mid=(st+end)/2;
            if(guess(mid)==0){
                return (int)mid;
            }
            else if(guess(mid)==-1){
                end=mid-1;
            }
            else
                st=mid+1;
        }
        return 0;
    }
};