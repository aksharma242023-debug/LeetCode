
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        long long ans = 0, cost = 0;
        int left = n - 1;

        for (int right = n - 1; right >= 0; right--) {
            while (!dq.empty() && nums[dq.back()] <= nums[right]) {
                int j = dq.back();
                dq.pop_back();

                int p = dq.empty() ? left + 1 : dq.back();

                cost += 1LL * (p - j) * (nums[right] - nums[j]);
            }

            dq.push_back(right);

            while (cost > k) {
                cost -= nums[dq.front()] - nums[left];

                if (dq.front() == left)
                    dq.pop_front();

                left--;
            }

            ans += left - right + 1;
        }

        return ans;
    }
};
