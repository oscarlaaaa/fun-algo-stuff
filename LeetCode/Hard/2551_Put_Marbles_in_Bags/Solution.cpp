// 2023-01-28
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        /*
            putting marbles within bags just means that you ignore values between the
            two bounds, and the edges comprise of the entire cost
            
            we want to find the distribution that yields us the minimum score, and then
            the maximum score to yield the greatest difference possible
            
            k groups = picking k to k*2 numbers to sum together
                - numbers have groups of 2 adjacent
                    - can overlap by 1 if necessary
                - have to include both ends, so it's really k-2 to k*2 -2 numbers in the middle
            
            can just think of it as choosing the k-1 boundary pairs in the middle to mark k separate bags
            - we only need to sum up the ends of each bag, so we choose pairs to mark the end of one bag
              and the start of another

            approach:
            - initialize a total with the first and last weight (as we have to include these)
            - generate adjacent pairs from weights to act as the boundaries between one bag and the next
                - place the weight of the pair within a list to iterate through later
            - sort our end-list of weights to get the smallest and largest weights
            - take the k-1 pair weights from the beginning + our initial total to get the smallest total
              weight possible
            - do the same with the k-1 pair weights from the end + initial total to get the largest total
              weight possible
        */  
        int n = weights.size();
        if (k == n) return 0;
        
        long long total = weights[0] + weights[n-1];
        
        // generate the boundary pairs between bags
        vector<long long> pairs;
        for (int i=0; i<n-1; i++) {
            pairs.push_back(weights[i] + weights[i+1]);
        }
        sort(pairs.begin(), pairs.end());
        
        long long minimum = total, maximum = total;
        for (int i=0; i<k-1; i++) {
            minimum += pairs[i];
        }
        
        for (int i=n-2; i>n-1-k; i--) {
            maximum += pairs[i];
        }
        
        return maximum - minimum;
    }
};