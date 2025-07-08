/** Longest Substring Without Repeating Characters */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n =s.length();
        unordered_map<char, int> mpp;
        int left = 0, right = 0;

        int maxLen = 0;

        while(right < n)
        {
            if(mpp.find(s[right]) != mpp.end())
            {
                left = max(mpp[s[right]]+1, left);
            }

            mpp[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);

            right++;
        }

        return maxLen;
    }
};

// O(N), O(N)