// 2022-12-05 (sorting)
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        /*
            input: list of player skills
            output: sum of chemistry of all teams, or -1 if no equal skill

            notes:
            - the only way to get all equal teams is to do lowest+highest and converge in the middle
            - need to sort the array to make it easier

            approach:
            - sort the array in ascending order
            - record the sum of the first and last skills
                - we will use this to check for validity of all groups
            - iterate from both ends
                - if sum != recorded sum from above, return -1
                - add the product of their skills to total
        */
        long long total = 0;
        int n = skill.size();
        sort(skill.begin(), skill.end());
        int tot = skill.front() + skill.back();
        for (int i=0; i<n/2; i++) {
            if (skill[i] + skill[n-1-i] != tot) 
                return -1;
            total += skill[i] * skill[n-1-i];
        }
        return total;
    }
};