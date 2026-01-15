class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        
        vector<vector<int>> result(m, vector<int>(n, 0));
        
        // Directions for the 3x3 neighborhood
        int dirs[3] = {-1, 0, 1};
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                int count = 0;
                
                // Check all neighboring cells
                for (int dx : dirs) {
                    for (int dy : dirs) {
                        int ni = i + dx;
                        int nj = j + dy;
                        
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                            sum += img[ni][nj];
                            count++;
                        }
                    }
                }
                
                result[i][j] = sum / count; // floor division
            }
        }
        
        return result;
    }
};