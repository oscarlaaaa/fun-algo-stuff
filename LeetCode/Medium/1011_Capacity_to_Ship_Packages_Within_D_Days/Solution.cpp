// 2023-02-25 (binary search)
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        /*
            input: list of package weights, and int days
            output: minimum weight capacity that will result in all packages shipped in d days

            notes:
            - looks kinda like we can binary search for the weight capacity to find the min?
                - similar to coco eats bananas
                - would end up with a nlogn solution
            - must be in order, so it's kinda difficult to find a way to greedily approach it

            analysis:
            - time = O(nlogn) where n=length of weights
            - space = O(1)
        */

        // we set the high bound as the weight needed if every package was the same weight as 
        // the max element
        int low = 1;
        int high = *max_element(weights.begin(), weights.end()) * ceil(1.0*weights.size()/days);
        
        while (low < high) {
            int maxWeight = low + (high-low)/2;
            int d = 1, curWeight = 0;
            for (int num : weights) {
                if (num > maxWeight) {
                    d = days+1;
                    break;
                }

                if (curWeight + num > maxWeight) {
                    d++;
                    curWeight = 0;
                }
                curWeight += num;
            }

            if (d <= days) {
                high = maxWeight;
            } else {
                low = maxWeight+1;
            }
        }

        return low;
    }
};