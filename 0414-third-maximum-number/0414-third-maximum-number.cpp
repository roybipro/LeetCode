class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        for (int n : nums) {
            // Skip duplicates
            if (n == first || n == second || n == third) continue;

            if (n > first) {
                third = second;
                second = first;
                first = n;
            }
            else if (n > second) {
                third = second;
                second = n;
            }
            else if (n > third) {
                third = n;
            }
        }

        // If third max doesn't exist, return max
        return (third == LLONG_MIN) ? first : third;
    }
};