/*
Given an array where every element occurs three times, except one element which occurs only once. Find the element that occurs once. 
Expected time complexity is O(n) and O(1) extra space.
Examples:
Input: arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3}
Output: 2
*/
typedef vector<int> vi;

int solve(vi arr){
  int ones = 0, twos = 0, uncommon = 0;
  for(auto &i : arr){
    twos |= (ones & i);
    ones ^= i;
    uncommon = ~(ones & twos);
    ones &= uncommon;
    twos &= uncommon;
  }
	return ones;
}
