//ae-validate-subsequence-easy-cpp

/*


Solution:

1. We only need to iterate over the array one time

2. We can have two pointers, one pointer on the array 
and another point on the subsequence that we are trying to validate

We have found a valid subsequence if we iterate through the full subsequence

If we iterate through the array before the full subsequence then we did
not find a valid subsequence

We can use a while loop to continue iterating through both the array
and the subsequence until either reaches n


*/


#include <iostream>
#include <vector>


class Solution {
public:
	//Determines whether a subsequence is a valid subsequnce of an array
	bool isValidSubsequence(std::vector<int> &array, std::vector<int>sequence);
};


bool Solution::isValidSubsequence(std::vector<int> &array, std::vector<int>sequence) {

	//Create two pointers for array and sequence to iterate through
	//and initialize both of them to 0;
	int arrayPointer = 0;
	int sequencePointer = 0;

	//We want to iterate through both until pointers are equal to n
	//create a while loop
	while (arrayPointer < array.size() && sequencePointer < sequence.size()) {

		//First we want to check if we found a match at the Array index and the sequence index
		//If so, we can increment sequencePointer forward
		if (array[arrayPointer] == sequence[sequencePointer]) {
			sequencePointer++;
		}
		//Regardless of if we find a match or not, we will continously move the array 
		//forward so we need to increment it after each iteration
		arrayPointer++;
	}

	//Once we exit out of this while loop, either the full sequence was found or
	//the array finished without the sequence being fully found, we can create an if
	//else statement to determine if it is valid or not
	if (sequencePointer == sequence.size()) {

		//this means the subsequence was found within the array
		return true;
	}
	else {
		return false;
	}

}


int main() {

	std::vector<int> array = { 5, 1, 22, 25, 6, -1, 8, 10 };
	std::vector<int> sequence = { 1, 6, -1, 10 };

	Solution solution;

	std::cout << std::boolalpha << solution.isValidSubsequence(array, sequence);



	return 0;

}
















