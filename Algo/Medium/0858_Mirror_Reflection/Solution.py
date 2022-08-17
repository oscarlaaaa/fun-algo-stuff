## 2022-08-16
class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:
        on_left_edge = True
        cur_height = 0
        upwards = True
        
        prev_position = [set(), set()]

        while True:
            ## bounce to opposite side (left <-> right)
            if upwards:
                cur_height += q
                if cur_height > p:
                    cur_height = 2*p - cur_height
                    upwards = False
            else:
                cur_height -= q
                if cur_height < 0:
                    cur_height = -cur_height
                    upwards = True
            on_left_edge = not on_left_edge
            
            ## prevent infinites
            if on_left_edge and cur_height in prev_position[0] or not on_left_edge and cur_height in prev_position[1]:
                break;
            prev_position[0 if on_left_edge else 1].add(cur_height)
            
            ## hit a receptor
            if cur_height == p:
                return 2 if on_left_edge else 1
            if cur_height == 0 and not on_left_edge:
                return 0
        
        return -1
        