#include <stdio.h>

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%5d ", arr[i]);
    }
    printf("\n");
}

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        printf("After iteration %2d: ", i);
        print_array(arr, n);
    }
}

int main() {
    int arr[] = {101, 23, 57, 13, 25, 121, 87, 36, 13, 204, 111, 89, 59};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("INSERTION SORT\n");
    printf("Original array:     ");
    print_array(arr, n);
    
    insertion_sort(arr, n);
    
    printf("Final sorted array: ");
    print_array(arr, n);
    
    return 0;
}

