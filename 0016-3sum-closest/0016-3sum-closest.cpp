class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
    int n = nums.size();
    int closestSum = nums[0] + nums[1] + nums[2];  // Initialize with first three numbers

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1, right = n - 1;
        while (left < right) {
            int currentSum = nums[i] + nums[left] + nums[right];

            // Update closestSum if current is closer to target
            if (abs(currentSum - target) < abs(closestSum - target)) {
                closestSum = currentSum;
            }

            if (currentSum < target) {
                left++;
            } else if (currentSum > target) {
                right--;
            } else {
                // If exact match
                return currentSum;
            }
        }
    }
    return closestSum;
}

int main() {
    vector<int> nums1 = {-1, 2, 1, -4};
    int target1 = 1;
    cout << threeSumClosest(nums1, target1) << endl;  // Output: 2

    vector<int> nums2 = {0, 0, 0};
    int target2 = 1;
    cout << threeSumClosest(nums2, target2) << endl;  // Output: 0

    return 0;
        
    }
};