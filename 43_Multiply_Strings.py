class Solution:
	def multiply(self, num1: str, num2: str) -> str:
		list_str = ["0","1","2","3","4","5","6","7","8","9"]
		
		
		new_num1 =0
		new_num2=0
		
		def make_num(x,y)
			for i in x:
				ind = list_str.index(i)
				y= y*10 + ind
			return y
		make_num(num1,new_num1)
		make_num(num2,new_num2)
		
		num3 = num1*num2
		