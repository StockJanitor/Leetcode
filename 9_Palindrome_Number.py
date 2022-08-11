class Solution:
    def isPalindrome(self, x: int) -> bool:

        
        if (x <0) or (x > 2147483647):
            return False
        
        # find out size of x
        div = 1 
        while x >= 10 * div:
            div *=10
            
            
        # num % 10, gets the right number removes left number,, 
        # num // 10 gets the left number, removes right number,,
        while x:
            right = x % 10
            left = x // div
            
            if left != right: return False
            
            # x % div gets right number, obtain rest of the right numbers
            # // 10 gets left number, removes the right number
            x = (x%div) // 10
            
            # since we removed 2 digit spots, increment div / 100
            div /= 100
            
            
        return True

'''

class Solution:
    def isPalindrome(self, x: int) -> bool:
        return str(x) == str(x)[::-1]

'''