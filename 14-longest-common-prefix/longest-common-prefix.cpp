class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = INT_MAX;

        for (int i = 0; i < strs.size(); i++) {
            n = min(n, (int)strs[i].size());
        }

        string ans = "";
        for (int i = 0; i < n; i++) {
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != ch) {
                    return ans;
                }
            }
            ans.push_back(ch);
        }

        return ans;
    }
};