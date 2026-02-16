#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// void swap(int *a,int *b,char *i,char *j){
//     int temp;
//     temp = *a;
//     *a = *b;
//     *b = temp;
//     char copy[50];
//     strcpy(copy,(i));
//     strcpy(i,j);
//     strcpy(j,copy);
// }
// int partition(int arr[], int low, int high,char *names) {
//     int pivot = arr[low];
//     int i = low;
//     int j = high;
//     while(i < j) {
//         while(arr[i] <= pivot && i <= high - 1) i++;
//         while(arr[j] > pivot && j >= low + 1) j--;
//         if(i < j) swap(&arr[i], &arr[j],names+i,names+j);
//     }
//     swap(&arr[low], &arr[j],names+low,names+j);
//     return j;
// }
// void sort(int arr[], int low, int high,char *names[][]) {
//     if(low < high) {
//         int pindex = partition(arr, low, high, names);
//         sort(arr, low, pindex - 1, names);
//         sort(arr, pindex + 1, high, names);
//     }
// }
// ==================== Solve Function ====================



void solve() {
    // Your code here
    int n,t; scanf("%d %d",&n,&t);
    float rating[n];
    char names[n][50];
    for(int i=0;i<n;i++){
        scanf("%s",names[i]);
        scanf("%f",&rating[i]);
    }
    for(int i =0;i<n;i++){
        for(int j=i+1;j<n;j++){
             if(rating[i]<rating[j]){
                float temp;
               temp = rating[i];
               rating[i] = rating[j];
               rating[j] = temp;
               char copy[50];
               strcpy(copy,names[i]);
               strcpy(names[i],names[j]);
               strcpy(names[j],copy);
             }
             if(rating[i]==rating[j]){
                 char copy[50],copy1[50];
                 strcpy(copy,names[i]);
                 strcpy(copy1,names[j]);
                 int l=0;
                 if(strlen(copy)==strlen(copy1)) l = strlen(copy1);
                 else if(strlen(copy)>strlen(copy1)){
                        strcpy(names[i],copy1);
                        strcpy(names[j],copy);
                 }
                 else{
                    strcpy(names[i],copy);
                        strcpy(names[j],copy1);
                 }
                 for(int k = 0;k<l;k++){
                    if(copy[k]>copy1[k]){
                        strcpy(names[i],copy1);
                        strcpy(names[j],copy);
                        break;
                    }
                    else{
                        strcpy(names[i],copy);
                        strcpy(names[j],copy1);
                        break;
                    }
                 }
                }
        }
    }
    
    for(int i=0;i<t;i++){
        printf("%s  ",names[i]);
        printf("%f\n",rating[i]);
    }

}

int main() {
    solve();
    return 0;
}