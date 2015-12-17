class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), max = 0, vol, left = 0, right = n - 1;
        while(left < right) {
            if(height[left] > height[right]) {
                vol = height[right] * (right - left);
                if(vol > max) max = vol;
                right--;
            }
            else {
                vol = height[left] * (right - left);
                if(vol > max) max = vol;
                left++;
            }
        }
        return max;
    }
};