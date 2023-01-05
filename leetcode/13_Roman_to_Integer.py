class Solution:
    def romanToInt(s: str) -> int:
        guide = {'I': 1, 'IV': 4, 'V': 5, 'IX': 9, 'X': 10, 'XL': 40, 'L': 50, 'XC': 90, 'C': 100, 'CD': 400, 'D': 500, 'CM': 900, 'M': 1000}
        
        s = [s for s in s][::-1]
        
        res = 0

        while len(s) != 0:
        
            if len(s) != 1:
                if guide[s[1]] < guide[s[0]]:
                    res += guide[s[1]+s[0]]
                    s.remove(s[1])
                    s.remove(s[0])
                else:
                    res+=guide[s[0]]
                    s.remove(s[0])
            else:
                res+=guide[s[0]]
                s.remove(s[0])
        

        return res