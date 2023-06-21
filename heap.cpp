#include <iostream>
using namespace std;
// fungsi membuat tree
void heapify(int arr[], int N, int i){
	// largest akan menjadi root
	int largest = i;//2
	int kiri = 2 * i + 1;
	int kanan = 2 * i + 2;

	// jika anak yang kiri lebih besar dari root
	if (kiri < N && arr[kiri] > arr[largest])
		largest = kiri;
	// jika anak yang kanna lebih besar dari root
	if (kanan < N && arr[kanan] > arr[largest])
		largest = kanan;
	// jika largest bukan root
	if (largest != i) {
		swap(arr[i], arr[largest]);
		// fungsi rekursif untuk membuat sub-tree
		heapify(arr, N, largest);
	}
}
// fungsi untuk pengurutan array menggunakan heap sort
void heapSort(int arr[], int N){
	//for loop untuk membuat max-heap binary tree
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);
	// for loop untuk mengurutkan array
	for (int i = N - 1; i > 0; i--) {

		// pemindahan root sekarang ke paling akhir
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int N){
	for (int i = 0; i < N; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main(){
	int arr[] = { 1, 1, 3, 8, 15, 19 };
	int N = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, N);

	cout << "Sorted array is \n";
	printArray(arr, N);
}