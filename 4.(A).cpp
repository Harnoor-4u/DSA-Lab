#include <iostream>
using namespace std;

//QUESTION 4 PART A ASSIGNMENT 1

void reverseArray(int arr[], int n) {
    int start = 0, end = n - 1;
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    reverseArray(arr, n);

    cout << "Reversed Array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
