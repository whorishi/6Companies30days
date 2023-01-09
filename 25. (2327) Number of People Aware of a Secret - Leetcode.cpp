/*
On day 1, one person discovers a secret.

You are given an integer delay, which means that each person will share the secret with a new person every day, starting from delay days after discovering the secret. You are also given an integer forget, which means that each person will forget the secret forget days after discovering it. A person cannot share the secret on the same day they forgot it, or on any day afterwards.

Given an integer n, return the number of people who know the secret at the end of day n. Since the answer may be very large, return it modulo 109 + 7.
*/

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long>days(1001,0);
        days[1]=1;
        int sharing=0;
        int sum=0;
        int mod=1e9+7;
        for(int i=2;i<=n;i++)
        {
            sharing = (sharing + days[max(i - delay, 0)] - days[max(i - forget, 0)] +mod)%mod;
            days[i]=sharing;
        }
        for(int i=n-forget+1;i<=n;i++)
        {
            sum = (sum%mod + days[i]%mod)%mod;
        }
        return sum;
    }
}
