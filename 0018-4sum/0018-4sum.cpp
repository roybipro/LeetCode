class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
    int n = nums.size();
    if (n < 4) return result;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates

        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j-1]) continue; // skip duplicates

            int left = j + 1, right = n - 1;
            while (left < right) {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    // Skip duplicates
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;

    vector<vector<int>> ans = fourSum(nums, target);

    for (auto &quad : ans) {
        for (int num : quad) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
    }
};