class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int el = 0;

        // Phase 1: Find candidate
        for(int i = 0; i < nums.size(); i++){
            if(cnt == 0){
                el = nums[i];
                cnt = 1;
            }
            else if(nums[i] == el){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        // Phase 2: Verify candidate
        int cnt1 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == el) cnt1++;
        }

        if(cnt1 > nums.size() / 2) return el;
        return -1;
    }
};