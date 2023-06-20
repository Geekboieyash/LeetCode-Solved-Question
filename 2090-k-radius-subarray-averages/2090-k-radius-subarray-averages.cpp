class Solution {
public:
   
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        if(k >= n) ans;
        int p = 2*k+1;
        vector<long long> pre(n+1);
        
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + nums[i];
        }
        
        for(int i=k; i+k < n; i++)
        {
            ans[i] = (pre[i+k+1] - pre[i-k])/p;
        }
        return ans;
    }
};