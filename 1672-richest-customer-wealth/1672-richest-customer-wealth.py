class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        ans=0
        for account in accounts:
            ans=max(ans,sum(account))
        return ans