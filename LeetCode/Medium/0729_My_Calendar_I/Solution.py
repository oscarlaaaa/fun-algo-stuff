## 2022-08-16 (linkedlist imp)
class MyCalendar:
    ## linkedlist impl of a booking
    class Booking:
        def __init__(self, start, end):
            self.start = start
            self.end = end
            self.next = None
            
    def __init__(self):
        self.bookings = None

    def book(self, start: int, end: int) -> bool:
        ## finding insertion location for booking
        prev, cur = None, self.bookings
        while cur:
            ## insertion point found
            if end <= cur.start:
                break
            prev, cur = cur, cur.next

        ## intersection found - don't insert
        if prev and start < prev.end:
            return False
        
        new_booking = self.Booking(start, end)
        new_booking.next = cur
        if not prev:
            ## create a new first booking
            self.bookings = new_booking
        else:
            prev.next = new_booking
            
        return True

## 2022-08-16 (binary search tree imp)
class MyCalendar:
    class BST:
        def __init__(self, start, end):
            self.start = start
            self.end = end
            
            self.left = None
            self.right = None
            
    def __init__(self):
        self.bookings = None

    def book(self, start: int, end: int) -> bool:
        if not self.bookings:
            self.bookings = self.BST(start, end)
            return True
        
        cur = self.bookings
        while cur:
            if start >= cur.end:
                if not cur.right:
                    cur.right = self.BST(start, end)
                    return True
                else:
                    cur = cur.right
            elif end <= cur.start:
                if not cur.left:
                    cur.left = self.BST(start, end)
                    return True
                else:
                    cur = cur.left
            else:
                ## intersection found
                return False
                
                    
            
# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)  

# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)