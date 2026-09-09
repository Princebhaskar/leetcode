class Solution {
public:
    int minimumSwap(string s1, string s2) {
        vector<int>f(26,0);
        for(char c:s1)f[c-'a']++;
        for(char c:s2)f[c-'a']++;
        for(int i=0;i<26;i++)if(f[i]&1)return -1;
        int res = 0 ;
        int n=s1.size();
        
        // vector<int>f1(2, 0) , f2(2, 0) ;
        for(int i=0;i<n;i++){
            if(s1[i]==s2[i])continue;
            for(int j=i+1;j<n;j++){
                if(s1[j]==s2[j])continue;
                if(s1[i]==s1[j]){
                    res++;
                    swap(s1[j], s2[i]);
                    break;
                }
            }
            if(s1[i]==s2[i])continue;
            for(int j=i+1;j<n;j++){
                if(s1[j]==s2[j]) continue;
                if(s1[i]==s2[j]){
                    res+=2;
                    swap(s2[j], s2[i]);
                    break;
                }
            }
        }

        return res ;
    }
};