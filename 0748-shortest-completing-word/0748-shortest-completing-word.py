class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        # Count required letters
        need = Counter(c.lower() for c in licensePlate if c.isalpha())
        
        res = ""
        
        for word in words:
            count = Counter(word)
            
            if all(count[c] >= need[c] for c in need):
                if res == "" or len(word) < len(res):
                    res = word
        
        return res