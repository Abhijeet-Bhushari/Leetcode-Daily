class Solution
{
    public:
        int calc(int n, int m)
        {
            int l = 1, r = m - 1;
            int a = ceil((double) n / m);
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (a *mid + (n / m) *(m - mid) == n)
                {
                    l = mid;
                    break;
                }
                else if (a *mid + (n / m) *(m - mid) > n) r = mid - 1;
                else l = mid + 1;
            }
            int ans = pow(a, l) *pow(n / m, m - l);
            return ans;
        }
    int integerBreak(int n)
    {
        int l = 2, r = n / 2;
        while (l <= r)
        {
            int m = (l + r) / 2;
            int low = m - 1, high = m + 1;
            cout<<m<<endl;
            int prod1 = calc(n, m), prod2 = calc(n, low), prod3 = calc(n, high);
            if (prod1 >= prod2 && prod1 >= prod3) return prod1;
            else if (prod1 < prod2)
            {
                r = m - 1;
            }
            else l = m + 1;
        }
        int ans = calc(n, l);
        return ans;
    }
};