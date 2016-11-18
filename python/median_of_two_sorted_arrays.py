class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        m, n = len(nums1), len(nums2)
        merge = sorted(nums1+nums2)
        if (m+n)%2 == 1:
            return float(merge[int((m+n-1)/2)])
        else:
            return (float(merge[int((m+n)/2)-1]) + float(merge[int((m+n)/2)]))/2