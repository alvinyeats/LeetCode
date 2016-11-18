/*****************************************************************
	Q:Given an array of integers, find two numbers such that they 
	add up to a specific target number.The function twoSum should 
	return indices of the two numbers such that they add up to the 
	target, where index1 must be less than index2. Please note that 
	your returned answers (both index1 and index2) are not zero-based.

	You may assume that each input would have exactly one solution.
******************************************************************/

#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target)
{
	unordered_map<int,int> hash;
	vector<int> result;
	
	for(int i=0;i<numbers.size();i++)
	{
		int numberToFind=target-numbers[i];
		if(hash.find(numberToFind)!=hash.end())
		{
			result.push_back(hash[numberToFind]+1);
			result.push_back(i+1);
			return result;
		}
		
	hash[numbers[i]]=i;
	}

	return result;
};


int _tmain(int argc, _TCHAR* argv[])
{
	
	int numbers[]={2,7,11,15};
	vector<int> num(numbers, numbers+4);

	int target = 18;

	
	vector<int> a = twoSum(num, target);
	cout << a[0] << "," << a[1] << "\n";
	
	return 0;
}