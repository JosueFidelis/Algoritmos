#include <iostream>

using namespace std;

int partition (int arr[], int begining, int end) {
    int pivot = arr[end];
    int i = begining;
    int t;
    for (int j = begining; j <end; j ++){
        if (arr[j] <= pivot) {
            t = arr[j];
            arr[j] = arr[i];
            arr[i] = t;
            i ++;
        }
    }
    t = arr[i];
    arr[i] = arr[end];
    arr[end] = t;
    return i;
}

void quicksort(int arr[], int begining, int end) {
    if (begining >= end) {
        return;
    } 
    int q = partition(arr, begining, end);
    quicksort(arr, begining, q - 1);
    quicksort(arr, q + 1, end);
}

int main () {
    int arr[] = {1, 54, 23, 36, 16, 76, 67, 57, 24, 57, 46, 2, 4, 243, 65, 143, 5, 65, 32, 343, 43, 35, 45, 12, 34, 876, 543, 452, 65436245, 46542, 465, 235};
    quicksort(arr, 0, sizeof(arr)/sizeof(int) - 1);
    for (int i = 0; i < sizeof(arr)/sizeof(int); i ++){
        cout << arr[i] << endl;
    }
    return 0;
}