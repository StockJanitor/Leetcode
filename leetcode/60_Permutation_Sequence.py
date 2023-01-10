import math


class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        
        # list of numbers
        nums = [i for i in range(1,n+1)]

        # factorial, number of permutations
        factorial = math.factorial(n)
        
        # finding the index
        index = k-1


        output = []


        while (nums):
            # getting previous factorial number
            factorial = factorial// len(nums)

            # finding the actual index/position
            position = index // factorial

            # pop off the number in the index/position
            number = nums.pop(position)

            # append to result
            output.append(number)

            # update the index
            index = index%factorial

        return "".join(output)


