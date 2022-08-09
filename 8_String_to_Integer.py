class Solution:
    def myAtoi(self, s: str) -> int:
        '''
        
        1. whitespace
        2. +/- symbol
        3. numbers
        4. between max and min
        5. random characters
        
        '''
        
        MAX = 2**31 - 1
        MIN = -2**31
        
        # strip whitespace
        s = s.lstrip()
        
        # if string empty return 0
        if not s:
            return 0 
        
        # index pointer
        i = 0
        
        # sign/symbol
        sign = 1
        
        # check sign
        if s[i] =="+":
            i +=1
        elif s[i]=="-":
            i +=1
            sign = -1
            
        # Parsed item
        parsed = 0    
        
        # loop the item
        while i < len(s):
            # current item
            current_i=s[i]
            
            # if not num, break
            if not current_i.isdigit():
                break
            
            # else we parse it
            else:
                # this will run if there is num remaining, if not then it wont run.
                
                # if parsed number is greater than the MAX, return max if positive, else min
                if (parsed > MAX // 10) or (parsed == MAX // 10 and int(current_i) > MAX % 10):
                    # returns max if positive, if over 2147483647, it will return MIN which includes -214748647
                    return MAX if sign == 1 else MIN
                
                # parsed item * 10 + next item
                parsed = parsed * 10 + int(current_i)
        
            #increase pointer
            i+=1
            
        # finally return the item with the correct sign
        return parsed * sign