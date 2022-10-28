def solutiondemo(arr):
    count = 1
    seen = set()
    for val in arr:
        if val < 1:
            continue
        seen.add(val)
        while count in seen:
            count += 1
    return count

def solution1(arr):
    return len(set([abs(arr[i]-arr[i-1]) for i in range(1, len(arr))]))

def solution2(s, arr):
    def get_counts(s):
        counts = dict()
        for c in s:
            counts[c] = counts[c]+1 if c in counts else 1
        return counts
            
    counts = get_counts(s)
    maximum = 0
    for word in arr:
        word_count = get_counts(word)
        
        can_craft = 99999999999
        for c, val in word_count.items():
            if c not in counts:
                can_craft = 99999999999
                break

            copies = counts[c] // val
            can_craft = min(can_craft, copies)
        
        if can_craft == 99999999999:
            continue
            
        maximum = max(can_craft, maximum)
    
    return maximum

solution2("BILLOBILLOLLOBBI", ["BILL", "BOB"])

def solution3(x, y, arr):
    jacob, jayden = 0, 0
    longest_prefix = -1
    for i, val in enumerate(arr):
        if val == x:
            jacob += 1
        if val == y:
            jayden += 1
        
        if jacob == jayden:
            longest_prefix = max(longest_prefix, i)
    
    return longest_prefix
