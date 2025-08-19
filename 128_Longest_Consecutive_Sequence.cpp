class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for(int num: nums) {
            st.insert(num);
        }

        int maxLen = 0;
        for(int num: nums)
        {
            if(st.find(num-1) == st.end())
            {
                int currLen = 1;
                int currNum = num;
                while(st.find(currNum + 1) != st.end()) {
                    currNum++;
                    currLen++;
                }

                maxLen = max(maxLen, currLen);
            }
        }

        return maxLen;
    }
};

/*

    Time Complexity : O(N), Although the time complexity appears to be quadratic due to the while loop nested
    within the for loop, closer inspection reveals it to be linear. Because the while loop is reached only when
    marks the beginning of a sequence (i.e. currentNumber-1 is not present in nums), the while loop can only run
    for N iterations throughout the entire runtime of the algorithm. This means that despite looking like O(N^2)
    complexity, the nested loops actually run in O(N+N)=O(N) time. All other        computations occur in constant
    time, so the overall runtime is linear. Where N is the size of the Array(nums).

    Space Complexity : O(N), Unordered set space.

    Solved using Array + Hash Table(Unordered set). Optimise Approach.

*/
