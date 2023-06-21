#include <iostream>
using namespace std;


int partition(int arr[], int low, int high)
{
    // atur pivot di high
	int pivot = arr[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++) {

        // patokanya pivot
		if (arr[j] < pivot) {
			i++; 
			swap(arr[i], arr[j]);
		}
	}
    /* setelah data sampai tepat di sebelum akhir array, 
    tukar posisi akhirnya (pivot) ke posisi i + 1 */
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		// pi =  index partisi / index pivot setelah diubah
		int pi = partition(arr, low, high);
        cout << (pi-1) << endl;

		// disortir lagi jikalau 1x quicksort tidak cukup
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = { 7, 6, 3, 4, 1, 3, 2};
	int n = sizeof(arr) / sizeof(arr[0]);

	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	printArray(arr, n);

	return 0;
}