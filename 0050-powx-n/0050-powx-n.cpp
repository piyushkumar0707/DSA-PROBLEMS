class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;

        long long N = n; // Use long long to avoid overflow when n = INT_MIN
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return fastPow(x, N);
    }

private:
    double fastPow(double x, long long n) {
        if (n == 0) return 1.0;
        double half = fastPow(x, n / 2);
        if (n % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }
};