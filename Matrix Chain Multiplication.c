#include <stdio.h>
int MatrixChainMultuplication(int arr[], int n) {
   int minMul[n][n];
   int j, q,i,L,k;
   for ( i = 1; i < n; i++)
      minMul[i][i] = 0;
   for (L = 2; L < n; L++) {
      for ( i = 1; i < n - L + 1; i++) {
         j = i + L - 1;
         minMul[i][j] = 9999;
         for ( k = i; k <= j - 1; k++) {
            q = minMul[i][k] + minMul[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
            if (q < minMul[i][j])
            minMul[i][j] = q;
         }
      }
   }
   return minMul[1][n - 1];
}
int main(){
   int arr[] = {3,4,5};
   int size = sizeof(arr) / sizeof(arr[0]);
   printf("Minimum number of multiplications required for the matrices multiplication is %d ",    MatrixChainMultuplication(arr, size));
   getchar();
   return 0;
}
