class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }

    bool solve(vector<double>& nums) {
        int n = nums.size();
        if (n == 1) {
            return fabs(nums[0] - 24.0) < 1e-6;
        }

        // try all pairs of numbers
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                vector<double> next;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }

                // try all operations on nums[i] and nums[j]
                for (int op = 0; op < 4; op++) {
                    // prune: avoid duplicate commutative operations
                    if ((op == 0 || op == 2) && i > j) continue;

                    if (op == 0) { // addition
                        next.push_back(nums[i] + nums[j]);
                    } else if (op == 1) { // subtraction
                        next.push_back(nums[i] - nums[j]);
                    } else if (op == 2) { // multiplication
                        next.push_back(nums[i] * nums[j]);
                    } else if (op == 3) { // division
                        if (fabs(nums[j]) < 1e-6) continue;
                        next.push_back(nums[i] / nums[j]);
                    }

                    if (solve(next)) return true;
                    next.pop_back(); // backtrack
                }
            }
        }
        return false;
    }
};
