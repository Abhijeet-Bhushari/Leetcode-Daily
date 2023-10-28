class Solution {
public:
    int countVowelPermutation(int n) {
        long long mod = 1000000007;    
        long long a = 1, e = 1, i = 1, o = 1, u = 1;
        long long a_next, e_next, i_next, o_next, u_next; 
        for(int k=1; k<n; k++){
            a_next = e + i + u;
            e_next = a + i;
            i_next = e + o;
            o_next = i;
            u_next = o + i;
            a = a_next%mod, e = e_next%mod, i = i_next%mod, o = o_next%mod, u = u_next%mod;
        }
        return (a + e + i + o + u) % mod;
    }
};