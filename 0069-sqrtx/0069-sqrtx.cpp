class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;  // 0 -> 0, 1 -> 1
        
        long long left = 1, right = x / 2;
        int ans = 0;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            
            if (mid * mid <= x) {
                ans = mid;        // mid is a valid candidate
                left = mid + 1;   // try to find a bigger one
            } else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
};