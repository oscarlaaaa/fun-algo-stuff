## 2022-10-07 (thanks ray)
class Solution:
    def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
        prereqs = {
            'k': 'a',
            'a': 'o',
            'o': 'r',
            'r': 'c',
        }
        
        croak_count = {
            'c': 0,
            'r': 0,
            'o': 0,
            'a': 0,
            'k': 0
        }

        required_num_of_frogs = 0
        num_of_frogs = 0

        for c in croakOfFrogs:
            ## check if it's a 'croak' character
            if c not in croak_count:
                return -1

            if c != 'c':
                prereq = prereqs[c]
                if croak_count[prereq] == 0:
                    return -1
                croak_count[prereq] -= 1

            croak_count[c] += 1
            if c in {'c', 'k'}:
                num_of_frogs += 1 if c == 'c' else -1

            required_num_of_frogs = max(required_num_of_frogs, num_of_frogs)

        croak_count['k'] = 0 
        return required_num_of_frogs if sum([val for val in croak_count.values()]) == 0 else -1