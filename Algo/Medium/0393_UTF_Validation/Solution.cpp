// 2022-09-12
class Solution {
public:
    // reduces each integer to 8 bits
    void cleanData(vector<int>& data) {
        for (int i=0; i<data.size(); i++) {
            data[i] = data[i] & 0b11111111;
        }
    }
    
    bool validUtf8(vector<int>& data) {
        cleanData(data);
        
        int pointer = 0, n = data.size();
        while (pointer < n) {
            int firstBit = data[pointer++];
            
            // determine # of bytes in the char
            int numOfBytes;
            if (firstBit >> 7 == 0) {
                numOfBytes = 0;
            } else if (firstBit >> 5 == 0b110) {
                numOfBytes = 1;
            } else if (firstBit >> 4 == 0b1110) {
                numOfBytes = 2;
            } else if (firstBit >> 3 == 0b11110) {
                numOfBytes = 3;
            } else {
                // invalid first bit
                return false;
            }
            
            // check that the remaining bytes in the char are valid
            while (numOfBytes > 0 && pointer < n) {
                if (data[pointer++] >> 6 != 0b10)
                    return false;
                numOfBytes--;
            }
            
            if (numOfBytes > 0) return false;
        }
        
        return true;
    }
};