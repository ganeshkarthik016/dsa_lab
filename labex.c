#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node{
 char city_name[50];
 long long pin_code;
 long long prize;
};
int binary_search(struct node  a[], int n, int target,int poi[]) {
    int l = 0, r = n - 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(a[mid].prize == target&&poi[mid]==1) return mid;
        else if(a[mid].prize < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int binary_search_ch(struct node  a[], int n, int target,int poi[]) {
    int l = 0, r = n - 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(a[mid].prize == target&&poi[mid]==1) return mid;
        else if(a[mid].prize < target) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}


int partition(struct node arr[], int low, int high) {
    int pivot = arr[low].prize;
    int i = low;
    int j = high;
    while(i < j) {
        while(arr[i].prize <= pivot && i <= high - 1) i++;
        while(arr[j].prize > pivot && j >= low + 1) j--;
        if(i < j) {
            struct node temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        };
    }
    struct node temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
void sort(struct node arr[], int low, int high) {
    if(low < high) {
        int pindex = partition(arr, low, high);
        sort(arr, low, pindex - 1);
        sort(arr, pindex + 1, high);
    }
}

void printall(struct node arr[],int poi[],int last){
    for(int i=0;i<=last;i++){
        if(poi[i]==1){
            printf("%s ",arr[i].city_name);
            printf("%lld %lld\n",arr[i].pin_code,arr[i].prize);
        }
    }
}
 

struct node delete(struct node arr[],int poi[],int last, long long prize){
    int index = binary_search(arr,last+1,prize,poi);
    struct node n;
    n.prize = -1;
    if(index==-1) return n;
    n = arr[index];
    poi[index] = 0;
    return n;
}

// ==================== Solve Function ====================
void solve() {
    // Your code here
    int n; scanf("%d",&n);
    struct node estate[50];
    int last = 0;
    int poi[50];
    for(int i=0;i<n;i++){
        scanf("%s",estate[i].city_name);
        scanf("%lld",&estate[i].pin_code);
        scanf("%lld",&estate[i].prize);
        last = i;
        poi[i] = 1;
    }
   sort(estate,0,last);
   while(1){
    printf("1.To list all : \n");
    printf("2.To delete : \n");
    printf("3.Closest : \n");
    printf("4.just before : \n");
    printf("5. exit: \n");
    printf("Enter the choise: \n");
    int ch; scanf("%d",&ch);
    if(ch==5) break;
    switch (ch)
    {
    case 1:
       printall(estate,poi,last);
        break;
    case 2:
        long long pr; scanf("%lld",&pr);
        struct node p = delete(estate,poi,last,pr);
        printf("%s ",p.city_name);
        printf("%lld %lld\n",p.pin_code,p.prize);
    case 3:
         long long prr; scanf("%lld",&prr); 
         int index = binary_search_ch(estate,last+1,prr,poi);
         if(estate[index].prize==prr){
             printf("%s ",estate[index].city_name);
        printf("%lld %lld\n",estate[index].pin_code,estate[index].prize);
         }
         else {
            struct  node pp = (estate[index].prize-prr>estate[index+1].prize-prr) ? estate[index+1] : estate[index];
            printf("%s ",pp.city_name);
        printf("%lld %lld\n",pp.pin_code,pp.prize);
         }
    case 4:
    long long prri; scanf("%lld",&prri); 
         int index1 = binary_search_ch(estate,last+1,prri,poi);
             printf("%s ",estate[index1].city_name);
        printf("%lld %lld\n",estate[index1].pin_code,estate[index1].prize);
         
   }
}
}

int main() {
    solve();
    return 0;
}