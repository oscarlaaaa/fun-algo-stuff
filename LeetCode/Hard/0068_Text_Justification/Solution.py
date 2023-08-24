## 2023-08-23
class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        """
        notes:
        - add words into a 2d list until list[i][j] hits the max char limit 
          (len(list[i])-1 + total chars <= maxWidth)
        - process words one by one and add spaces after
            - skip processing last word and have separate logic bc it never has spaces
              after it
            - same with last line bc it's only left justified
        - # of spaces after each word would be:
            - # spaces available // number of words-1
            - if we can't split it evenly, +1
        
        analysis:
        - time = O(n)
        - space = O(n)
        """
        packs = [[]]
        line_chars = [0]
        for word in words:
            if line_chars[-1] + len(word) + len(packs[-1]) > maxWidth:
                packs.append([])
                line_chars.append(0)
            
            packs[-1].append(word)
            line_chars[-1] += len(word)
        
        output = []
        for pack, line_char in zip(packs[:-1], line_chars[:-1]):
            output.append("")
            spaces = maxWidth - line_char

            if len(pack) == 1:
                output[-1] += pack[0] + " "*spaces
                continue

            n = len(pack)-1
            for word in pack[:-1]:
                spaces_to_add = spaces//n + (1 if spaces%n > 0 else 0)
                output[-1] += word + (" "*spaces_to_add)
                spaces -= (1 if spaces%n > 0 else 0)
            output[-1] += pack[-1]
        
        last_line = " ".join(packs[-1])
        last_line += " "*(maxWidth-len(last_line))
        output.append(last_line)
        return output
