class Solution {//heap
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        if(pq.empty()) return 0;
        for(int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};

class Solution {//quick sort
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSort(nums, nums.size() - k, 0, nums.size() - 1);
    }
    
    int quickSort(vector<int>& nums, int k, int left, int right) {
        if(k >= left && k <= right) {
            int pos = partition(nums, left, right);
            if(pos == k) return nums[pos];
            else if(pos > k) {
                return quickSort(nums, k, left, pos - 1);
            }
            else {
                return quickSort(nums, k, pos + 1, right);
            }
        }
        return INT_MIN;
    }
    
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], j = left + 1;
        for(int i = left + 1; i <= right; i++) {
            if(nums[i] < pivot) {
                swap(nums, i, j);
                j++;
            }
        }
        swap(nums, left, j - 1);
        return j - 1;
    }
    
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};

class Solution {//k-size heap
public:
    void adjustHeap(vector<int>& nums, int k, int i) {
        int left = i * 2 + 1;
        int right = left + 1;
        int minV = nums[i], minI = i;
        if(left < k && nums[left] < minV) {
            minV = nums[left];
            minI = left;
        }
        if(right < k && nums[right] < minV) {
            minV = nums[right];
            minI = right;
        }
        if(minI != i) {
            swap(nums[minI], nums[i]);//nums[minI] instead of minV
            adjustHeap(nums, k, minI);
        }
    }
    
    void buildHeap(vector<int>& nums, int k) {
        int i = k / 2 - 1;
        for(int j = i; j >= 0; j--) {
            adjustHeap(nums, k, j);//j instead of i
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty()) return -1;
        buildHeap(nums, k);
        for(int i = k; i < nums.size(); i++) {
            if(nums[i] > nums[0]) {
                swap(nums[i], nums[0]);
                adjustHeap(nums, k, 0);
            }
        }
        return nums[0];
    }
};
