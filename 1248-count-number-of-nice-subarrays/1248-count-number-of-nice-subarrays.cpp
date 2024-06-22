class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++)
        {
            nums[i] %= 2;
        }
        vector<int> pre(nums.size()+1);
        pre[0] = 1;
        int s=0, res=0;
        for(int i = 0; i < nums.size(); i++) {
            s += nums[i];
            res += (s>=k)?pre[s-k]:0;
            pre[s]++;
        }
        return res;
    }
};