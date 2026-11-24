class Solution {
public:
    int maxLength(vector<int>& nums) {
        int mx = 0, ml = 1;
        for (int x : nums) {
            mx = max(mx, x);
            ml = lcm(ml, x);
        }
        long long maxP = 1LL * ml * mx;
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            long long p = 1;
            int g = 0, l = 1;
            for (int j = i; j < n; ++j) {
                p *= nums[j];
                if (p > maxP) {
                    break;
                }
                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);
                if (p == 1LL * g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
        
    }
};