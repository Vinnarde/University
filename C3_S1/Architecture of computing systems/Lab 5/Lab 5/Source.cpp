#include <iostream>
#include <omp.h>
#include <array>
#include <chrono>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const uint64_t vec_size = 10;

int threads = 8;

class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};


void fill_array(std::array<int, vec_size>& arr)
{
	for (auto& x : arr)
	{
		x = rand();
	}
}

void print_array(std::array<int, vec_size>& arr)
{
	for (auto x : arr)
		std::cout << std::setw(6) << x;

	std::cout << '\n';
}

void task_1()
{
	int n;
	std::array<int, vec_size> v_1{};
	std::array<int, vec_size> v_2{};

	std::array<int, vec_size> result{};

	fill_array(v_1);
	fill_array(v_2);

	print_array(v_1);
	print_array(v_2);
	Timer t;
#pragma omp parallel private(n) num_threads(2)
	{
		t.reset();
#pragma omp sections
		{
#pragma omp section
			{
				n = omp_get_thread_num();
				std::cout << "ThreadId: " << n << '\n';
				for (uint64_t i = 0; i < vec_size / 2; ++i)
				{
					result[i] = v_1[i] + v_2[i];
				}
			}
#pragma omp section
			{
				n = omp_get_thread_num();
				std::cout << "ThreadId: " << n << '\n';
				for (uint64_t i = vec_size / 2; i < vec_size; ++i)
				{
					result[i] = v_1[i] + v_2[i];
				}
			}
		}
	}

	double time = t.elapsed();
	print_array(result);
	std::cout << "\n\nTime elapsed: " << time << '\n';
}

void merge(int array[], int low, int mid, int high)
{
	int* temp_arr = new int[high - low + 1];
	int i = low, j = mid + 1;
	int k = 0;

	while (i <= mid && j <= high)
	{
		if (array[i] <= array[j])
			temp_arr[k++] = array[i++];
		else
			temp_arr[k++] = array[j++];
	}

	while (i <= mid)
	{
		temp_arr[k++] = array[i++];
	}

	while (j <= high)
	{
		temp_arr[k++] = array[j++];
	}

	for (k = 0, i = low; i <= high; ++i, ++k)
	{
		array[i] = temp_arr[k];
	}

	delete[] temp_arr;
}

void merge_sort(int array[], int low, int high)
{
	if (low >= high) return;
	int mid = (low + high) / 2;
	merge_sort(array, low, mid);
	merge_sort(array, mid + 1, high);

	merge(array, low, mid, high);
}

void merge_sort_omp(int array[], int low, int high, int splits)
{
	if (low >= high) return;

	int mid = (low + high) / 2;

#pragma omp parallel sections num_threads(2) if (threads > splits)
	{
#pragma omp section
		{
			merge_sort_omp(array, low, mid, splits * 2);
		}
#pragma omp section
		{
			merge_sort_omp(array, mid + 1, high, splits * 2);
		}
	}

	merge(array, low, mid, high);
}

bool isSorted(int array[], int size)
{
	for (int i = 1; i < size; ++i)
	{
		if (array[i] < array[i - 1])
			return false;
	}
	return true;
}



void task_2()
{
	constexpr int n = 100000000;

	int* array = new int[n];
	int* array2 = new int[n];
	int* array3 = new int[n];

	for (int i = 0; i < n; i++)
	{
		array[i] = n - i - 1;
		array2[i] = n - i - 1;
		array3[i] = n - i - 1;
	}

	Timer t1;
	merge_sort(array, 0, n - 1);
	double endPoint = t1.elapsed();
	std::cout << "Sequential sort. Time taken: " << endPoint << '\n';
	std::cout << "Is sorted: " << std::boolalpha << isSorted(array, n) << '\n';

	Timer t2;
	omp_set_dynamic(false);
	omp_set_num_threads(threads); // 8
	omp_set_nested(true);
	t2.reset();
	merge_sort_omp(array2, 0, n - 1, 1);
	endPoint = t2.elapsed();
	std::cout << "Parallel sort(with nested sections). Time taken: " << endPoint << '\n';
	std::cout << "Is sorted: " << std::boolalpha << isSorted(array2, n) << '\n';

	Timer t3;
	omp_set_nested(false);
	omp_set_num_threads(2);
	t3.reset();
	merge_sort_omp(array3, 0, n - 1, 4);
	endPoint = t3.elapsed();
	std::cout << "Parallel sort(no nested sections). Time taken: " << endPoint << '\n';
	std::cout << "Is sorted: " << std::boolalpha << isSorted(array3, n) << '\n';

	std::cout << array[n - 1] << '\n';
	std::cout << array2[n - 1] << '\n';
	std::cout << array3[n - 1] << '\n';
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];    // pivot
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void quickSortSequential(int arr[], int low, int high)
{
	if (low < high) {
		int pivot = partition(arr, low, high);

		quickSortSequential(arr, low, pivot - 1);
		quickSortSequential(arr, pivot + 1, high);

	}
}

void quickSortParallel(int arr[], int low, int high, int splits)
{
	if (splits >= threads)
		quickSortSequential(arr, low, high);
	else
	{
		int pivot = partition(arr, low, high);

#pragma omp parallel sections num_threads(2) if (threads > splits)
		{
#pragma omp section
			{
				quickSortParallel(arr, low, pivot - 1, splits * 2);
			}
#pragma omp section 
			{
				quickSortParallel(arr, pivot + 1, high, splits * 2);
			}
		}
	}
}

void task_3()
{
	constexpr int n = 100000000;

	int* array = new int[n];
	int* array2 = new int[n];
	int* array3 = new int[n];

	for (int i = 0; i < n; i++)
	{
		int temp = rand() * rand();
		array[i] = temp;
		array2[i] = temp;
		array3[i] = temp;
	}

	Timer t1;
	quickSortSequential(array, 0, n - 1);
	double endPoint = t1.elapsed();
	std::cout << "Sequential sort. Time taken: " << endPoint << '\n';
	std::cout << "Is sorted: " << std::boolalpha << isSorted(array, n) << '\n';

	Timer t2;
	omp_set_dynamic(false);
	omp_set_num_threads(threads); // 8
	omp_set_nested(true);
	t2.reset();
	quickSortParallel(array2, 0, n - 1, 1);
	endPoint = t2.elapsed();
	std::cout << "Parallel sort(with nested sections). Time taken: " << endPoint << '\n';
	std::cout << "Is sorted: " << std::boolalpha << isSorted(array2, n) << '\n';

	Timer t3;
	omp_set_nested(false);
	omp_set_num_threads(2);
	t3.reset();
	quickSortParallel(array3, 0, n - 1, 4);
	endPoint = t3.elapsed();
	std::cout << "Parallel sort(no nested sections). Time taken: " << endPoint << '\n';
	std::cout << "Is sorted: " << std::boolalpha << isSorted(array3, n) << '\n';

	std::cout << array[n - 1] << '\n';
	std::cout << array2[n - 1] << '\n';
	std::cout << array3[n - 1] << '\n';
}

int main()
{
	omp_set_dynamic(false);
	//std::cout << "Num of threads: " << omp_thread_count() << '\n';
	//task_1();
	//task_2();
	task_3();
	task_3();
	task_3();
	return 0;
}


/* This function takes first element as pivot, places
   the pivot element at its correct position in sorted
   array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */




   //int main()
   //{
   //	int start_s = clock();//start time
   //	for (int i = 0; i < n; i++) {
   //		arr[i] = rand() % n;//filling random value
   //	}
   //
   //	int pivot = partition(arr, 0, n - 1);// returns the pivot element
   //#pragma omp parallel sections
   //	{
   //#pragma omp section
   //		{
   //			quicksort(arr, 0, pivot - 1);//Thread 1
   //		}
   //#pragma omp section
   //		{
   //			quicksort(arr, pivot + 1, n - 1);//Thread 2
   //		}
   //	}
   //	int stop_s = clock();//end Time
   //	printf("Time taken: %.6fs\n", (double)(stop_s - start_s) / CLOCKS_PER_SEC);
   //}

