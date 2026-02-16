#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define fr(i,a,b) for(int i = a; i < b; i++)
#define MAX 100000
#define swap(a, b) do { int temp = a; a = b; b = temp; } while(0)

// ==================== Utility Functions ====================

// Frequency count for integers in array
int freq[MAX] = {0};
void freq_arr(const int *arr, int n) {
    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
}

// Frequency count for characters in string
int freq_c[256] = {0};
void freq_str(const char *s) {
    for(int i = 0; s[i] != '\0'; i++) {
        freq_c[(unsigned char)s[i]]++;
    }
}

// Prime check
int isPrime(int n) {
    if(n < 2) return 0;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return 0;
    }
    return 1;
}

// Sieve
void sieve(int n, int *is_prime) {
    for(int i = 0; i <= n; i++) is_prime[i] = 1;
    is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i * i <= n; i++) {
        if(is_prime[i]) {
            for(int j = i * i; j <= n; j += i) {
                is_prime[j] = 0;
            }
        }
    }
}

// gcd and lcm
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Binary search
int binary_search_custom(const int *a, int n, int target) {
    int l = 0, r = n - 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(a[mid] == target) return mid;
        else if(a[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

// XOR upto n
int xor_upto(int n) {
    if(n % 4 == 0) return n;
    if(n % 4 == 1) return 1;
    if(n % 4 == 2) return n + 1;
    return 0;
}

// power function
int pow_int(int base, int exp) {
int result = 1;
while (exp > 0) {
    if (exp % 2 != 0)
        result *= base;
    base *= base;
    exp = exp / 2;
}
return result;
}

// Sorting (QuickSort)
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
void sort(int arr[], int low, int high) {
    if(low < high) {
        int pindex = partition(arr, low, high);
        sort(arr, low, pindex - 1);
        sort(arr, pindex + 1, high);
    }
}

// ==================== Solve Function ====================
void solve() {
    // Your code here
}

/////////////////////////////////////////////////////////////////////////////////
// Author: ganesh B. KARTHIK
// Institute: IIIT Jabalpur
/////////////////////////////////////////////////////////////////////////////////

int main() {
    solve();
    return 0;
}