#include <stdio.h>

// Function to perform Bubble Sort and count swaps
void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swaps[arr[j]]++;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                
                // Count swaps for the swapped element
                swaps[arr[j]]++;
            }
        }
    }
}

// Function to perform Selection Sort and count swaps
void selectionSort(int arr[], int n, int swaps[])  {     
    int i, j, min_idx, temp;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++){
    // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
    if (min_idx != i) {
        swaps[arr[min_idx]]++;
        swaps[arr[i]]++;
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
    
    }
}


int main() {
    int array1bubble[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2bubble[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    
    int n1 = sizeof(array1bubble) / sizeof(array1bubble[0]);
    int n2 = sizeof(array2bubble) / sizeof(array2bubble[0]);
    
    int swaps1_bubble[100] = {0};  // Assuming values are between 1 and 100
    int swaps2_bubble[100] = {0};
    
    int swaps1_selection[100] = {0};
    int swaps2_selection[100] = {0};
    
    // Perform Bubble Sort and count swaps for array1
    bubbleSort(array1bubble, n1, swaps1_bubble);
    
    // Display swaps for array1 using Bubble Sort
    printf("array1 (Bubble Sort):\n");
    for (int i = 0; i < n1; i++) {
        printf("%d: %d\n", array1bubble[i], swaps1_bubble[array1bubble[i]]);
    }
    
    // Display total swaps for array1 using Bubble Sort
    int totalSwaps1_bubble = 0;
    for (int i = 0; i < n1; i++) {
        totalSwaps1_bubble += swaps1_bubble[array1bubble[i]];
    }
    totalSwaps1_bubble = totalSwaps1_bubble/2;
    printf("%d\n\n", totalSwaps1_bubble);

    // Performs Bubblesort for array2

    bubbleSort(array2bubble, n2, swaps2_bubble);
    
    // Display swaps for array2 using Bubble Sort
    printf("array2 bubble sort:\n");
    for (int i = 0; i < n2; i++) {
        printf("%d: %d\n", array2bubble[i], swaps2_bubble[array2bubble[i]]);
    }
    
    // Display total swaps for array2 using Bubble Sort
    int totalSwaps2_bubble = 0;
    for (int i = 0; i < n2; i++) {
        totalSwaps2_bubble += swaps2_bubble[array2bubble[i]];
    }
    totalSwaps2_bubble = totalSwaps2_bubble/2;
    printf("%d\n\n", totalSwaps2_bubble);

    int array1selection[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2selection[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    
    // Perform Selection Sort and count swaps for array1
    selectionSort(array1selection, n1, swaps1_selection);
    
    // Display swaps for array1 using Selection Sort
    printf("array1 selection sort:\n");
    for (int i = 0; i < n1; i++) {
        printf("%d: %d\n", array1selection[i], swaps1_selection[array1selection[i]]);
    }
    
    // Display total swaps for array1 using Selection Sort
    int totalSwaps1_selection = 0;
    for (int i = 0; i < n1; i++) {
        totalSwaps1_selection += swaps1_selection[array1selection[i]];
    }
    totalSwaps1_selection = totalSwaps1_selection / 2;
    printf("%d\n\n", totalSwaps1_selection);
    
    
    // Perform Selection Sort and count swaps for array2
    selectionSort(array2selection, n2, swaps2_selection);
    
    // Display swaps for array2 using Selection Sort
    printf("array2 selection sort:\n");
    for (int i = 0; i < n2; i++) {
        printf("%d: %d\n", array2selection[i], swaps2_selection[array2selection[i]]);
    }
    
    // Display total swaps for array2 using Selection Sort
    int totalSwaps2_selection = 0;
    for (int i = 0; i < n2; i++) {
        totalSwaps2_selection += swaps2_selection[array2selection[i]];
    }
    totalSwaps2_selection = totalSwaps2_selection / 2;
    printf("%d\n", totalSwaps2_selection);

    return 0;
}