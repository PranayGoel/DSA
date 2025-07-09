class Solution {
public:
    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low, right = mid + 1;

        // Merge two sorted halves
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }

        // Copy remaining elements
        while (left <= mid) temp.push_back(arr[left++]);
        while (right <= high) temp.push_back(arr[right++]);

        // Copy back to original array
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    void count_pairs(vector<int>& arr, int low, int mid, int high, int& count) {
        int right = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (right <= high && (long long)arr[i] > 2LL * arr[right]) {
                right++;
            }
            count += (right - (mid + 1));
        }
    }

    void mergeSort(vector<int>& arr, int low, int high, int& count) {
        if (low >= high) return;

        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid, count);
        mergeSort(arr, mid + 1, high, count);
        count_pairs(arr, low, mid, high, count);
        merge(arr, low, mid, high);

    }

    int reversePairs(vector<int>& nums) {
        int count = 0;
        mergeSort(nums, 0, nums.size() - 1, count);
        return count;
    }
};
