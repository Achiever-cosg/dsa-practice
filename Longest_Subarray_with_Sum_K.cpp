/** Longest Subarray with Sum K - GFG */

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int, int> mpp;
        
        int sum = 0;
        int maxLen = 0;
        for(int i=0; i<n; i++)
        {
            sum += arr[i];
            if(sum == k)
                maxLen = i+1;
            
            // store the encountered sum if theu don;t exist
            if(mpp.find(sum) == mpp.end())
                mpp[sum] = i;
            
            // check for currSum - k diff, if present or not
            if(mpp.find(sum - k) != mpp.end())
                maxLen = max(maxLen, i - mpp[sum - k]);
        }
        
        return maxLen;
    }
};

// O(N), O(N)