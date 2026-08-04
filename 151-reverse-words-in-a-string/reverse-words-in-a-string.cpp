class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";
        int n = s.size();
        for(int i=n-1;i>=0;i--){
            while(s[i]==' '&& i>0){
                if(temp.size()>0){
                    reverse(temp.begin(), temp.end());
                    ans+=temp+' ';
                    temp.clear();
                }
                i--;
            }
            if(s[i]!= ' '){
                temp.push_back(s[i]);
            }
        }
        if(temp.size()>0){
            reverse(temp.begin(), temp.end());
            ans+= temp;
            return ans;
        }
        return ans.substr(0, ans.size()-1);
    }
};