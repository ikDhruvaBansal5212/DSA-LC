class Solution {
public:
    int solve(int i, string &s, vector<int> &dp) {
        if (i == s.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = INT_MAX;

        for (int j = i; j < s.size(); j++) {
            if (isPalindrome(i, j, s)) {
                ans = min(ans, 1 + solve(j + 1, s, dp));
            }
        }

        return dp[i] = ans;
    }

    bool isPalindrome(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, -1);

        return solve(0, s, dp) - 1;
    }
};