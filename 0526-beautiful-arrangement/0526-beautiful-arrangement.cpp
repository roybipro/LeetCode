class Solution {
public:
    int countArrangement(int n) {
        vector<bool> used(n + 1, false);
        return backtrack(1, n, used);
    }
    
    int backtrack(int pos, int n, vector<bool>& used) {
        if (pos > n) return 1;
        
        int count = 0;
        for (int num = 1; num <= n; num++) {
            if (!used[num] && (num % pos == 0 || pos % num == 0)) {
                used[num] = true;
                count += backtrack(pos + 1, n, used);
                used[num] = false;
            }
        }
        return count;
    }
};