class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        int start = 0, maxLen = 0;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            // when the loop stops, left and right are one step past the palindrome
            return pair<int,int>(left + 1, right - 1);
        };

        for (int i = 0; i < n; i++) {
            // odd length
            auto [l1, r1] = expand(i, i);
            if (r1 - l1 + 1 > maxLen) {
                start = l1;
                maxLen = r1 - l1 + 1;
            }

            // even length
            auto [l2, r2] = expand(i, i + 1);
            if (r2 - l2 + 1 > maxLen) {
                start = l2;
                maxLen = r2 - l2 + 1;
            }
        }

        return s.substr(start, maxLen);
    }
};