class Solution:
    def sortVowels(self, s: str) -> str:
        vowels = set("aeiouAEIOU")
        
        # Extract and sort vowels by ASCII
        extracted = sorted([ch for ch in s if ch in vowels])
        
        # Iterator over sorted vowels
        it = iter(extracted)
        
        # Build result
        result = []
        for ch in s:
            if ch in vowels:
                result.append(next(it))
            else:
                result.append(ch)
        
        return "".join(result)
