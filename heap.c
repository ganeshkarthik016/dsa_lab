// #include<stdio.h>
// #include<stdlib.h>

//  typedef struct{
//     int arr[100];
//     int size;
//  }heap;
//  void init(heap*h){
//     h->size=0;
//  }
//  void swap(int *i,int*j){
//      int temp=*j;
//      *j=*i;
//      *i=temp;
//  }
//  int max(int a, int b){
//     if(a>=b)return a;
//     return b;
//  }
//  void insert(heap*h,int n){
//     if(h->size>=100){printf("Heap Overflow");return;}
//     int i=h->size;
//    h-> arr[i]=n;
//    h->size++;
//     while (i > 0 && h->arr[(i - 1) / 2] < h->arr[i]) {
//         swap(&h->arr[i], &h->arr[(i - 1) / 2]);
//         i = (i - 1) / 2;
//     }
//    }
//    void heapify(heap*h,int index,int n){
//     int i=index;
//     while((2*i+2)<n){
//         int temp=h->arr[i];
//         int mx=max(h->arr[i],max(h->arr[2*i+1],h->arr[2*i+2]));
//         if(mx !=temp ){
//             h->arr[i]=mx;
//             if(mx==h->arr[2*i+1]){h->arr[2*i+1]=temp;i=2*i+1;}
//             else {h->arr[2*i+2]=temp;i=2*i+2;}
//         }
//         else{break;}
//      }
//      if(2*i+2==n){
//         if(h->arr[i] < h->arr[2*i+1]){
//             int temp=h->arr[2*i+1];
//            h->arr[2*i+1]= h->arr[i];
//         h->arr[i]=temp;
//         }
//      }
//    }
//    void delete(heap*h){
//     if(h->size==0){
//         printf("\n Heap underflow");
//     }
//     int n=h->size;
//      h->arr[0]=h->arr[n-1];
//      h->size--;
//      n--;
//      heapify(h,0,n);
//    }
   
//    void sort(heap*h){
//     for(int i=h->size-1;i>=0;i--){
//         swap(&h->arr[0],&h->arr[i]);
//         heapify(h,0,i-1);
//     }
//    }
//   void print(heap*h){
//     for(int i=0;i<h->size;i++){
//         printf("%d ",h->arr[i]);
//     }
// }
//   int main(){
//     int input[]={1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
//     int size =sizeof(input)/sizeof(int);
//     heap h;
//     init(&h);
//     for(int i=0;i<size;i++){
//         insert(&h,input[i]);
//     }
//     sort(&h);
//     print(&h);
//   }

  //----------------------------------------------------------------------------------
  #include <stdio.h>
#include <stdlib.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify: ensures max-heap property at index i
void heapify(int arr[], int n, int i) {
    int largest = i;         // Initialize largest as root
    int left = 2*i + 1;      // left child
    int right = 2*i + 2;     // right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Build Max Heap
void buildHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

// Print process with maximum resources
void printMax(int arr[], int n) {
    if (n > 0)
        printf("Process with max resources: %d\n", arr[0]);
    else
        printf("Heap is empty.\n");
}

// Increase resources for a process
void increaseKey(int arr[], int i, int new_val) {
    arr[i] = new_val;
    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Remove process having max resources
int extractMax(int arr[], int *n) {
    if (*n <= 0)
        return -1;
    if (*n == 1) {
        (*n)--;
        return arr[0];
    }

    int root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify(arr, *n, 0);
    return root;
}

// Insert new process
void insertKey(int arr[], int *n, int key) {
    (*n)++;
    int i = *n - 1;
    arr[i] = key;

    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heap Sort (ascending order)
void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Print heap
void printHeap(int arr[], int n) {
    printf("Heap: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[100] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int n = 11;
    int choice, val, index;

    buildHeap(arr, n);

    while (1) {
        printf("\n==== MENU ====\n");
        printf("1. Print process with max resources\n");
        printf("2. Increase resources for a process\n");
        printf("3. Remove process with max resources\n");
        printf("4. Insert new process\n");
        printf("5. Sort processes in ascending order\n");
        printf("6. Display heap\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printMax(arr, n);
                break;
            case 2:
                printf("Enter process index (0-%d) and new value: ", n-1);
                scanf("%d %d", &index, &val);
                increaseKey(arr, index, val);
                break;
            case 3:
                printf("Removed max: %d\n", extractMax(arr, &n));
                break;
            case 4:
                printf("Enter new process resource value: ");
                scanf("%d", &val);
                insertKey(arr, &n, val);
                break;
            case 5:
                heapSort(arr, n);
                printf("Sorted processes (ascending): ");
                for (int i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;
            case 6:
                printHeap(arr, n);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}