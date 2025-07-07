/** 567. Permutation in String */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0, right = 0;
        sort(s1.begin(), s1.end());
        deque<char> tempStr;

        while(right < s2.length())
        {
            tempStr.push_back(s2[right]);
            if(right-left+1 == s1.length())
            {
                string temp = "";
                for(auto c: tempStr)
                    temp += c;

                sort(temp.begin(), temp.end());
                if(temp == s1)
                    return true;
                
                tempStr.pop_front();
                left++;
            }
            right++;
        }

        return false;
    }
}; 

// O(nlogN), O(1)

class Solution {
private:
    bool areEqual(vector<int>& v, vector<int>& v2)
    {
        for(int i=0; i<26; i++)
        {
            if(v[i] != v2[i])
                return false;
        }

        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int left = 0, right = 0;
        vector<int> v(27, 0);
        for(auto c: s1)
            v[c-'a']++;

        vector<int> v2(27, 0);

        while(right < s2.length())
        {
            v2[s2[right]-'a']++;
            if(right-left+1 == s1.length())
            {
                if(areEqual(v, v2))
                    return true;

                v2[s2[left]-'a']--;
                left++;
            }
            right++;
        }

        return false;
    }
};

// O(N), O(N)