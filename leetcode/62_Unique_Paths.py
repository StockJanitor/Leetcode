class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # creating matrix of 
        dp = [[1]*m]*n

        # start from 1,1
        for row in range(1, n):
            for col in range(1,m):
                # value = up box + left box
                dp[row][col] = dp[row-1][col] + dp[row][col-1]

        return dp[n-1][m-1]


        # another way
    # def uniquePaths(self , m: int, n: int):
    #     last = [0,1] + [0] * (n-1)
    #     for i in range(m):
    #         print(i,"this is i")
    #         for j in range(1,n+1):
    #             last[j] += last[j-1]
    #             print(last[j])
