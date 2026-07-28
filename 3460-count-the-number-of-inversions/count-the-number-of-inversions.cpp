class Solution {
public:
    static const int MOD = 1e9 + 7;

    int numberOfPermutations(int n, vector<vector<int>>& requirements) {

        vector<int> req(n, -1);

        for (auto &v : requirements)
            req[v[0]] = v[1];

        if (req[0] > 0)
            return 0;

        int MAX = 400;

        vector<vector<int>> dp(n + 1, vector<int>(MAX + 1, 0));
        dp[1][0] = 1;

        for (int len = 2; len <= n; len++) {

            vector<int> prefix(MAX + 2, 0);

            for (int j = 0; j <= MAX; j++)
                prefix[j + 1] = (prefix[j] + dp[len - 1][j]) % MOD;

            for (int inv = 0; inv <= MAX; inv++) {

                int l = max(0, inv - (len - 1));
                int r = inv;

                dp[len][inv] =
                    (prefix[r + 1] - prefix[l] + MOD) % MOD;
            }

            if (req[len - 1] != -1) {

                int need = req[len - 1];

                for (int inv = 0; inv <= MAX; inv++) {

                    if (inv != need)
                        dp[len][inv] = 0;
                }
            }
        }

        return dp[n][req[n - 1]];
    }
};