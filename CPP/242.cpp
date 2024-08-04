/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Example 3:
Input: s = "rat", t = "art"
Output: true
*/

//Time complexity:  O(nlogn) -> onde n = s+t
//Space complexity: O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;//strcmp()
    }
};

//OR

//Time complexity:  O(n)
//Space complexity: O(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        unordered_map<char, int> count;

        // Count the frequency of characters in string s
        for (size_t i = 0; i < s.size(); i++)
            count[s[i]]++;

        // Decrement the frequency of characters in string t
        for (size_t i = 0; i < t.size(); i++)
            count[t[i]]--;

        // Check if any character has non-zero frequency
        for (size_t i = 0; i < count.size(); i++)
            if (count[i].second != 0) return false;
        return true;
    }
};

//OR

//Time complexity:  O(n)
//Space complexity: O(27) || O(s¹+t¹+26)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        int count[26] = {0};

        // Count the frequency of characters in string s
        for (size_t i = 0; i < s.size(); i++)
            count[s[i] - 'a']++;

        // Decrement the frequency of characters in string t
        for (size_t i = 0; i < t.size(); i++)
            count[t[i] - 'a']--;

        // Check if any character has non-zero frequency
        for (size_t i = 0; i < 26; i++)
            if (count[i] != 0)
                return false;
       
        return true;
    }
};