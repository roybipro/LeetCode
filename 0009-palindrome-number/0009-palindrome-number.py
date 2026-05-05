class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            return False


        num = x
        result = 0
        while num > 0:
            ld = num % 10
            result = (result*10)+ld
            num = num//10
        return x == result 