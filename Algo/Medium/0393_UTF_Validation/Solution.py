from typing import *

## 2022-08-30
class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        data = [d&0b11111111 for d in data]
        i = 0
        while i < len(data):
            bytes_to_check = 0

            if data[i] & 0b10000000 == 0: # 1 byte
                bytes_to_check = 0
            elif data[i] >> 3 == 0b11110: # 4 byte
                bytes_to_check = 3
            elif data[i] >> 4 == 0b1110: # 3 byte
                bytes_to_check = 2
            elif data[i] >> 5 == 0b110: # 2 byte
                bytes_to_check = 1
            else: # invalid
                return False

            ## checking the rest of the bytes in the character
            while i+1 < len(data) and bytes_to_check > 0:
                i += 1
                bytes_to_check -= 1
                if data[i] >> 6 != 0b10: ## checks that the byte starts wtih 10
                    return False

            if bytes_to_check > 0:
                return False

            i += 1

        return True