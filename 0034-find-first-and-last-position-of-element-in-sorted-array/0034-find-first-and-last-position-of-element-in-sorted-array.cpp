class Solution {
public:
    int first(vector<int>& arr, int n, int k){
        int low = 0, high = n-1;
        int first = -1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(arr[mid] == k){
                first = mid;
                high = mid-1;
            }
            else if(arr[mid] < k) low = mid+1;
            else high = mid-1;
        }
        return first;
    }

    int last(vector<int>& arr, int n, int k){
        int low = 0, high = n-1;
        int last = -1;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(arr[mid] == k){
                last = mid;
                low = mid+1;
            }
            else if(arr[mid] < k) low = mid+1;
            else high = mid-1;
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int f = first(nums, nums.size(), target);
        if(f == -1) return vector<int>{-1,-1};
        int l = last(nums, nums.size(), target);
        return vector<int>{f, l};
    }

};