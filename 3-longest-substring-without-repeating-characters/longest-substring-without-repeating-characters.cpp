class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int>st;
        int len = 0;
        int n=s.size();
        int j =0;
        for(int i=0;i<n;i++){
            while(st.count(s[i])){
                st.erase(s[j]);
                j++;
            }
            st.insert(s[i]);
            len = max(len , i-j+1);
        }
        return len;
    }
};