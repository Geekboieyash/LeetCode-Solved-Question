class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int x = nums[n-1];
        int y = (k*(k-1))/2;
        return x*k+y;
        
    }
};