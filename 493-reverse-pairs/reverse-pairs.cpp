class Solution {
    long long ans = 0;
    void countPairs(vector<int> &nums, int low, int mid, int high) {
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && nums[i] > 1LL * nums[j] * 2) {
                j++;
            }
            ans += (j - (mid + 1));
        }
    }
    void merge(vector<int> &nums, int low, int mid, int high) {
        int n1 = mid - low + 1;
        int n2 = high - mid;
        vector<long long> left(n1), right(n2);
        for (int i = 0; i < n1; i++) {
            left[i] = nums[low + i];
        }
        for (int i = 0; i < n2; i++) {
            right[i] = nums[mid + i + 1];
        }
        int i = 0, j = 0, k = low;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                nums[k] = left[i];
                i++;
            } else {
                nums[k] = right[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            nums[k] = left[i];
            i++;
            k++;
        }
        while (j < n2) {
            nums[k] = right[j];
            j++;
            k++;
        }
    }
    void mergeSort(vector<int> &nums, int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            mergeSort(nums, low, mid);
            mergeSort(nums, mid + 1, high);
            countPairs(nums, low, mid, high);
            merge(nums, low, mid, high);
        }
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return ans;
    }
};