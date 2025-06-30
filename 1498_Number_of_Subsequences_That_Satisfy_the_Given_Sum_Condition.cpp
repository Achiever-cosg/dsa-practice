/** 1498. Number of Subsequences That Satisfy the Given Sum Condition */

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mod = 1e9+7;

        int left = 0, right = n-1;
        int maxCnt = 0;

        // pre-compute the power of 2 to prevent he 
        // overflow of shifting indices
        vector<int> power(n, 1);
        for(int i=1; i<n; i++)
        {
            power[i] = (power[i-1] * 2)%mod;
        }

        while(left <= right)
        {
            if(nums[left] + nums[right] <= target)
            {
                int tempCnt = power[right-left];
                maxCnt = (maxCnt + tempCnt % mod) % mod;
                left++;
            } else {
                right--;
            }
        }

        return maxCnt;
    }
};

// O(NlogN), O(N)