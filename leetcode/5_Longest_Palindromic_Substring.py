class Solution:
    def longestPalindrome(self, s: str) -> str:

        #get length of s
        N = len(s)

        # two pointer left l, and right r
        def LP(l,r):
            
            # loop if l is more than 0, r is less than length
            while r < N and l >=0:

                # if within string, check if palindromic, if not break
                if s[r] != s[l]: break
                    
                #if palindromic, we add r and minus l    
                r +=1
                l -=1
                
            # l must +1, we dont want negative
            return l+1,r
            
        start,end = 0,0

        for i in range(N):
            # check every i, starts from middle and expand
            l,r=LP(i,i)
            
            if (r-l) > (end-start):
                end = r
                start = l
            l,r=LP(i,i+1)
            if (r-l) > (end-start):
                end = r
                start = l
                
        return s[start:end]

'''
Slower version

class Solution:
    def longestPalindrome(self, s: str) -> str:
        

        res = ""
        resLen = 0
        
        # loop each char
        for i in range(len(s)):
            l,r=i,i
            
            # if left l > 0, right r <len, and l=r, then its palindrom
            while l >=0 and r<len(s) and s[l]==s[r]:
                
                # if r-1+1 > current longest length, we update it.
                if (r-l+1)>resLen:
                    res=s[l:r+1]
                    resLen=r-l+1
                
                # increment it
                l-=1
                r+=1
        
        # same thing for even, just +1
        for i in range(len(s)):
            l,r=i,i+1
            while l >=0 and r<len(s) and s[l]==s[r]:
                if (r-l+1)>resLen:
                    res=s[l:r+1]
                    resLen=r-l+1
                l-=1
                r+=1
        
        # return the result
        return res
'''