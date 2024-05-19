    #include <stdio.h>  
      int i;
    int getMax(int a[], int n) {  
       int max = a[0];  
       for(i = 1; i<n; i++) {  
          if(a[i] > max)  
             max = a[i];  
       }  
       return max; //maximum element from the array  
    }  
      
    void countingSort(int a[], int n, int place) // function to implement counting sort  
    {  
      int output[n + 1];  
      int count[10] = {0};    
      int i;
      // Calculate count of elements  
      for (i = 0; i < n; i++)  
        count[(a[i] / place) % 10]++;  
          
      // Calculate cumulative frequency  
      for ( i = 1; i < 10; i++)  
        count[i] += count[i - 1];  
      
      // Place the elements in sorted order  
      for ( i = n - 1; i >= 0; i--) {  
        output[count[(a[i] / place) % 10] - 1] = a[i];  
        count[(a[i] / place) % 10]--;  
      }  
      
      for ( i = 0; i < n; i++)  
        a[i] = output[i];  
    }  
      
    // function to implement radix sort  
    void radixsort(int a[], int n) {  
       
      // get maximum element from array  
      int max = getMax(a, n);  
      int place;
      // Apply counting sort to sort elements based on place value  
      for ( place = 1; max / place > 0; place *= 10)  
        countingSort(a, n, place);  
    }  
      
    // function to print array elements  
    void printArray(int a[], int n) {  
    int i;
      for ( i = 0; i < n; ++i) {  
        printf("%d  ", a[i]);  
      }  
      printf("\n");  
    }  
      
    int main() {  
      int a[] = {181, 289, 390, 121, 145, 736, 514, 888, 122};  
      int n = sizeof(a) / sizeof(a[0]);  
      printf("Before sorting array elements are - \n");  
      printArray(a,n);  
      radixsort(a, n);  
      printf("After applying Radix sort, the array elements are - \n");  
      printArray(a, n);  
    }  
