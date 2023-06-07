// 2023-06-05 (buckets)
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        /*
        notes:
        - can we subtract smaller from larger each time? or maybe take largest and smallest
          and create buckets for each element; if there is overlap, then it is not a sequence
        - invalid if the range for each bucket doesn't divide properly
        - fit elements into buckets by dividing their val by the bucket range
            - bucket range = largest-smallest / number of slots-1
        
        analysis:
        - time = O(n) where n=length of arr
        - space = O(n) where n=length of arr
        */
        int n = arr.size();
        int smallest = *std::min_element(arr.begin(), arr.end());
        int largest = *std::max_element(arr.begin(), arr.end());

        // all numbers are the same = valid arithmetic progression
        if (smallest == largest)
            return true;

        // impossible to have an arithmetic progression since the avg. gap between elements
        // would have to be a floating point number
        if ((largest-smallest)%(n-1) != 0)
            return false;
        
        int bucketRange = (largest-smallest)/(n-1);

        vector<bool> buckets(n);
        for (int val : arr) {
            int slot = (val-smallest)/bucketRange;
            if (buckets[slot])
                return false;
            buckets[slot] = true;
        }
        return true;
    }
};