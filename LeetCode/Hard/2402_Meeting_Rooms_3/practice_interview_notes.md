- n number of meeting rooms
- labelled from 0 to n-1
- list of meetings we want to book with those meeting rooms
	- 2d list where item = [starttime, endtime]

booking meetings
- every meeting held in lowest number label
- if no available room, meeting is delayed until a room is free
	- doesn't affect the duration of a meeting
- rooms with earlier starts are given priority
- return the number of the room that has held the most meetings
	- in the case of a tie, then return the smaller room number

input:
- number of meeting rooms 
- list of meetings we would want to book

output:
- the room number that has held the most meetings (lower one in the case of a tie)

constraints:
- start time is always smaller than end time
- start times are unique

steps:
1. create a new list where we have [starttime, duration]
2. want to track:
	- current available rooms (in order of index) - pq/heap 
  - meetings that we want to book (in order of start times) - presort 
  - meetings that will end soon (in order of completion time) - pq/heap 
3. sort our meetings
4. initialize 2 min heaps - one to track available room numbers, and one to track meetings that are in progress
5. book out all the rooms by iterating through meetings and popping smallest indices off of our min heap
	- while we are booking rooms, we will push onto our other min heap with pairs of {endtime, room index}
  - keep track of # of times each room has been booked
  - whenever we book a room, we set time to the max(time, starttime)
6. return the index with the most # of bookings

examples:
n = 2
meetings = [[0, 6],[1, 6],[5, 8]]
----------------------------^
current_rooms = []
current_meetings = [{6, 0}, {6, 1}]
number_bookings = [1,2]
time = 6

rooms available = 
number of times booked = [1, 2]
output = 1
