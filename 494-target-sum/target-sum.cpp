class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int totalSum = 0;
        for (int x : nums)
            totalSum += x;

        if (abs(target) > totalSum) return 0;
        if ((totalSum + target) % 2) return 0;

        int req = (totalSum + target) / 2;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(req + 1, 0));

        if (nums[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if (nums[0] != 0 && nums[0] <= req)
            dp[0][nums[0]] = 1;

        for (int i = 1; i < n; i++) {
            for (int sum = 0; sum <= req; sum++) {

                int nottake = dp[i - 1][sum];

                int take = 0;
                if (nums[i] <= sum)
                    take = dp[i - 1][sum - nums[i]];

                dp[i][sum] = take + nottake;
            }
        }

        return dp[n - 1][req];
    }
};