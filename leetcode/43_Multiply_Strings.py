class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        list_str = ["0","1","2","3","4","5","6","7","8","9"]

		# initialize int
        new_num1 =0
        new_num2 = 0

		# if 0 then 0
        if num1 == "0" or num2 == "0":
            return "0"

		# convert to int method
        def make_num(x) -> int:
            ''' convert str -> num'''
            y=0
            for i in x:
                ind = list_str.index(i)
                y= y*10 + ind
            return y

		# converted to int
        new_num1 = make_num(num1)
        new_num2 = make_num(num2)

		# num3 - result of product
        num3 = new_num1*new_num2


        num_str = []

        while num3!=0:
			# append num_str by finding num3 in list
            num_str.append(list_str[num3 % 10])
			# reduce num 3
            num3=num3 // 10
			
		# append it inversely 
        a = "".join(num_str[::-1])

        return a
