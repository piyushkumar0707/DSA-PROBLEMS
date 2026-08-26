class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        n=len(nums)
        start=0
        for i in range(n):
            if nums[i]%2==0:
                temp=nums[i]
                nums[i]=nums[start]
                nums[start]=temp

                start+=1
        return nums