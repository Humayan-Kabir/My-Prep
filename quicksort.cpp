#include<bits/stdc++.h>
using namespace std;
int partition(int arr[], int left, int right) {
    int i = left, j = right, pivot = arr[(left + right) / 2];
    while(i <= j) {
        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;
        if(i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++; j--;
        }
    }
    return i;
}
void quickSort(int arr[], int left, int right) {
      if(left >= right) return;
      int index = partition(arr, left, right);
      if (left < index - 1)
            quickSort(arr, left, index - 1);
      if (index < right)
            quickSort(arr, index, right);
     return;
}
int main() {
    int arr[] = {5, 1, 3, 8, 9};
    quickSort(arr, 0, 4);
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
        if(i == 4) cout << endl;
    }
    return 0;
}