#include<iostream>
#include<chrono>

using namespace std;
using namespace std::chrono;

int nums[10000];
int original[10000];

void swap(int& n1, int& n2) {
	int temp = n1;
	n1 = n2;
	n2 = temp;
}

void bubbleSort(int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (nums[j] > nums[j + 1]) {
				swap(nums[j], nums[j + 1]);
			}
		}
	}
}

void selectionSort(int n) {
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (nums[j] < nums[min]) {
				min = j;
			}
		}
		swap(nums[i], nums[min]);
	}
}

//void binarySort(int n) {
//	for (int i = 0; i < n, i++) {
//		for (int j = 0; j < n; j++)
//		{
//
//		}
//	}
//}

void originalArr() {
	for (int i = 0; i < 10000; i++)
	{
		original[i] = nums[i];
	}
}

void numsArr() {
	for (int i = 0; i < 10000; i++)
	{
		nums[i] = original[i];
	}
}

int main() {
	for (int i = 0; i < 10000; i++)
	{
		nums[i] = rand() % 1000;
	}
	originalArr();
	
	//Bubble sort
	auto start = high_resolution_clock::now();
	bubbleSort(10);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << "Bubble sort: " << duration.count() << " ms\n";
	

	// Selection Sort
	numsArr();
	start = high_resolution_clock::now();
	selectionSort(10);
	stop = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(stop - start);
	cout << "Selection sort: " << duration.count() << " ms\n";

	//Binary Sort
	/*numsArr();
	start = high_resolution_clock::now();
	binarySort(10);
	stop = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(stop - start);
	cout << "Binary sort: " << duration.count() << " ms\n";*/
}