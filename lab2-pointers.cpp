
/* program for checking numbers as palindrome, armstrong,perfect number*/
#include <stdio.h>
#include<cstdlib>

bool palindrome(int * num);// Function to check for a number is palindrome or not
bool armstrong(int * num);// Function to check for a number is Armstrong or not
bool perfect(int * num);// Function to check for a number is Perfect or not

int main(){
    int * flag;
    flag=(int *)malloc(sizeof(int));
    * flag=1;
    while(*(flag)!=0){
        printf("1.Palindrome \n2.Armstrong number \n3.Perfect Number \n4.Exit\nEnter choice\t");
        int *cptr;
        cptr=(int *)malloc(sizeof(int));
        scanf("%d",cptr);
        int *num;
        num=(int *)malloc(sizeof(int));
        bool *result;
        result=(bool *)malloc(sizeof(bool));
        
        switch (*cptr){
            
            case 1:
            printf("Enter number to check for palindrome \t");
            scanf("%d",num);
            (* result)=palindrome(num);
            if(* result){
                printf("Palindrome\n");
            }
            else{
                printf("Not a palindrome\n");
            }
            break;

            case 2:
            printf("Enter number to check for armstrong \t");
            scanf("%d",num);
            (* result)=armstrong(num);
            if(* result){
                printf("Armstrong number\n");
            }
            else{
                printf("Not an Armstrong number\n");
            }
            break;

            case 3:
            printf("Enter number to check for perfect \t");
            scanf("%d",num);
            (* result)=perfect(num);
            if(* result){
                printf("Perfect number\n");
            }
            else{
                printf("Not a Perfect number\n");
            }
            break;
             
            case 4:
            (*flag)=0;
            printf("Code over\n");
            break;
            default:
            printf("Enter any one of the valid given choices\n"); 
        }
    }
}

bool palindrome(int * num){
    int * tnum;
    tnum=(int *)malloc(sizeof(int));
    (*tnum)=(* num);
    int * rnum;
    rnum=(int *)malloc(sizeof(int));
    (*rnum)=0;
    while((*tnum)>0){

        (*rnum)=((*rnum)*10)+(*tnum)%10;
        (*tnum)=(*tnum)/10;
    }
    if ((*rnum)==(*num)){
        return true;
    }
    else{
        return false;
    }  
}
    
bool armstrong(int * num){
    int * tnum;
    tnum=(int *)malloc(sizeof(int));
    *tnum=*num;

    int * cnum;
    cnum=(int *)malloc(sizeof(int));
    *cnum=*num;

    int *dig;
    dig=(int *)malloc(sizeof(int));
    *dig=0;
    
    int *summ;
    summ=(int *)malloc(sizeof(int));
    *summ=0;

    int *pow;
    pow=(int *)malloc(sizeof(int));

    while ((*cnum)>0){
        (*dig)+=1;
        (*cnum)=(*cnum)/10;
    }

    while ((*tnum)>0){
        *pow=1;
        int *i;
        i=(int *)malloc(sizeof(int));
        
        for((*i)=0;(*i)<*dig;(*i)++){
            (*pow)=(*pow)*((*tnum)%10);
        }
        (*summ)+=(*pow);
        (*tnum)/=10;
    }
    if ((*summ)==(*num)){
        return true;
    }
    else{
        return false;
    }  
}

bool perfect(int * num){
    int * tnum;
    tnum=(int *)malloc(sizeof(int));
    *tnum=*num;

    int * summ;
    summ=(int *)malloc(sizeof(int));
    *summ=0;

    int *i;
    i=(int *)malloc(sizeof(int));


    for((*i)=1;(*i)<=(*tnum)/2;(*i)++){
        if((*tnum)%(*i)==0){
            (*summ)+=(*i);
        }
    }

    if ((*summ)==(*num)){
        return true;
    }
    else{
        return false;
    }  


    


    
    
}