class Solution {
public:
    static bool cmp(int a, int b) {
        return abs(a) < abs(b);
    }
    
    long long perfectPairs(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), cmp);
        
        long long count = 0;
        for (int i = 0; i < n; i++) {
            int a = nums[i];
            int limit = 2 * abs(a);
            
            // binary search: find last index j where |nums[j]| <= limit
            int lo = i + 1, hi = n - 1, pos = i;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (abs(nums[mid]) <= limit) {
                    pos = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            count += (pos - i);
        }
        return count;
    }
};
