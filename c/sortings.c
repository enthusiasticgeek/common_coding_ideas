#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Helper function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void list(int* a, int size){
     for (int i=0; i < size; i++){
         printf("%d,",a[i]);
     }
}

// Function to randomize the aay
void randomize(int* a, int size) {
    srand(time(NULL));  // Initialize the random seed

    for (int i = size - 1; i > 0; i--) {
        // Generate a random index between 0 and i (inclusive)
        int j = rand() % (i + 1);

        // Swap the current element with the randomly selected element
        swap(&a[i], &a[j]);
    }
}

//Bubble sort
void sort(int* a, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (a[j] > a[j+1]) {  // Changed comparison condition
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

//simple reverse
void reverse(int *a, int size){
     int temp[size];
     for (int i=0; i < (size); i++){
              temp[i] = a[size-1-i];
     }
     list(temp,size);
}


//better reverse
void reverse1(int* a, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = a[i];
        a[i] = a[size - 1 - i];
        a[size - 1 - i] = temp;
    }
}

// Function to perform the partitioning step
int partition(int* a, int low, int high) {
    // Select the rightmost element as the pivot
    int pivot = a[high];

    // Index of the smaller element
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (a[j] <= pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    // Place the pivot element in its correct position
    swap(&a[i + 1], &a[high]);

    // Return the index of the pivot element
    return i + 1;
}

// Function to implement QuickSort
void quickSort(int* a, int low, int high) {
    if (low < high) {
        // Partition the aay and get the pivot index
        int pivotIndex = partition(a, low, high);

        // Recursively sort the left and right sub-aays
        quickSort(a, low, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, high);
    }
}

// Merge two sorted subaays into a single sorted subaay
void merge(int* a, int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;

    // Compare elements from both subaays and merge them in sorted order
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            a[k++] = left[i++];
        } else {
            a[k++] = right[j++];
        }
    }

    // Copy the remaining elements from the left subaay
    while (i < leftSize) {
        a[k++] = left[i++];
    }

    // Copy the remaining elements from the right subaay
    while (j < rightSize) {
        a[k++] = right[j++];
    }
}

// Merge Sort function
void mergeSort(int* a, int size) {
    if (size <= 1) {
        return;  // Base case: Array of size 1 is already sorted
    }

    int mid = size / 2;

    // Create left and right subaays
    int left[mid];
    int right[size - mid];

    // Copy elements to left and right subaays
    for (int i = 0; i < mid; i++) {
        left[i] = a[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = a[i];
    }

    // Recursively sort the left and right subaays
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // Merge the sorted subaays
    merge(a, left, mid, right, size - mid);
}



int main (int argc, char* argv[]){
    int a[10] = {14,10,222,23,444,85,99,191,29,233};
    int len = sizeof(a) / sizeof(a[0]);
    printf("length=%d\n",len);
    sort(a,len); 
    list(a,len); 
    printf("\n");
    reverse1(a,len); 
    list(a,len); 
    printf("\n");
    randomize(a,len);
    list(a,len); 
    printf("\n");
    quickSort(a,0,len-1); 
    list(a,len); 
    printf("\n");
    randomize(a,len);
    list(a,len); 
    printf("\n");
    mergeSort(a,len); 
    list(a,len); 


    
    return 0;
}
