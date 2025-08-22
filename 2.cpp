#include <iostream>
using namespace std;

//QUESTION 2 ASSIGNMENT 1

int removeDuplicates(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] == arr[j]) {
                // Shift elements to left
                for(int k = j; k < n-1; k++) {
                    arr[k] = arr[k+1];
                }
                n--;    
                j--;    
            }
        }
    }
    return n; 
}

int main() {
    int arr[100], n;

    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    n = removeDuplicates(arr, n);

    cout << "Array after removing duplicates: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
