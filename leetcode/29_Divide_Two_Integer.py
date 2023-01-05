class Solution:
	def divide(self, dividend: int, divisor: int) -> int:
		sign = 1
		if dividend < 0:
			sign *= -1
		if divisor <0:
			sign *= -1
		
		dividend=abs(dividend)
		divisor=abs(divisor)

		output = 0
        
		while dividend >= divisor:
			
			# increment divisor variable
			temp = divisor

			# mod variable
			mod = 1

			# dividend must be compare to temp now, the new divisor
			while dividend >= temp:

				# dividend - temp, decrease by current divisor variable 
				dividend -= temp

				# output increase by current mod number
				output += mod

				# increase mod by 1
				mod += mod

				# increase divisor variable by 1
				temp += temp

		
		return min(max(output*sign,-2147483648),2147483647)
		