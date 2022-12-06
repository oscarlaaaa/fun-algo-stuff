// 2022-06-21 (Filtering approach)
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> suggestions;
        
        vector<string> curProducts = products;
        sort(curProducts.begin(), curProducts.end());
        
        int idx = 0, curLetter = 0;
        for (int i=0; i<searchWord.length(); i++) {
            // filter out products in our current list that doesn't match
            vector<string> filtered;
            for (int j=0; j<curProducts.size(); j++) {
                if (curProducts[j].size() > i && curProducts[j][i] == searchWord[i])
                    filtered.push_back(curProducts[j]);
            }
            curProducts = move(filtered);
            
            if (curProducts.size() < 3) {
                suggestions.push_back(curProducts);
            } else {
                vector<string> slice(curProducts.begin(), curProducts.begin()+3);
                suggestions.push_back(slice);
            }
        }
        return suggestions;
    }
};

// 2022-06-22 (sliding window approach)
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> suggestions;
        sort(products.begin(), products.end());
        
        int left = 0, right = (int) products.size();
        for (int i=0; i<searchWord.length(); i++) {
            while (left < right && products[left][i] != searchWord[i])
                left++;
            
            while (right-1 >= left && products[right-1][i] != searchWord[i])
                right--;
            
            int rightBound = right - left >= 3 ? left+3 : right;
            vector<string> slice(products.begin()+left, products.begin()+rightBound);
            suggestions.push_back(slice);
        }
        return suggestions;
    }
};
