#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int arr[1000];
int insertionSort(int n){
    long int key,i,j;
    for(j=1;j<n;j++){
        key=arr[j];
        i=j-1;
        while(i>=0 && arr[i]>key){
            arr[i+1]=arr[i];
            //printf("%d\t",arr[i+1]);
            i--;
        }
        arr[i+1]=key;
    }
}

int main(){
    clock_t t;
    t=clock();
    FILE * fp;
    fp = fopen ("E:random1.txt","w");
    long int ra=0,i=0,count=0;
    srand(time(NULL));
    while(i!=1000){
        ra=rand()%100;
        fprintf (fp, "%d\n",ra);
        printf("%d\t",ra);
        i++;
    }
    fclose (fp);
    t=clock() - t;
    double required_time = ((double)t)/CLOCKS_PER_SEC;
    printf("\n\nTo execute the program required time is : %f seconds.\n\n",required_time);
   ///////////////////////////////////////////////////////////////////////////////
    long int n=0,l=0;
    fp = fopen ("E:random1.txt","r");
    while (fscanf(fp, "%d", &n)!=EOF){
        printf("%d\t",n);
        arr[l]=n;
        l++;
    }
    insertionSort(l);
    fclose(fp);

    l=0;
    printf("\n\n\t\tAfter sorting\n\n");
    fp = fopen ("E:random2.txt","w");
    while (l!=1000){
        printf(" %d ",arr[l]);
        fprintf (fp, "%d\t",arr[l]);
        l++;
    }
    fclose(fp);
    return 0;
}
