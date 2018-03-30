#include <iostream>

using namespace std;

typedef struct Heap {
    int heap[31000];
    int t;
    Heap () {
        this->heap [31000];
        this->t = 0;
    }
} Heap;

void insert_heap1(Heap *hep, int x) {
    hep -> t ++;
    hep -> heap[hep -> t] = x;
}

void heapify(Heap *hep, int i);

void build_heap (Heap *hep) {
    for (int i = hep->t/2; i > 0; i --) {
        heapify(hep, i);
    }
}

void heapify (Heap *hep, int i) {
    while (i <= hep->t/2) {
        int maior;
        if (2*i + 1 <= hep->t) {
            if (hep->heap[2*i] >= hep->heap[(2*i) + 1]) {
                maior = 2*i;
            } else {
                maior = 2*i +1;
            }
        } else {
            maior = 2*i;
        }
        if (hep->heap[i] < hep->heap[maior]) {
            int AUX = hep->heap [maior];
            hep->heap[maior] = hep->heap[i];
            hep->heap[i] = AUX;
            i = maior;
        } else {
            i = hep->t;
        }
    }
}

int remove_heap (Heap *hep) {
    int AUX = hep->heap[1];
    hep->heap[1] = hep->heap[hep->t];
    hep->heap[hep->t] = AUX;
    hep->t--;
    heapify(hep, 1);
    return AUX;
}

void heapsort(Heap *hep) {
    if (hep ->t == 1) {
        return; 
    } else {
        int AUX;
        while (hep->t> 1) {
            AUX = hep->heap[1];
            hep->heap[1] = hep->heap[hep->t];
            hep->heap[hep->t] = AUX;
            hep->t--;
            heapify(hep, 1);
        }
    }
}

void insert_heap(Heap *hep, int key) {
    if (hep->t == 0) {
        hep->t ++;
        hep->heap[hep->t] = key;
    } else {
        hep->t++;
        hep->heap[hep->t] = key;
        if (hep->heap[hep->t/2] < hep->heap[hep->t]) {
            int z = hep->t;
            int AUX;
            while (z>1 && hep->heap[z] > hep->heap[z/2]) {
            AUX = hep->heap[z/2];
            hep->heap[z/2] = hep->heap[z];
            hep->heap[z] = AUX;
            z /= 2;
            }
        } 
    }
}

int main() {
    int A[] = {34, 43, 53, 52, 24, 12, 54, 1, 3, 4};
    Heap *hep = new Heap();
    for (int i = 0; i < sizeof(A)/sizeof(int); i ++) {
        insert_heap(hep, A[i]);
    }
    int a = hep->t;
    build_heap(hep);
    heapsort(hep);
    for (int i = 1; i <= a; i ++) {
        cout << hep->heap[i] << endl;
    }
    return 0;
}