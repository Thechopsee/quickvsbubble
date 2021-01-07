#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>



#define N 100000




void bubbleSort(int* pole, int lenght) {
	for (int i = 0; i < lenght - 1; i++) {
		for (int j = 0; j < lenght - i - 1; j++) {
			if (pole[j + 1] < pole[j]) {
				int tmp = pole[j + 1];
				pole[j + 1] = pole[j];
				pole[j] = tmp;
			}
		}
	}
}

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}



int partition(int* array, int low_indx, int high_indx)
{
	int pivot = array[high_indx];
	int i = (low_indx - 1);

	for (int j = low_indx; j <= high_indx - 1; j++)
	{

		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high_indx]);
	return (i + 1);
}


void quickSort(int* array, int low_indx, int high_indx)
{
	if (low_indx < high_indx)
	{

		int pi = partition(array, low_indx, high_indx);

		quickSort(array, low_indx, pi - 1);
		quickSort(array, pi + 1, high_indx);
	}
}



inline void PrintTimeDifference(std::chrono::steady_clock::time_point begin, std::chrono::steady_clock::time_point end)
{
	long long t = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	printf("%lld [ms]\n", t);
}

void randgen(int* rnd_nums)
{
	srand(time(NULL));
	

	for (int i = 0; i < N; i++)
	{
		
		rnd_nums[i] = rand() % N;
	}
}


int main()
{
	
	int* rnd_nums = new int[N];
	randgen(rnd_nums);


	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	bubbleSort(rnd_nums, N);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	PrintTimeDifference(begin, end);


	begin = std::chrono::steady_clock::now();
	quickSort(rnd_nums, 0, N - 1);
	end = std::chrono::steady_clock::now();
	PrintTimeDifference(begin, end);
	


	

	return 0;
}

