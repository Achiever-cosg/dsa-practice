class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString = "";

        for(string str: strs)
        {
            int len = str.length();
            string delimiter = to_string(len) + "#";
            encodedString = encodedString + delimiter + str;
        }

        return encodedString;
    }

    vector<string> decode(string s) {
        vector<string> decodedString;

        int i=0;        
        while(i < s.length())
        {
            string len = "", currWord = "";
            while(s[i] != '#') {
                len += s[i];
                i++;
            }
            i++;

            int currLen = stoi(len);
            for(int j=i; j<i+currLen; j++) {
                currWord += s[j];
            }
            i += currLen;

            decodedString.push_back(currWord);
        }

        return decodedString;
    }
};

// use delimiter as 'length of current string and #'.
// O(m+n), O(m+n)
