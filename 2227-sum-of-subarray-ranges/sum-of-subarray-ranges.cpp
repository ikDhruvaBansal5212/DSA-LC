class Solution {
public:
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> left(n), right(n);
        stack<int> st;

        // Previous Smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller or Equal
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++)
            ans += 1LL * arr[i] * left[i] * right[i];

        return ans;
    }

    long long sumSubarrayMax(vector<int>& arr) {
        int n = arr.size();

        vector<int> left(n), right(n);
        stack<int> st;

        // Previous Greater
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();

            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Greater or Equal
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();

            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++)
            ans += 1LL * arr[i] * left[i] * right[i];

        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums) - sumSubarrayMins(nums);
    }
};