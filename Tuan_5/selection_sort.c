#include <stdio.h>

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%5d ", arr[i]);
    }
    printf("\n");
}

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        
        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
        printf("After iteration %2d: ", i + 1);
        print_array(arr, n);
    }
}

int main() {
    int arr[] = {101, 23, 57, 13, 25, 121, 87, 36, 13, 204, 111, 89, 59};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("SELECTION SORT\n");
    printf("Original array:     ");
    print_array(arr, n);
    
    selection_sort(arr, n);
    
    printf("Final sorted array: ");
    print_array(arr, n);
    
    return 0;
}

