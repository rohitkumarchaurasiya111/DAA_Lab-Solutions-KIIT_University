#include<stdio.h>
int main(){
    int arr[] = {5,9,0,-3,8};
    int n=5;
    int key = -3;

    for(int i=0; i<n;i++){
        if (arr[i] == key)
        {
            printf("%d is in %d index\n",key,i);
        }
    }
}