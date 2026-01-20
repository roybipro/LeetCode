class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
       if (nums.empty()) return 0;

        int maxLen = 1;
        int current = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                current++;
            } else {
                current = 1;
            }
            maxLen = max(maxLen, current);
        }

        return maxLen;  
    }
};