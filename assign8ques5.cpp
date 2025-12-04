#include <iostream>
#include <vector>
using namespace std;


void maxHeapify(vector<int>& A, int i) {
    int n = A.size() - 1; 

    int left = 2 * i;      
    int right = 2 * i + 1; 
    int largest = i;


    if (left <= n && A[left] > A[largest])
        largest = left;


    if (right <= n && A[right] > A[largest])
        largest = right;


    if (largest != i) {
        swap(A[i], A[largest]);
        maxHeapify(A, largest);
    }
}

void buildMaxHeap(vector<int>& A) {
    int n = A.size() - 1; 


    for (int i = n / 2; i >= 1; i--) {
        maxHeapify(A, i);
    }
}

void heapSort(vector<int>& A) {
    buildMaxHeap(A);
    int heapSize = A.size() - 1;

    for (int i = heapSize; i >= 2; i--) {
        swap(A[1], A[i]);         // Move largest (root) to end
        heapSize--;               // Reduce heap size
        maxHeapify(A, 1); // Fix heap again
    }
}

int main() {
    
    vector<int> A = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

    cout << "Before Heap Sort:\n";
    for (int i = 1; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;

    heapSort(A);

    cout << "\nAfter Heap Sort (Ascending Order):\n";
    for (int i = 1; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}






