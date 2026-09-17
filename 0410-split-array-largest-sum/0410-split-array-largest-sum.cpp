class Solution {
public:
    int countPartitions(vector<int>& arr, int maxSum) {
        int partitions = 1;
        long subarraySum = 0;

        for(int num : arr) {
            if(subarraySum + num <= maxSum) {
                subarraySum += num;
            }
            else {
                partitions++;
                subarraySum = num;
            }
        }
        return partitions;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int partitions = countPartitions(nums, mid);

            if(partitions > k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};