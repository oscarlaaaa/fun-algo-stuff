from typing import *

## 2022-08-16
class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        morse = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        
        seen = set()
        for word in words:
            rep = []
            for c in word:
                rep.append(morse[ord(c) - ord('a')])
            seen.add("".join(rep))
        
        return len(seen)