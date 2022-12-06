# [115. Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/)
 
Given two strings `s` and `t`, return the number of distinct subsequences of `s` which equals `t`.

A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., `"ACE"` is a subsequence of `"ABCDE"` while `"AEC"` is not).

The test cases are generated so that the answer fits on a 32-bit signed integer.

 
Example 1:

    Input: s = "rabbbit", t = "rabbit"
    Output: 3
    
Example 2:

    Input: s = "babgbag", t = "bag"
    Output: 5

Constraints:

* 1 <= s.length, t.length <= 1000
* s and t consist of English letters.