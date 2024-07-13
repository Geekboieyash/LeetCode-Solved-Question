class Solution {
public:
    int calc(vector<int>& bits, int len, int k, int m) {            // Utilizing a greedy exit, we can
        for (int bit = m - 1, val = 0; ~bit; bit--)                 //   calculate how the window's
            if (bits[bit] > len) {                                  //   AND value compares to k:
                if ((val |= 1 << bit) > k)
                    return 1;                                       //      1: larger
            } else if (val < k - (k % (1 << bit)))
                return -1;                                          //     -1: smaller
        return 0;                                                   //      0: equal to
    }
    
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int m = 1+log2(*max_element(nums.begin(), nums.end()));     // Calculate the number of bits needed
        long ans(0);
        vector<int> maxBits(m), minBits(m);;
        for(int a=0, b=0, c=0; c<n;c++)                             // 3 pointer approach
        {
            if(nums[c] < k)                                         // Quick reset to 0 if there are no possible good subarray up to c
            {
                fill(minBits.begin(), minBits.end(), 0);
                fill(maxBits.begin(), maxBits.end(), 0);
                a = b = c+1;
                continue;
            }
            for (int x = nums[c], bit = 0; x; x >>= 1, bit++)       // We can use an early exit when updating our bitmaps
                minBits[bit] += x & 1, maxBits[bit] += x & 1;        
            while (calc(minBits, c - a, k, m) < 0)                  // Move a up to lower lower bound
                for (int x = nums[a++], bit = 0; x; x >>= 1, bit++)
                    minBits[bit] -= x & 1;
            if (nums[c] == k) {                                     // Quick shortcut to reset b to 0
                fill(maxBits.begin(), maxBits.end(), 0);            //   if it's going to anyway
                b = c + 1, ans += c - a + 1;
                continue;
            }
            if (b < a)                                              // Shortcut b to a before moving up
                maxBits = minBits, b = a;
            while (!calc(maxBits, c - b, k, m))                     // Move b up to upper lower bound
                for (int x = nums[b++], bit = 0; x; x >>= 1, bit++)
                    maxBits[bit] -= x & 1;
            ans += b - a;                          
        }
        return ans;
        
    }   
};