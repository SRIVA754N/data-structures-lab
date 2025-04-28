/* PROGRAM FOR SEARCHING*/

#include <cstdio>
#include <cstdlib>
# include "sort.h"

// Function prototypes
void linearsearch();
void binarysearch();
void display(int len,int * list);
int * createArr(int length);


        
    
int main(){


int flag=1;
while(flag!=0){


    printf("Enter Choice \n 1.Linear search\n 2.Binay search\n  3.Exit\n ");
    int choice;
    scanf("%d",&choice);
    
    
    switch (choice){
        case 1: linearsearch();
        break;
        case 2: binarysearch();
        break;
        case 3: printf("Program code over");
        flag=0;//To mark the end of the menu
        break;
        default:printf("Enter a valid choice from above \n");
        break;


    }
}
    return 0;

}

//Function to display each element inside the array
void display(int len,int * list){
    for(int i=0;i<len;i++){
        printf("%d\t",list[i]);
    }
    printf("\n");
}

//Function to create array dynamically based on length
int * createArr(int length){
    int * list=(int *) malloc(length*sizeof(int)+1);
    
    for (int i=0;i<length;i++){
        printf("Enter element %d\t:",i+1);
        int ele;
        scanf("%d",&(list[i]));
        printf("\n");
        
    
}
return list;
}

//Function to perform linear search 
void linearsearch(){
    int len;
    printf("Enter number of elements in the array:\t");
    scanf("%d",&len);
    int * list=createArr(len);
    //algorithm for linear search
    int ele;
    printf("Enter the element to search in the list: \n");
    scanf("%d",&ele);
    int found=0;//Flag marking the occurence of the element
    for (int i=0;i<len;i++){
        if(list[i]==ele){
            printf("THe elemnet %d was found in the list at position index %d\n",ele,i);
            found=1;//Flagged as 1 meaning found
        }
    }
    if (found==0){//Case of element not inside array
        printf("The element %d was not found in the given list\n",ele);
    }
    
}

//Function to perforn binary search
void binarysearch(){
    int len;
    printf("Enter number of elements in the array:\t");
    scanf("%d",&len);
    int * list=createArr(len);
    //algorithm for binary search
    list=sortlist(len,list);
    display(len,list);
    int ele;
    printf("Enter the element to search in the list: ");
    scanf("%d",&ele);
    
    int low=0;
    int high=len-1;
    int found=0;//Flag for occurence of the element
    
    while(low<=high){
        int mid=(low+high)/2;
        if(list[mid]>ele){
            high=mid-1;
        }
        else if(list[mid]<ele){
            low=mid+1;
        }
        else{
            printf("The element %d is found at in the given array \n",ele);
            found=1;
            break;
        }
    }
    if(found==0){//Absense of element in the array
        printf("The element %d is not found inside the given list\n",ele);
    }
}

