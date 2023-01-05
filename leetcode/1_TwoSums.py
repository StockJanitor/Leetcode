class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:

        # initiate dictionary
        values = dict()

        # return index and value of list
        for index, value in enumerate(nums):
            
            # diff between target and value
            diff = target - value

            # check diff in values, if true, return index of the diff and current index
            if diff in values:
                return [values[diff], index]
            
            # if not in dic, append current value and assign current index
            values[value] = index
        return []

        