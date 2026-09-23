class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currentMax = nums[0];
        int currentMin = nums[0];
        int ans = nums[0];

        for(int i = 1; i < n; i++) {
            int x = nums[i];
            if(x < 0) {
                swap(currentMax, currentMin);
            }
            currentMax = max(x, currentMax * x);
            currentMin = min(x, currentMin * x);
            ans = max(ans, currentMax);
        }
        return ans;
    }
};