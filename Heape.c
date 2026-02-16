#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyMax(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);
}

void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void printMaxProcess(int arr[], int n) {
    if (n > 0)
        printf("Process with maximum resources has %d resources.\n", arr[0]);
    else
        printf("Heap is empty.\n");
}

void increaseResources(int arr[], int n, int index, int inc) {
    if (index < 0 || index >= n) {
        printf("Invalid process index.\n");
        return;
    }
    arr[index] += inc;
    while (index > 0 && arr[(index - 1) / 2] < arr[index]) {
        swap(&arr[index], &arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
    printf("Resources increased.\n");
}

int deleteMax(int arr[], int n) {
    if (n <= 0) {
        printf("Heap is empty.\n");
        return 0;
    }

    int maxValue = arr[0];
    arr[0] = arr[n - 1];
    n--;
    heapifyMax(arr, n, 0);
    printf("Removed process with %d resources.\n", maxValue);
    return n;
}

int insertHeap(int arr[], int n, int value) {
    n++;
    arr[n - 1] = value;
    int i = n - 1;
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    printf("New process inserted.\n");
    return n;
}

void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapifyMax(arr, i, 0);
    }
    printf("Processes sorted in ascending order of resources.\n");
}

int main() {
    int arr[100] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int n = 11;
    int choice, value, index, inc;

    buildHeap(arr, n);

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Display heap\n");
        printf("2. Print process with max resources\n");
        printf("3. Increase resources for a process\n");
        printf("4. Remove process with max resources\n");
        printf("5. Insert new process\n");
        printf("6. Sort processes in ascending order\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 0)
            break;

        switch (choice) {
            case 1:
                printf("Current Heap: ");
                printHeap(arr, n);
                break;
            case 2:
                printMaxProcess(arr, n);
                break;
            case 3:
                printf("Enter process index (0 to %d): ", n - 1);
                scanf("%d", &index);
                printf("Enter resources to increase: ");
                scanf("%d", &inc);
                increaseResources(arr, n, index, inc);
                break;
            case 4:
                n = deleteMax(arr, n);
                break;
            case 5:
                printf("Enter resources for new process: ");
                scanf("%d", &value);
                n = insertHeap(arr, n, value);
                break;
            case 6:
                heapSort(arr, n);
                printHeap(arr, n);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
