/** 3330. Find the Original Typed String I */

class Solution {
public:
    int possibleStringCount(string word) {
        if(word.length() == 0)
            return 0;

        int cnt = 1;
        for(int i=1; i<word.length(); i++)
        {
            if(word[i] == word[i-1])
                cnt++;
        }

        return cnt;
    }
};

// O(N), O(1)