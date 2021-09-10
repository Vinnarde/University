// #include <iostream>
// #include <omp.h>
// #include <array>
// #include <chrono>

// const uint64_t vec_size = 10;

// class Timer
// {
// private:
// 	// ���������� ����� ������������ ��� �������� ������� � ��������� �����
// 	using clock_t = std::chrono::high_resolution_clock;
// 	using second_t = std::chrono::duration<double, std::ratio<1> >;

// 	std::chrono::time_point<clock_t> m_beg;

// public:
// 	Timer() : m_beg(clock_t::now())
// 	{
// 	}

// 	void reset()
// 	{
// 		m_beg = clock_t::now();
// 	}

// 	double elapsed() const
// 	{
// 		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
// 	}
// };


// void fill_array(std::array<int, vec_size>& arr)
// {
// 	for (auto& x : arr)
// 	{
// 		x = rand();
// 	}
// }

// void print_array(std::array<int, vec_size>& arr)
// {
// 	for (auto x : arr)
// 		std::cout << x << ' ';

// 	std::cout << '\n';
// }

// void task_1()
// {
// 	int n;
// 	std::array<int, vec_size> v_1{};
// 	std::array<int, vec_size> v_2{};

// 	std::array<int, vec_size> result{};



// 	fill_array(v_1);
// 	fill_array(v_2);

// 	//print_array(v_1);
// 	//print_array(v_2);
// 	Timer t;
// #pragma omp parallel private(n) num_threads(2)
// 	{
// 		t.reset();
// #pragma omp sections
// 		{
// #pragma omp section
// 			{
// 				n = omp_get_thread_num();
// 				std::cout << "ThreadId: " << n << '\n';
// 				for (uint64_t i = 0; i < vec_size / 2; ++i)
// 				{
// 					result[i] = v_1[i] + v_2[i];
// 				}
// 			}
// #pragma omp section
// 			{
// 				n = omp_get_thread_num();
// 				std::cout << "ThreadId: " << n << '\n';
// 				for (uint64_t i = vec_size / 2; i < vec_size; ++i)
// 				{
// 					result[i] = v_1[i] + v_2[i];
// 				}
// 			}
// 		}
// 	}

// 	double time = t.elapsed();
// 	print_array(result);
// 	std::cout << "\n\nTime elapsed: " << time << '\n';
// }

// void merge(int array[], int low, int mid, int high)
// {
// 	int* temp_arr = new int[high - low + 1];
// 	int i = low, j = mid + 1;
// 	int k = 0;

// 	while (i <= mid && j <= high)
// 	{
// 		if (array[i] <= array[j])
// 			temp_arr[k++] = array[i++];
// 		else
// 			temp_arr[k++] = array[j++];
// 	}

// 	while (i <= mid)
// 	{
// 		temp_arr[k++] = array[i++];
// 	}

// 	while (j <= high)
// 	{
// 		temp_arr[k++] = array[j++];
// 	}

// 	for (k = 0, i = low; i <= high; ++i, ++k)
// 	{
// 		array[i] = temp_arr[k];
// 	}

// 	delete temp_arr;
// }

// void merge_sort_omp(int array[], int low, int high)
// {
// 	if (low >= high) return;

// 	int mid = (low + high) / 2;

// 	//omp_set_dynamic(1);

// 	int n = 0;

	
// #pragma omp parallel private(n) num_threads(12)
// 	{
// 		n = omp_get_num_threads();
// 		//std::cout << n << '\n';
// 		//omp_set_nested(0);
// #pragma omp sections 
// 		{
// #pragma omp section
// 			{
// 				merge_sort_omp(array, low, mid);
// 			}
// #pragma omp section
// 			{
// 				merge_sort_omp(array, mid + 1, high);
// 			}
// 		}
// 		//std::cout << n << '\n';

// 	}
// 	merge(array, low, mid, high);
// }

// void merge_sort(int array[], int low, int high)
// {
// 	if (low >= high) return;
// 	int mid = (low + high) / 2;
// 	merge_sort(array, low, mid);
// 	merge_sort(array, mid + 1, high);
// 	merge(array, low, mid, high);
// }


// void task_2()
// {
// 	const int n = 2097152;

// 	int* array = new int[n];

// 	for (int i = 0; i < n; i++)
// 	{
// 		array[i] = n - 1 - i;
// 	}


// 	Timer t;
// 	merge_sort_omp(array, 0, n - 1);
// 	double time = t.elapsed();

// 	std::cout << "Time elapsed: " << time << '\n';

// 	std::cout << array[n - 1];
// }

// int omp_thread_count() {
// 	int n = 0;
// #pragma omp parallel reduction(+:n)
// 	n += 1;
// 	return n;
// }

// int main()
// {
	
	
// 	omp_set_num_threads(12);
// 	std::cout << omp_thread_count();
// 	task_2();

// 	return 0;
// }
// //
// //
// //
// //
// //
// //
// //
// //
// //
// //#include <stdlib.h>
// //#include <stdio.h>
// //#include <chrono>
// //#include <time.h>
// ////#include <sys/time.h>
// //#include <math.h>
// //
// //#define N 2097152
// //
// //double wall_time(void) {
// //	/* struct timeval tv;
// //	 struct timezone tz;
// //
// //	 gettimeofday(&tv, &tz);*/
// //	return(1.0);
// //}
// //
// //class Timer
// //{
// //private:
// //	// ���������� ����� ������������ ��� �������� ������� � ��������� �����
// //	using clock_t = std::chrono::high_resolution_clock;
// //	using second_t = std::chrono::duration<double, std::ratio<1> >;
// //
// //	std::chrono::time_point<clock_t> m_beg;
// //
// //public:
// //	Timer() : m_beg(clock_t::now())
// //	{
// //	}
// //
// //	void reset()
// //	{
// //		m_beg = clock_t::now();
// //	}
// //
// //	double elapsed() const
// //	{
// //		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
// //	}
// //};
// //
// //
// //void print_array(int* array, int l, int r) {
// //	int i;
// //
// //	printf("[");
// //	for (i = l; i <= r; i++) {
// //		printf("%d", array[i]);
// //		if (i != r) {
// //			printf(", ");
// //		}
// //	}
// //	printf("]\n");
// //}
// //
// ///*
// // * Merges two sorted pieces from *array:
// // * [sl, el] and [sr, er]
// // */
// //void merge(int* array, int sl, int el, int sr, int er) {
// //	int len_l = el - sl + 1;
// //	int len_r = er - sr + 1;
// //
// //	int pos = 0;
// //
// //	// Creates a buffer to store the sorted interval temporarily
// //	// It is not possible to sort two sorted arrays in O(n) without additional memory
// //	int* buffer = (int*)malloc((len_l + len_r) * sizeof(int));
// //
// //	while (sl <= el && sr <= er) {
// //		if (array[sl] <= array[sr]) {
// //			buffer[pos++] = array[sl++];
// //		}
// //		else {
// //			buffer[pos++] = array[sr++];
// //		}
// //	}
// //
// //	while (sl <= el) {
// //		buffer[pos++] = array[sl++];
// //	}
// //	while (sr <= er) {
// //		buffer[pos++] = array[sr++];
// //	}
// //
// //	sl -= len_l;
// //	sr -= len_r;
// //
// //	for (pos = 0; pos < len_l; pos++) {
// //		array[sl++] = buffer[pos];
// //	}
// //	for (pos = len_l; pos < len_l + len_r; pos++) {
// //		array[sr++] = buffer[pos];
// //	}
// //
// //	free(buffer);
// //}
// //
// //void merge_sort(int* array, int b, int e) {
// //	if (e - b + 1 <= 1) return;
// //
// //	int m = (b + e) / 2;
// //
// //#pragma omp parallel
// //	{
// //#pragma omp sections
// //		{
// //#pragma omp section
// //			merge_sort(array, b, m);
// //
// //#pragma omp section
// //			merge_sort(array, m + 1, e);
// //		}
// //	}
// //	merge(array, b, m, m + 1, e);
// //}
// //
// //int is_sorted(int* array, int len) {
// //	int i;
// //	for (i = 1; i < len; i++) {
// //		if (array[i] < array[i - 1]) {
// //			return 0;
// //		}
// //	}
// //	return 1;
// //}
// //
// //int omp_thread_count() {
// //	int n = 0;
// //#pragma omp parallel reduction(+:n)
// //	n += 1;
// //	return n;
// //}
// //int main() {
// //	int i;
// //	int* array = (int*)malloc(N * sizeof(int));
// //
// //	if (!array) {
// //		printf("Panic. Could not allocate memory for array\n");
// //	}
// //
// //	srand(time(NULL));
// //	for (i = 0; i < N; i++) {
// //		array[i] = rand() % N;
// //	}
// //
// //	printf("%d\n", omp_thread_count());
// //
// //	//print_array(array, 0, N - 1);
// //	Timer t;
// //	double t0 = t.elapsed();
// //
// //	merge_sort(array, 0, N - 1);
// //	double t1 = t.elapsed();
// //	//print_array(array, 0, N - 1);
// //
// //	printf("Time spent %.4lf\n", t1 - t0);
// //
// //	if (!is_sorted(array, N)) {
// //		printf("Failure, the algorithm is not sorting properly.\n");
// //	}
// //	else {
// //		printf("Array successfuly sorted\n");
// //	}
// //
// //	free(array);
// //
// //	return 0;
// //}
// /
// /
// #include <iostream>
// #include <ctime>

// const int n = 100000000;

// int arr[n];
// /* This function takes first element as pivot, places
//    the pivot element at its correct position in sorted
// 	array, and places all smaller (smaller than pivot)
//    to left of pivot and all greater elements to right
//    of pivot */

// int partition(int arr[], int low, int high) {
// 	int i, j, temp, key;
// 	key = arr[low];
// 	i = low + 1;
// 	j = high;
// 	while (true) {
// 		while (i < high && key >= arr[i])
// 			i++;
// 		while (key < arr[j])
// 			j--;
// 		if (i < j) {
// 			temp = arr[i];
// 			arr[i] = arr[j];
// 			arr[j] = temp;
// 		}
// 		else {
// 			temp = arr[low];
// 			arr[low] = arr[j];
// 			arr[j] = temp;
// 			return(j);
// 		}
// 	}
// }

// /* The main function that implements QuickSort
//  arr[] --> Array to be sorted,
//   low  --> Starting index,
//   high  --> Ending index */
// void quicksort(int arr[], int low, int high)
// {
// 	int pivot;

// 	if (low < high) {
// 		pivot = partition(arr, low, high);

// 		quicksort(arr, low, pivot - 1);
// 		quicksort(arr, pivot + 1, high);

// 	}
// }


// int main()
// {
// 	int start_s = clock();//start time
// 	for (int i = 0; i < n; i++) {
// 		arr[i] = rand() % n;//filling random value
// 	}

// 	int pivot = partition(arr, 0, n - 1);// returns the pivot element
// #pragma omp parallel sections
// 	{
// #pragma omp section
// 		{
// 			quicksort(arr, 0, pivot - 1);//Thread 1
// 		}
// #pragma omp section
// 		{
// 			quicksort(arr, pivot + 1, n - 1);//Thread 2
// 		}
// 	}
// 	int stop_s = clock();//end Time
// 	printf("Time taken: %.6fs\n", (double)(stop_s - start_s) / CLOCKS_PER_SEC);
// }