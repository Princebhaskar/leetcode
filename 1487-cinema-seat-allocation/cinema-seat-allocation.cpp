class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& r) {
        unordered_map<int,vector<int>>mp;
        for(auto it:r ){
            int row = it[0];
            int booked = it[1];
            mp[row].push_back(booked);
        }
        int cnt =0;
        int x = mp.size();
        cnt += 2*(n-x);
        for(auto it: mp){
               bool left = true;
               bool mid = true;
               bool right = true;
               for(auto itr: it.second){
                    if(itr<=5 && itr >=2)left=false;
                    if(itr<=7&&itr>=4)mid=false;
                    if(itr<=9 && itr>=6)right=false;
               }
               if(left && right)cnt+=2;
               else if(left || right || mid)cnt+=1;
               else cnt+=0;
        }
        return cnt;
    }
};