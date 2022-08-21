class Solution:
	def divide(self, dividend: int, divisor: int) -> int:
		sign = 1
		if dividend < 0:
			sign *= -1
		if divisor <0:
			sign *= -1
		
		abs(dividend)
		abs(divisor)
			
		mod =0
		while dividend > divisor:
			dividend -= divisor
			mod += 1
		return mod*sign
		