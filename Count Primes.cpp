class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        bool arr[n];
        memset(arr, 1, n * sizeof(bool));
        for (int i = 2; i <= (int)sqrt(n); ++i) {
            if (arr[i]) {
                for (int j = 2 * i; j < n; j += i) {
                    arr[j] = false;
                }
            }
        }
        int k = 0;
        for (int i = 2; i < n; ++i) {
            k = arr[i] ? k + 1 : k;
        }
        return k;
    }
};