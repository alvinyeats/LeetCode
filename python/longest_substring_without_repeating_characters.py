class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        start = max_length = 0
        used_char = {}
        for idx, word in enumerate(s):
            if word in used_char and start <= used_char[word]:
                start = used_char[word] + 1
            else:
                max_length = max(max_length, idx - start + 1)
            used_char[word] = idx
        return max_length