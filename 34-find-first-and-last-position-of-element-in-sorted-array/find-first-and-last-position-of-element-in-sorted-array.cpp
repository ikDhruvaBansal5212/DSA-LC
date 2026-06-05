class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int n = nums.size();
        int i = 0, j = n - 1;

        //First occurrence
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] == target) {
                if (mid == 0 || nums[mid - 1] != target) {
                    result.push_back(mid);
                    break;
                } else {
                    j = mid - 1;
                }
            } else if (nums[mid] < target) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }

        // If first occurrence not found
        if (result.size() == 0) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }

        // Second occurrence
        i = 0, j = n - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] == target) {
                if (mid == n - 1 || nums[mid + 1] != target) {
                    result.push_back(mid);
                    break;
                } else {
                    i = mid + 1;
                }
            } else if (nums[mid] < target) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }

        return result;
    }
};
