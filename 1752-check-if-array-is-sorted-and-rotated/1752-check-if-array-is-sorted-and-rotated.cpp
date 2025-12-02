class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int drops = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                drops++;
            }
        }

        // circular check
        if (nums[n - 1] > nums[0]) {
            drops++;
        }

        return drops <= 1;
    }
};