#include <iostream>
#include <array>
#include <vector>
#include <functional>

void BubbleSort() {
	std::array<int, 8> packageWeight = { 55, 11, 68, 33, 28, 98, 55, 12 };
	int comparisonCount = 0;
	int swapCount = 0;

	std::cout << "Bubble Sort:\n";

	for (size_t i = 0; i < packageWeight.size() - 1; ++i) {
		for (size_t j = 0; j < packageWeight.size() - i - 1; ++j) {
			++comparisonCount;
			if (packageWeight[j] > packageWeight[j + 1]) {
				std::swap(packageWeight[j], packageWeight[j + 1]);
				++swapCount;
			}
		}
	}

	std::cout << "Sorted Weights: ";
	for (const auto& weight : packageWeight) {
		std::cout << weight << " ";
	}
	std::cout << std::endl;
	std::cout << "Total Comparisons Made: " << comparisonCount << std::endl;
	std::cout << "Total Swaps Made: " << swapCount << std::endl;
}

void SelectionSort() {
	std::array<int, 8> packageWeight = { 55, 11, 68, 33, 28, 98, 55, 12 };
	int comparisonCount = 0;
	int selectionCount = 0;

	std::cout << "Selection Sort:\n";

	for (size_t i = 0; i < packageWeight.size() - 1; ++i) {
		size_t minIndex = i;
		for (size_t j = i + 1; j < packageWeight.size(); ++j) {
			++comparisonCount;
			if (packageWeight[j] < packageWeight[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			std::swap(packageWeight[i], packageWeight[minIndex]);
			++selectionCount;
		}
	}

	std::cout << "Sorted Weights: ";
	for (const auto& weight : packageWeight) {
		std::cout << weight << " ";
	}
	std::cout << std::endl;
	std::cout << "Total Comparisons Made: " << comparisonCount << std::endl;
	std::cout << "Total Selections Made: " << selectionCount << std::endl;
}

void InsertionSort() {
	std::array<int, 8> packageWeight = { 55, 11, 68, 33, 28, 98, 55, 12 };
	int splitCount = 0, insertionCount = 0;

	std::cout << "Insertion Sort:\n";

	for (size_t i = 1; i < packageWeight.size(); ++i) {
		int key = packageWeight[i];
		size_t j = i;

		while (j > 0 && packageWeight[j - 1] > key) {
			packageWeight[j] = packageWeight[j - 1];
			--j;
			++splitCount;
		}

		packageWeight[j] = key;
		++insertionCount;
	}

	std::cout << "Sorted Weights: ";
	for (const auto& weight : packageWeight) {
		std::cout << weight << " ";
	}
	std::cout << std::endl;
	std::cout << "Total Splits: " << splitCount << std::endl;
	std::cout << "Total Insertions: " << insertionCount << std::endl;
}

void MergeSort() {
	std::vector<int> packageWeight = { 55, 11, 68, 33, 28, 98, 55, 12 };
	int splitCount = 0, mergeCount = 0;

	auto Merge = [&](std::vector<int>& array, int left, int mid, int right) {
		int leftSize = mid - left + 1;
		int rightSize = right - mid;

		std::vector<int> leftArray(leftSize);
		std::vector<int> rightArray(rightSize);

		for (int i = 0; i < leftSize; ++i)
			leftArray[i] = array[left + i];
		for (int j = 0; j < rightSize; ++j)
			rightArray[j] = array[mid + 1 + j];

		int i = 0, j = 0, k = left;

		while (i < leftSize && j < rightSize) {
			if (leftArray[i] <= rightArray[j]) {
				array[k] = leftArray[i];
				++i;
			}
			else {
				array[k] = rightArray[j];
				++j;
			}
			++k;
		}

		while (i < leftSize) {
			array[k] = leftArray[i];
			++i;
			++k;
		}

		while (j < rightSize) {
			array[k] = rightArray[j];
			++j;
			++k;
		}
		++mergeCount;
		};

	std::function<void(std::vector<int>&, int, int)> MergeSortRec = [&](std::vector<int>& array, int left, int right) {
		if (left < right) {
			int mid = left + (right - left) / 2;
			++splitCount;

			MergeSortRec(array, left, mid);
			MergeSortRec(array, mid + 1, right);
			Merge(array, left, mid, right);
		}
		};

	MergeSortRec(packageWeight, 0, packageWeight.size() - 1);

	std::cout << "Merge Sort:\n";
	std::cout << "Sorted Weights: ";
	for (const auto& weight : packageWeight) {
		std::cout << weight << " ";
	}
	std::cout << std::endl;
	std::cout << "Total Splits: " << splitCount << std::endl;
	std::cout << "Total Merges: " << mergeCount << std::endl;
}

int main() {
	BubbleSort();
	std::cout << "\n\n";
	SelectionSort();
	std::cout << "\n\n";
	InsertionSort();
	std::cout << "\n\n";
	MergeSort();

	return 0;
}