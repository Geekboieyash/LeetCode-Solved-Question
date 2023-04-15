class Solution {
public:

    bool canJump(vector<int>& nums) {
        int maxReachablePosition = 0;
        for(int i=0;i<nums.size();i++){
            if(maxReachablePosition < i)
                return false;
            maxReachablePosition = max(maxReachablePosition, i+nums[i]);
      
            if(maxReachablePosition > nums.size() - 2)
                return true;
        }
        return true;
    }
};