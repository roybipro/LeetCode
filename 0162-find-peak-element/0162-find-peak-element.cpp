class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // we are going uphill, so a peak is on the right
                left = mid + 1;
            } else {
                // we are going downhill, so a peak is on the left or at mid
                right = mid;
            }
        }

        // left == right, pointing to a peak
        return left;
    }
};