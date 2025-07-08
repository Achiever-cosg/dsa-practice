/** 2348. Number of Zero-Filled Subarrays */

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;

        long long totalCount = 0;
        int contCount = 0; // continuous sub-array count
        
        for(int i=0; i<n; i++)
        {
            if(nums[i] == 0)
            {
                contCount++;
                totalCount += contCount;
            }
            else 
                contCount = 0;
        }

        return totalCount;
    }
};

// O(N), O(1)