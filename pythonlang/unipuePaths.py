class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        whole = m + n - 2
        smaller = min(m,n) - 1
        res = 1
        i = 1
        while(i <= smaller):
            res = res * (whole - smaller + i) // i
            i += 1
        return res
            