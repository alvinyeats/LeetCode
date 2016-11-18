/*****************************************************************
	Q:There are two sorted arrays nums1 and nums2 of size
	m and n respectively. Find the median of the two sorted 
	arrays. The overall run time complexity should be O(log (m+n)).

******************************************************************/

#include "stdafx.h"
#include <iostream>
#include <cmath>

using std::min;
using std::cin;
using std::cout;
using std::endl;

class Solution{
public:
	int getkth(int a[], int m, int b[], int n, int k){
		if(m > n)
			return getkth(b, n, a, m, k);
		if(m == 0)
			return b[k - 1];
		if(k == 1)
			return min(a[0], b[0]);

		int i = min(m, k/2), j = min(n, k/2);
		if(a[i-1] > b[j-1])
			return getkth(a, m, b+j, n-j, k-j);
		else
			return getkth(a+i, m-i, b, n, k-j);
		return 0;

	}

	double findMedianSortedArrays(int A[], int m, int B[], int n){
		int p = (m + n + 1) >> 1;
		int q = (m + n + 2) >>1;
		return (getkth(A, m, B, n, p) + getkth(A, m, B, n, q)) / 2.0;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{	
	int A[] = {1,9};
	int B[] = {2,4,6,6};

	Solution y;
	cout <<	y.findMedianSortedArrays(A, 2, B, 4) << endl;


	return 0;
}
