class Solution:
    def firstUniqChar(self, s: str) -> int:
        freq={}
        for i in s:
            if i not in freq:
                freq[i]=1
            else:
                freq[i]+=1
        for i in range (len(s)):
            if freq[s[i]]==1:
                return i
        return -1 
        