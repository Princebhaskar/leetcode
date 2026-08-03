class Solution {
public:
    int minDeletions(string s) {
        vector<int>freq(26,0);
        for(auto it: s){
            freq[it-'a']++;
        }
        unordered_set<int>st;
        int cnt =0;
        for(int i=0;i<26;i++){
            while(freq[i]>0 && st.find(freq[i])!= st.end()){
                freq[i]--;
                cnt++;
            }
            if(freq[i]>0){
                st.insert(freq[i]);
            }
        }
        return cnt;
    }
};