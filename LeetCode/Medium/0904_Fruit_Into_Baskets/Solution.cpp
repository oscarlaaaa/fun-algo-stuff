// 2023-02-07 (sliding window)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        /*
            input: list of fruits
            output: maximum number of fruits pickable

            notes:
            - only have 2 baskets, and each basket can hold one type of fruit
                - basically can onyl pick 2 types of fruit
            - must pick exactly one fruit from every tree from the start tree moving
              towards the right
            - once we reach a tree with fruit that cannot fit, must stop

            approach:
            - sliding window headed eastwards
            - keep track of what numbers we take in wiht a set
            - expand until we hit a different number
                - once we do, track our max window size
                - shrink until we only have one type of fruit
            - repeat until we hit the end
        */
        int n = fruits.size();
        int pick = 0, maxPick = 0;
        unordered_map<int, int> picked;
        for (int left=0, right=0; right<n; right++) {
            while (picked.size() == 2 && !picked.count(fruits[right])) {
                picked[fruits[left]]--;
                pick--;
                if (picked[fruits[left]] == 0)
                    picked.erase(fruits[left]);
                left++;
            }
            picked[fruits[right]]++;
            pick++;
            maxPick = max(maxPick, pick);
        }
        return maxPick;
    }
};
