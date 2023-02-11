## 2023-02-11
class Solution:
    def distinctNames(self, ideas: List[str]) -> int:
        """
        input: a list of name idea strings
        output: number of distinct valid names for the company

        notes:
        - swap the first letters of two "idea" strings to denote a valid idea
        - maybe we can group all strings based on their substring of idea[1:]?
            - within each grouping maybe have a set of first letters they possess
            - flip the groupings so that we only have 26 groups to iterate thru after
        - with this, we just need to find all possible permutations of:
            - first letters within different groups
        - can we calculate as we iterate through?
            - probably not as we might hit a word that we haven't iterated towards yet?
        - just compare sets
            - multiply the sizes of the sets together
            - subtract 2 for every intersecting value between sets
                - can accomplish this in 1 move by multiplying the differences with each other
        
        {"offee": {c, t}, "onuts": {d}, "ime": {t}}
        ---> we should probably flip it and limit our iteration to 26*26
        {"c": [offee], "d": [onuts], "t": [time, offee]}

        analysis:
        - time = O(n) where n=length of ideas
        - space = O(n) where n=length of ideas
        """
        idea_groups = dict()
        for idea in ideas:
            if idea[0] not in idea_groups:
                idea_groups[idea[0]] = set()
            idea_groups[idea[0]].add(idea[1:])
        
        distinct = 0
        seen = set()
        for k1, v1 in idea_groups.items():
            for k2, v2 in idea_groups.items():
                ## prevent matching words within their own group OR previously matched
                if k1 == k2 or (k1, k2) in seen:
                    continue
                
                distinct += 2*len(v1.difference(v2))*len(v2.difference(v1))
                seen.add((k2, k1))
        
        return distinct