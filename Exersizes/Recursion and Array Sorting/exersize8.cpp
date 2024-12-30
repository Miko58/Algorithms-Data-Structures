#include <vector>
#include <iostream>
#include <time.h>
#include <assert.h>
#include <chrono>	 //for timing
#include <algorithm> //for comparing with STL sort

using namespace std;
using namespace std::chrono;
/**
 * Order left, center, and right and hide the pivot.
 * Then compute partition, restore the pivot and return its position.
 */
template <typename Comparable>
int partition(vector<Comparable> &a, int left, int right)
{
	assert(left < right);
	int center = (left + right) / 2;

	if (a[center] < a[left])
		std::swap(a[left], a[center]);
	if (a[right] < a[left])
		std::swap(a[left], a[right]);
	if (a[right] < a[center])
		std::swap(a[center], a[right]);

	// Place pivot at position right - 1
	std::swap(a[center], a[right - 1]);

	// Now the partitioning
	Comparable &pivot = a[right - 1];
	int i = left, j = right - 1;
	do
	{
		while (a[++i] < pivot)
			;
		while (pivot < a[--j])
			;
		if (i < j)
		{
			swap(a[i], a[j]);
		}
	} while (i < j);

	swap(a[i], a[right - 1]); // Restore pivot
	return i;
}

/**
 * Internal insertionSort method.
 * a is an array of Comparable items.
 * start is the left-most index of the subarray.
 * end is the right-most index of the subarray.
 */
template <typename Comparable>
void insertionSort(vector<Comparable> &a, int start, int end)
{
	assert(start <= end);
	for (int p = start; p <= end; ++p)
	{
		Comparable tmp = std::move(a[p]);

		int j;
		for (j = p; j > 0 && tmp < a[j - 1]; --j)
		{
			a[j] = std::move(a[j - 1]);
		}
		a[j] = std::move(tmp);
	}
}

const int useInsertion = 100;

/**
 * Internal quicksort method that makes recursive calls.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void introSort(vector<Comparable> &a, int left, int right)
{
	assert(left <= right);
	if (right - left > useInsertion)
	{
		int i = partition(a, left, right);
		introSort(a, left, i - 1);	// Sort small elements
		introSort(a, i + 1, right); // Sort large elements
	}
	else
	{ // Do an insertion sort on the subarray
		insertionSort(a, left, right);
	}
}

/**
 * Quicksort algorithm (driver).
 */
template <typename Comparable>
void introSort(vector<Comparable> &a)
{
	introSort(a, 0, a.size() - 1);
}

void checkSort(const vector<int> &a)
{
	for (int i = 0; i < a.size() - 1; ++i)
	{
		if (a[i] >= a[i + 1])
		{
			cout << "Error at " << i << endl;
		}
	}
	// cout << "Finished checksort" << endl;
}

template <typename AnyType>
void permute(vector<AnyType> &a)
{
	for (int j = 1; j < a.size(); ++j)
	{
		swap(a[j], a[rand() % j]);
	}
}

int main()
{
	int NUM_ITEMS = 10000;
	for (int x = 1; x < 9; x++)
	{
		NUM_ITEMS *= x;
		vector<int> a(NUM_ITEMS);
		vector<int> b(NUM_ITEMS); // for comparing with STL sort, copy of a
		for (int i = 1; i < a.size(); ++i)
		{
			a[i] = a[i - 1] + 'a';
		}

		for (int theSeed = 0; theSeed < 1; ++theSeed)
		{
			srand(time(0) + theSeed);

			permute(a);
			b = a;
			// Get starting timepoint
			auto start = high_resolution_clock::now();
			introSort(a);
			// Get ending timepoint
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);

			cout << "Time taken by introSort: "
				 << duration.count() << " microseconds" << endl;

			// Get starting timepoint
			start = high_resolution_clock::now();
			sort(b.begin(), b.end());
			// Get ending timepoint
			stop = high_resolution_clock::now();
			duration = duration_cast<microseconds>(stop - start);

			cout << "Time taken by STL sort: "
				 << duration.count() << " microseconds" << endl;
		}
	}

	return 0;
}
