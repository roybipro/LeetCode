class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int answer = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long sum = 0;

            for (int num : nums) {
                sum += (num + mid - 1) / mid; // ceil division
            }

            if (sum <= threshold) {
                answer = mid;       // valid divisor
                right = mid - 1;    // try smaller
            } else {
                left = mid + 1;     // need bigger divisor
            }
        }

        return answer;
    }
};