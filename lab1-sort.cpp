/* PROGRAM FOR SORTING*/

#include <cstdio>
#include <cstdlib>

// Function prototypes
void bubblesort();
void insertionsort();
void selectionsort();
int * sortlist(int len,int * list);
void display(int len,int * list);
int * createArr(int length);


        
    
int main(){


int flag=1;// Flag to mark the code flow
while(flag!=0){


    printf("Enter Choice \n 1.Bubble sort\n 2.Insertion sort\n 3.Selection sort\n 4.Exit\n ");
    int choice;
    scanf("%d",&choice);
    
    
    switch (choice){
        //Menu driven algorithm based on user's choice
        case 1: bubblesort();
        break;
        case 2: insertionsort();
        break;
        case 3: selectionsort();
        break;
        case 4:
        printf("Code ends");
         flag=0;
        //Marking the end of the code.
        break;
        default:printf("Enter a valid choice from above \n");
        break;


    }
}
    return 0;

}

// Function to display contents on the list
void display(int len,int * list){
    for(int i=0;i<len;i++){
        printf("%d\t",list[i]);
    }
    printf("\n");
}

// Function to create array dynamically(based on length)
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

// Function to perform bubblesort
void bubblesort (){
    int len;
    printf("Enter number of elements in the array:\t");
    scanf("%d",&len);
    int * list=createArr(len);
    display(len,list);
    // Bubble sorting algorithm
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-i-1;j++){
            if(list[j+1]<list[j]){
                int temp=list[j+1];
                list[j+1]=list[j];
                list[j]=temp;
            }
            display(len,list);// Function called to display array after each iteration
        }
        
    }
    
}

// Function to perform insertion sort
void insertionsort(){
    int len;
    printf("Enter number of elements in the array:\t");
    scanf("%d",&len);
    int * list=createArr(len);
    display(len,list);
    //Insertion sort algorithm
    for (int i=1;i<len;i++){
        int key=list[i];
        int j=i-1;
        while ((j>=0) && list[j]>key){
            list[j+1]=list[j];
            j=j-1;

        }
        list[j+1]=key;
        display(len,list);//Function called to display array after each iteration
        
        
        
    }
    
    
}

// Function to perform selection sort
void selectionsort(){
    int len;
    printf("Enter number of elements in the array:\t");
    scanf("%d",&len);
    int * list=createArr(len);
    display(len,list);
    //Insertion sort algorithm
    for (int i=0;i<len;i++){
        int min=i;
        for (int j=i+1;j<len;j++){
            
            if(list[min]>list[j]){
                min=j;printf("\n");
            }
    
    int temp=list[i];
    list[i]=list[min];
    list[min]=temp;
        }       
    display(len,list);// Functioncalled to display array after each iteration
    
    
    }
    
}


