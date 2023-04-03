// 2023-04-02 (2pointer + sorting)
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        /*
        notes:
        - infite number of boats, each one with an upper weight limit
        - each boat can carry up to 2 people max
        - what if we just sort the people list and take either the lowest + highest (if possible)
          otherwise only taking the highest? we can kinda guarantee optimal pairings this way

        analysis:
        - time = O(nlogn) where n=people size
        - space = O(1)
        */
        int n = people.size();
        sort(people.begin(), people.end());
        int boats = 0;
        int left = 0, right = n-1;
        while (left <= right) {
            if (left != right && people[left] + people[right] <= limit) 
                left++;
            right--;
            boats++;
        }
        return boats;
    }
};

// 2023-04-02 (2pointer + bucket sort)
class Solution {
public:
    vector<int> bucketSort(vector<int>& arr, int size) {
        vector<int> buckets(size+1);
        for (int val : arr)
            buckets[val]++;

        vector<int> output;
        for (int i=0; i<=size; i++) {
            for (int j=0; j<buckets[i]; j++)
                output.push_back(i);
        }
        return output;
    }
    int numRescueBoats(vector<int>& people, int limit) {
        /*
        notes:
        - infite number of boats, each one with an upper weight limit
        - each boat can carry up to 2 people max
        - what if we just sort the people list and take either the lowest + highest (if possible)
          otherwise only taking the highest? we can kinda guarantee optimal pairings this way
            - can further optimize by bucket sorting

        analysis:
        - time = O(n) where n=people size
        - space = O(1)
        */
        int n = people.size();
        vector<int> sortedPeople = bucketSort(people, limit);
        int boats = 0;
        int left = 0, right = n-1;
        while (left <= right) {
            if (left != right && sortedPeople[left] + sortedPeople[right] <= limit) 
                left++;
            right--;
            boats++;
        }
        return boats;
    }
};