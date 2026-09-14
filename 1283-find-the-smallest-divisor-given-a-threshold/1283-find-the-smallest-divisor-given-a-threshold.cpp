class Solution {
public:
    int sumByD(vector<int>& arr, int div) {
        int sum = 0;
        for(int num : arr) {
            sum += ceil((double)num / div);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        if(nums.size() > threshold) return -1;

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low <= high) {
            int mid = (low + high) / 2;
            if(sumByD(nums, mid) <= threshold) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};