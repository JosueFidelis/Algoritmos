#include <iostream> 

using namespace std;


void mergesort(int merge[], int mergeSaida[], int begining, int end);

void intercala(int merge[], int mergeSaida[], int begining, int begining2, int end){
    int i, k = i = begining;
    int j = begining2 + 1;
    while (i <= begining2 && j <= end) {
        if (merge[i] <= merge[j]) {
            mergeSaida[k] = merge[i];
            i++;
            k++;
        } else {
            mergeSaida[k] = merge[j];
            j++;
            k++;
        }
    }
    while (i <= begining2) {
        mergeSaida[k] = merge[i];
        i++;
        k++;
    }
    while (j <= end) {
        mergeSaida[k] = merge[j];
        j++;
        k ++;
    }
    for (int i = begining; i <= end; i ++) {
        merge[i] = mergeSaida[i];
    }
}

void mergesort(int merge[], int mergeSaida[], int begining, int end) {
    if (begining >= end) {
        return;
    } else {
        mergesort(merge, mergeSaida, begining, (begining+end)/2);
        mergesort(merge, mergeSaida, ((begining+end)/2) + 1, end);
        intercala(merge, mergeSaida, begining, ((begining+end)/2), end);
    }
}

int main () {
    int a[]= {3 ,5 ,2 ,1, 4, 8, 5, 45, 65, 68};
    int mergeSaida[sizeof(a)/sizeof(int)];
    mergesort(a, mergeSaida, 0, sizeof(a)/sizeof(int) - 1);
    for (int i = 0; i < sizeof(a)/sizeof(int); i ++) {
        cout << a[i] << endl;
    }
    return 0;
}