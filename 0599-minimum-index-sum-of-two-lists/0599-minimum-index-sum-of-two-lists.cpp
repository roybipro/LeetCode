class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;
        
        // Store index of list1 strings
        for (int i = 0; i < list1.size(); i++) {
            mp[list1[i]] = i;
        }
        
        vector<string> result;
        int minSum = INT_MAX;
        
        // Traverse list2
        for (int j = 0; j < list2.size(); j++) {
            if (mp.count(list2[j])) {
                int sum = j + mp[list2[j]];
                
                if (sum < minSum) {
                    result.clear();
                    result.push_back(list2[j]);
                    minSum = sum;
                }
                else if (sum == minSum) {
                    result.push_back(list2[j]);
                }
            }
        }
        
        return result;
    }
};