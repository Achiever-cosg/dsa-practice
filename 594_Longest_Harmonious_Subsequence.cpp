/** 594. Longest Harmonious Subsequence */

/** 1. Sorting */ 

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i=0;
        int maxCnt = 0;
        
        for(int j=0; j<n; j++)
        {
            while(nums[j] - nums[i] > 1)
                i++;
            
            if(nums[j] - nums[i] == 1)
                maxCnt = max(maxCnt, j-i+1);
        }

        return maxCnt;
    }
};

// O(NlogN), O(1)

/** 2. HashMap */

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int i: nums)
            mpp[i]++;

        int maxCnt = 0;
        for(auto it: mpp)
        {
            if(mpp.find(it.first+1) != mpp.end())
            {
                int currCnt = it.second + mpp[it.first+1];
                maxCnt = max(maxCnt, currCnt);
            }
        } 

        return maxCnt;
    }
};

// O(N), O(N)