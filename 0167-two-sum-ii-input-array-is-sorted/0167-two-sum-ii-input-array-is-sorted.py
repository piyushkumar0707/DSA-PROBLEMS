class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        n=len(numbers)
        dict1={}
        for i in range(n):
            rem=target-numbers[i]
            if rem in dict1:
                return [dict1[rem]+1,i+1]
            dict1[numbers[i]]=i