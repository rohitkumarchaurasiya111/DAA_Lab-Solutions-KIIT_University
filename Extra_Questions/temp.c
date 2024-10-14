#include <stdio.h>
#include <stdlib.h>

int binary(int n){
    if(n<2){
        if(n==0) return 0;
        else return 1;
    }
    int res = (n%2) + 10*binary(n/2);
    return res;
}

int main(){

    FILE *file;
    int n;
    file = fopen("decimal.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    fscanf(file, "%d", &n);
    int  arr[n];
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
    
    file = fopen("binary.txt", "w");
    fprintf(file, "");
    fclose(file);
   
    file = fopen("binary.txt", "a");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    for(int i=0; i<n; i++){
        int n = binary((int)arr[i]);
        fprintf(file, "The binary of %d is '%d'.\n", arr[i], n);
        printf("%d\n", n);
    }
    printf("\n");
}