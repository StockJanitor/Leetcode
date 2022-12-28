# Constraints:

# -100.0 < x < 100.0
# -231 <= n <= 231-1
# n is an integer.
# -104 <= xn <= 104

# recusion
def myPow(self, x: float, n: int) -> float:
    if x ==0:
        return 0
    if n == 0:
        return 1
    if n <0:
        n *= -1
        x = 1/x

    return self.myPow(x*x,n//2) if n%2==0 else x*self.myPow(x*x,n//2)




# # Binary method
# def myPow(self, x: float, n: int) -> float:
#     if n < 0:
#         x = 1/x
#         n *=-1

#     output = 1
#     while n:
#         # read current binary, if 1 then multiply
#         if n&1:
#             output *=x

#         # move to next binary    
#         n>>=1

#         x*=x
#     return output