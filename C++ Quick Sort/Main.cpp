#include <iostream>
#include <vector>

using std::cout;
using std::endl;

int partition(std::vector<int>& arr, int start, int end) {

	int temp = 0;

	int pivotIndex = start;
	int pivotValue = arr[end];

	for (int i = start; i < end; i++) {
		if (arr[i] < pivotValue) {
			//swap the values and increase pivot index
			//this will gradually move everything smaller than pivot value left and everything larger to the right
			temp = arr[i];
			arr[i] = arr[pivotIndex];
			arr[pivotIndex] = temp;

			pivotIndex++;
		}

	}
	//swap the end and index to make the pivot be in the correct place in the array, so now everything smaller is to the left and
	//everything larger is to the right
	temp = arr[pivotIndex];
	arr[pivotIndex] = arr[end];
	arr[end] = temp;

	return pivotIndex;
}


void quickSort(std::vector<int>& arr, int start, int end) {
	if (start >= end) {//if the start is greater than or equal to the end then it is sorted and everything will return
		return;
	}

	//partition the array and recursively call quick sort
	int index = partition(arr, start, end);
	quickSort(arr, start, index - 1);
	quickSort(arr, index + 1, end);



}

int main(int argc, char* argv[]) {
	srand(time(NULL));

	int arrSize = 25;//this number stores the number of numbers that go in the array of numbers
	int maxValue = 100; //how large the numbers can be 

	//create an array of random values
	std::vector<int> arr;
	arr.reserve(arrSize);
	for (int i = 0; i < arrSize; i++) {
		arr.push_back(std::rand() % maxValue);
	}



	//output the array
	cout << "Unsorted: " << endl;
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;


	//call the quicksort algorithm
	quickSort(arr, 0, arr.size() - 1);


	//output the array again now it is sorted
	cout << "Sorted: " << endl;
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;

	return 0;
}