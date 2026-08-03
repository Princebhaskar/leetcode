class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long A = a;
        long long B = b;
        long long C = c;

        long long ab = lcm(A,B);
        long long bc = lcm(B,C);
        long long ac = lcm(A,C);
        long long abc = lcm(ab, C);

        long long low = 1;
        long long high = INT_MAX;
        long long ans = high;

        while(low <= high){
            long long mid  = low + (high-low)/2;
            long long cnt = mid/A + mid/B + mid/C -mid/ab -mid/ac -mid/bc + mid/abc;

            if(cnt >= n){
                ans =mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return (int)ans;
    }
};