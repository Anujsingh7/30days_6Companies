class Solution {
public:
    int minimizeSet(long long d1, long long d2, long long x, long long y) {
       long long l=x+y;
       long long r=2*l;
       long long lcm=(d1*d2)/__gcd(d1,d2);
       long long total=x+y;
       long long ans=0;
       while(l<=r)
       {
             long long mid = (l + r) / 2;
            long long both = mid / lcm;
            long long onlyA = mid / d2 - both;
            long long onlyB = mid / d1 - both;
            total = max(0ll, x - onlyA) + max(0ll, y - onlyB);
            if (mid - onlyA - onlyB-both >= total)
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
       return ans;
    }
};