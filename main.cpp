#include <iostream>

using namespace std;

//Time O(n)

int* findMissing(int* arr, int n) {
    int arr2[n];
    int* resultArr = new int[2];
    for (int i=1; i<=n; i++) {
        arr2[i - 1] = i; //fills arr2 with expected unique ints
    }
    int count = 0;
    int arrCount = 0; //only increments when int found to prevent out of bound indexing
    for (int i=0; i<n; i++) {
        if ((arr[arrCount] ^ arr2[i]) !=  0) {
            resultArr[count] = arr2[i];
            count++;
        } else {
            arrCount++;
        }
        if (count == 2) {
            return resultArr;
        }
    }
}

//With an array of n unique ints where each element is in the range [1,n]
//With array size of n-2 find which two numbers are missing array
int main(){
    int n=7;
    int arr[n-2] = {1,2,3,4,6};
    int* result = findMissing(arr, n);
    for (int i=0; i<2; i++) {
        cout << result[i] << " ";
    }
    return 0;
}