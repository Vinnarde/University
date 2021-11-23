#include <chrono>
#include <functional>
#include <omp.h>
#include <iostream>
#include <random>
#include <vector>

constexpr size_t vectorSize = 10000000;

const auto seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator(seed);
std::uniform_int_distribution<int_fast32_t> distribution(0, 10000);
auto generateRandomNumber = std::bind(distribution, std::ref(generator));

bool isSorted(const std::vector<int>& array, bool (*cmp)(int, int))
{
	for (size_t i = 0; i < array.size() - 1; ++i)
	{
		if (cmp(array[i], array[i + 1]) != true)
			return false;
	}

	return true;
}

inline bool ascending(const int first, const int second)
{
	return first <= second;
}

void merge(std::vector<int>& arr, int low, int mid, int high)
{
	auto tempArr = new int[high - low + 1];
	int i{ low }, j{ mid + 1 };
	int k{};

	while (i <= mid && j <= high)
	{
		if (arr[i] <= arr[j])
			tempArr[k++] = arr[i++];
		else
			tempArr[k++] = arr[j++];
	}

	while (i <= mid)
	{
		tempArr[k++] = arr[i++];
	}

	while (j <= high)
	{
		tempArr[k++] = arr[j++];
	}

	for (k = 0, i = low; i <= high; ++i, ++k)
	{
		arr[i] = tempArr[k];
	}

	delete[] tempArr;
}

void mergeSortOMP(std::vector<int>& arr, int low, int high)
{
	if (low >= high)
		return;
	int mid = (low + high) / 2;

	omp_set_dynamic(true);
	//omp_set_nested(true);
#pragma omp parallel shared(arr)
	{
#pragma omp sections
		{
#pragma omp section
			{
				mergeSortOMP(arr, low, mid);
			}
#pragma omp section
			{
				mergeSortOMP(arr, mid + 1, high);
			}
		}
	}
	merge(arr, low, mid, high);
}

void mergeSort(std::vector<int>& arr)
{
	mergeSortOMP(arr, 0, arr.size() - 1);
}


int partition(std::vector<int>& arr, int low, int high)
{
	int pivot{ arr[high] };
	int i{ low - 1 };

	for (int j = low; j <= high - 1; ++j)
	{
		if (arr[j] < pivot)
		{
			++i;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[high]);
	return i + 1;
}

void partition(std::vector<int>& arr, int low, int high, int& outLeftPivot, int& outRightPivot)
{
	if (arr[low] > arr[high])
	{
		std::swap(arr[low], arr[high]);
	}

	int leftIndex{ low + 1 };
	int rightIndex{ high - 1 };

	int iterator{ low + 1 };
	int leftPivot{ arr[low] };
	int rightPivot{ arr[high] };

	while (iterator <= rightIndex)
	{
		// if elements are less than the left pivot
		if (arr[iterator] < leftPivot)
		{
			std::swap(arr[iterator], arr[leftIndex]);
			leftIndex++;
		}

		// if elements are greater than or equal
		// to the right pivot
		else if (arr[iterator] >= rightPivot)
		{
			while (arr[rightIndex] > rightPivot && iterator < rightIndex)
			{
				rightIndex--;
			}

			std::swap(arr[iterator], arr[rightIndex]);

			rightIndex--;

			if (arr[iterator] < leftPivot)
			{
				std::swap(arr[iterator], arr[leftIndex]);
				leftIndex++;
			}
		}
		iterator++;
	}
	leftIndex--;
	rightIndex++;

	std::swap(arr[low], arr[leftIndex]);
	std::swap(arr[high], arr[rightIndex]);

	outLeftPivot = leftIndex;
	outRightPivot = rightIndex;
}

void dualPivotQuickSort(std::vector<int>& arr, int low, int high)
{
	if (low < high)
	{
		int leftPivot, rightPivot;
		partition(arr, low, high, leftPivot, rightPivot);
		dualPivotQuickSort(arr, low, leftPivot - 1);
		dualPivotQuickSort(arr, leftPivot + 1, rightPivot - 1);
		dualPivotQuickSort(arr, rightPivot, high);
	}
}

void quickSortOMP(std::vector<int>& arr, int low, int high)
{
	if (low < high)
	{
		int pivotLocation = partition(arr, low, high);

#pragma omp parallel sections
		{
#pragma omp section
			{
				quickSortOMP(arr, low, pivotLocation - 1);
			}
#pragma omp section
			{
				quickSortOMP(arr, pivotLocation + 1, high);
			}
		}
	}
}

void quickSort(std::vector<int>& arr)
{
	quickSortOMP(arr, 0, arr.size() - 1);
}



//#pragma optimize ("", off)
void task_1()
{
	std::vector<int> firstVector(vectorSize);
	std::vector<int> secondVector(vectorSize);

	std::for_each(firstVector.begin(), firstVector.end(), [](auto& x) { x = generateRandomNumber(); });
	std::for_each(secondVector.begin(), secondVector.end(), [](auto& x) { x = generateRandomNumber(); });

	std::vector<int> resultVector(vectorSize);

	double startPoint = omp_get_wtime();

#pragma omp parallel shared(firstVector, secondVector, resultVector) num_threads(2)
	{
#pragma omp sections
		{
#pragma omp section
			{
				for (size_t i = 0; i < vectorSize / 2; ++i)
					resultVector[i] = firstVector[i] + secondVector[i];
			}
#pragma omp section
			{
				for (size_t i = vectorSize / 2; i < vectorSize; ++i)
					resultVector[i] = firstVector[i] + secondVector[i];
			}
		}
	}

	double endPoint = omp_get_wtime();

	std::cout << "Sections.\n" << "Time taken: " << endPoint - startPoint << " seconds\n";


	startPoint = omp_get_wtime();

	mergeSort(resultVector);

	endPoint = omp_get_wtime();

	std::cout << "Merge sort.\n" << "Time taken: " << endPoint - startPoint << " seconds\n";

	std::cout << "Is sorted: " << std::boolalpha << isSorted(resultVector, ascending) << '\n';

	startPoint = omp_get_wtime();

	for (int64_t i = 0; i < vectorSize; ++i)
		resultVector[i] = firstVector[i] + secondVector[i];

	endPoint = omp_get_wtime();
	std::cout << "Sequential.\n" << "Time taken: " << endPoint - startPoint << " seconds\n";

	startPoint = omp_get_wtime();

	quickSort(resultVector);
	//dualPivotQuickSort(resultVector, 0, resultVector.size() - 1);

	endPoint = omp_get_wtime();

	std::cout << "Is sorted: " << std::boolalpha << isSorted(resultVector, ascending) << '\n';
	std::cout << "Quick sort.\n" << "Time taken: " << endPoint - startPoint << " seconds\n";
}


int main(int argc, char* argv[])
{
#ifdef _OPENMP
	printf_s("OpenMP is supported!\n\n");
#endif

	task_1();

	//std::vector<int> arr = { 24, 8, 42, 75, 29, 77, 38, 57 };
	//dualPivotQuickSort(arr, 0, arr.size() - 1);
	//std::cout << "Sorted array: ";
	//for (int i = 0; i < arr.size(); i++)
	//	std:: cout << arr[i] << " ";
	//	
	//std::cout << "\nIs sorted: " << isSorted(arr, ascending) << '\n';
}
