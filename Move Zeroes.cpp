class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>::iterator it = nums.begin();
        int count = 1;
        while(it != nums.end()) {
            if(count == nums.size()) break;
            if(*it == 0) {
                nums.erase(it);
                nums.push_back(0);
            }
            else it++;
            count++;
        }
    }
};