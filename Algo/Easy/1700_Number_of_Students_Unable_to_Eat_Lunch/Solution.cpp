// 2022-09-18
//
// The only time we run into a time where students are unable to eat are when
// there are no students that prefer the top of the sandwich stack. As such, we
// can disregard the 'queueing` system and instead just count how many students
// prefer each sandwich type, and stop when we reach a sandwich that no students
// that enjoy it remaining.
//
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> prefer = {0, 0};
        for (int stud : students) 
            prefer[stud]++;
            
        for (int sandwich : sandwiches) {
            if (prefer[sandwich] == 0)
                break;
            prefer[sandwich]--;
        }
        
        return prefer[0]+prefer[1];
    }
};