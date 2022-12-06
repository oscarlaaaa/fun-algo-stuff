## 2022-12-03
class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        """
        input: a string sentence
        output: whether it is a circular sentence

        notes:
        - circular if the last letter of each word matches the first letter of the next word
        - circles around from lastidx to 0

        approach:
        - split into a list; delimiter " "
        - append the first word to the end
        - loop through and check words[i][-1] == words[i+1][0]
            - return false if not
        - return true at the end
        """
        words = sentence.split(" ")
        words.append(words[0])
        
        for i in range(len(words)-1):
            if words[i][-1] != words[i+1][0]:
                return False
        
        return True