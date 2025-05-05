#include <iostream>
#include <vector>
#include <algorithm>  // for min and max functions
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, maxarea = 0;

        while (left < right) {
            int width = right - left;
            int h = min(height[left], height[right]);
            int area = width * h;
            maxarea = max(maxarea, area);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return maxarea;
    }
};

int main() {
    Solution sol;
    // Example usage
    // Input: height = [1,8,6,2,5,4,8,3,7]
    // Output: 49
    vector<int> height = {1,8,6,2,5,4,8,3,7}; 
    int result = sol.maxArea(height);
    cout  << result << endl;
    return 0;
}