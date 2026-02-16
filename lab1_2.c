#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define swap(a, b) do { int temp = a; a = b; b = temp; } while(0)

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j) {
        while(arr[i] <= pivot && i <= high - 1) i++;
        while(arr[j] > pivot && j >= low + 1) j--;
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
void quick_sort(int arr[], int low, int high) {
    if(low < high) {
        int pindex = partition(arr, low, high);
        quick_sort(arr, low, pindex - 1);
        quick_sort(arr, pindex + 1, high);
    }
}

// ==================== Solve Function ====================
void solve() {
    int n;
    scanf("%d",&n);
    int arr[n];
    int sum = 0;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
         sum += arr[i];
    }
    int *p = arr;
    printf("1 :\n");
    for(int i = 0;i<n;i++){
        printf("value : %d; address : %p\n",arr[i],p);
        p++;
    }
    printf("2 : \n");
    printf("sum of all elements : %d\n",sum);
    printf("3 : \n");
    printf("Enter extra number : ");
    int ex; scanf("%d",&ex);
    int new[n+1];
    for(int i=0;i<n;i++){
        new[i] = arr[i];
    }
    new[n] = ex;
    quick_sort(new,0,n);
    for(int i=0;i<=n;i++){
        printf("%d ",new[i]);
    }
    printf("\n");
    printf("4 :\n");
    p--;
    for(int i=0;i<n;i++){
        printf("%d ",*p);
        p--;
    }
    printf("\n");
    printf("5 :\n");

}

/////////////////////////////////////////////////////////////////////////////////
// Author: ganesh KARTHIK Bhanupanthula
// Institute: IIITDM Jabalpur
/////////////////////////////////////////////////////////////////////////////////

int main() {
    solve();
    return 0;
}