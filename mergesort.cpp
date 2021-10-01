# include<iostream>
using namespace std;
void merge(int arr[], int lb, int mid, int ub) {
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int b[ub - lb] = {0};
    while(i <= mid && j <= ub) {
        if(arr[i] <= arr[j]) {
            b[k] = arr[i];
            i++;
        } else if(arr[j] < arr[i]) {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    if(i > mid) {
        while(j <= ub) {
            b[k] = arr[j];
            j++;
            k++;
        }
    } else {
        while(i <= mid) {
            b[k] = arr[i];
            i++;
            k++;
        }
    }
    for(int k = lb; k <= ub; k++) {
        arr[k] = b[k];
    }
}
void mergesort(int arr[], int lb, int ub) {
    if(lb < ub) {
        int mid = (lb + ub) / 2;
        mergesort(arr, lb, mid);
        mergesort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

int main() {
    int a[5] = {100, 234, 234321, 99, 0};
    mergesort(a, 0, 5);
    for(int i = 0; i < 5; i++) {
        cout<<a[i]<<endl;
    }
    return 0;
}
