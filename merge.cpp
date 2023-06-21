#include <iostream>
using namespace std;
void merge(int array[], int left, int mid, int right){                                    
    int subArrKiri = mid - left + 1; 
    int subArrKanan = right - mid;   
    // Create temp arrays
    int *leftArray = new int[subArrKiri], *rightArray = new int[subArrKanan];
    // for loop untuk membuar array sebelah kiri
    for (int i = 0; i < subArrKiri; i++)
        leftArray[i] = array[left + i];
    // for loop untuk membuat array sebelah kanan
    for (int j = 0; j < subArrKanan; j++)
        rightArray[j] = array[mid + 1 + j];

    int indexArrKiri = 0, indexArrKanan = 0;
    int indekOfMergeArr = left;

    // while loop di bawah untuk mengurutkan array dari terkecil ke besar
    while (indexArrKiri < subArrKiri && indexArrKanan < subArrKanan){
        if (leftArray[indexArrKiri] <= rightArray[indexArrKanan]){
            array[indekOfMergeArr] = leftArray[indexArrKiri];
            indexArrKiri++;
        }else{
            array[indekOfMergeArr] = rightArray[indexArrKanan];
            indexArrKanan++;
        }
        indekOfMergeArr++;
    }
    while (indexArrKiri < subArrKiri){
        array[indekOfMergeArr] = leftArray[indexArrKiri];
        indexArrKiri++;
        indekOfMergeArr++;
    }
    while (indexArrKanan < subArrKanan){
        array[indekOfMergeArr] = rightArray[indexArrKanan];
        indexArrKanan++;
        indekOfMergeArr++;
    }
    // hapus leftArray dan rightArray karena tidak diperlukan
    delete[] leftArray;
    delete[] rightArray;
}


void mergeSort(int array[], int begin, int end){
    if (begin >= end)
        return; 

    int mid = begin + (end - begin) / 2; 
    mergeSort(array, begin, mid);        // mengurutkan array sebelah kiri pertama
    mergeSort(array, mid + 1, end);      // mengurutkan array sebelah kanan pertama
    merge(array, begin, mid, end);
}

void printArray(int Arr[], int size){
    for (int i = 0; i < size; i++)
        cout << Arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[] = {0, 11, 13, 15, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout << "Array awal\t: ";
    printArray(arr, arr_size);
    mergeSort(arr, 0, arr_size - 1);
    cout << "Setelah diurutkan\t: ";
    printArray(arr, arr_size);
    return 0;
}