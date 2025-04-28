#include  <stdio.h>
#include <cstdlib>

#define length 5

class ListAdt{
    private:
     int list[length];
     int current=0;
    
    public:
    int insertBeg(int);
    int insertEnd(int);
    int insertPos(int,int);
    int deleteBeg();
    int deleteEnd();
    int deletePos(int);
    int search(int);
    int rotate(int);
    int display();

    
    



 
};

int main(){
    class ListAdt list;
    int flag=1;
    int choice;
    while(flag!=0){
        printf("Enter choice \n1.Insert at Beginning\n2.Insertion at end\n3.Insertion at position\n4.Delete at beginning\n5.Delete at end\n6.Delete at position\n7.Search\n8.Display elements\n9.Rotate\n10.Exit\t ");
        scanf("%d",&choice);
        int value;
        int result;
        int pos;
        int k;
    
        switch(choice){

            case 1:
            printf("Enter the number to be added\n");
            scanf("%d",&value);
            result=list.insertBeg(value);
            if(result==0){
                printf("Element could not be added list is full\n");
            }
            break;

            case 2:
            printf("Enter the number to be added\n");
            scanf("%d",&value);
            result=list.insertEnd(value);
            if(result==0){
                printf("Element could not be added list is full\n");
            }
            break;

            case 3:
            printf("Enter the number to be added\n");
            scanf("%d",&value);
            printf("Enter the position to which elemnt is added");
            scanf("%d",&pos);
            result=list.insertPos(pos,value);
            if(result==0){
                printf("Element could not be added list is full\n");
            }
            break;

            case 4:
            result=list.deleteBeg();
            printf("%d\n",result);
            break;
            

            case 5:
            result=list.deleteEnd();
            printf("%d\n",result);
            break;


            case 6:
            printf("Enter the position to which element is Deleted");
            scanf("%d",&pos);
            result=list.deletePos(pos);
            printf("%d\n",result);
            break;

            case 7:
            printf("Enter the number to be searched\n");
            scanf("%d",&value);
            result=list.search(value);
            if(result==-1){
                printf("Element could not be found insde list\n");
            }
            else{
                printf("Element found at position %d\n",result);
            }
            break;
            

            case 8:
            result=list.display();
            break;

            case 9:
            printf("Enter the times to rotate\n");
            scanf("%d",&k);
            result=list.rotate(k);
            break;

            case 10:
            printf("Code over");
            flag=0;
            break;

            default:
            printf("Enter a valid choice between 1 to 10\n");
            break;   
        }
    }
}

int ListAdt::insertBeg(int value){
        if(current==length){
            return 0;
        }
        for (int i=current;i>0;i--){
            list[i]=list[i-1];
        }
        list[0]=value;
        current++;
        return 1;
    }

int ListAdt::insertEnd(int value){
    if(current==length){
        return 0;
    }
    list[current]=value;
    current++;
    return 1;
}

int ListAdt::insertPos(int pos,int value){
    if(pos<1 || pos>(current+1) || current==length){
        return 0;
    }
    for (int i=current;i>=pos;i--){
        list[i]=list[i-1];
    }
    list[pos-1]=value;
    current++;
    return 1;
}

int ListAdt::deleteBeg(){
    if(current==0){
        printf("List is empty\n");
    }
    int result=list[0];
    for (int i=0;i<current-1;i++){
        list[i]=list[i+1];
    }
    current--;
    return result;
}

int ListAdt::deleteEnd(){
    if(current==0){
        printf("List is empty\n");
    }
    int result=list[current-1];
    current--;
    return result;
}

int ListAdt::deletePos(int pos){
    if(pos<1 || pos>(current) || current==0){
        return -1;
    }
    int result=list[pos-1];
    for (int i=pos-1;i<current-1;i++){
        list[i]=list[i+1];
    }
    current--;
    return result;
}

int ListAdt::search(int value){
    if(current==0){
        return -1;
    }
    for (int i=0;i<current;i++){
        if(list[i]==value){
            return i+1;
        }
    }
    return -1;
}

int ListAdt::rotate(int k){
    if(current==0){
        return -1;
    }
    int temp;
    int actual=k%current;
    for (int i=0;i<actual;i++){
        temp=list[current-1];
        for (int j=current-1;j>0;j--){
            list[j]=list[j-1];
        }
        list[0]=temp;
    }
    return 1;
}

int ListAdt::display(){
    for(int i=0; i<current;i++){
        printf("%d\t",list[i]);
    }
    printf("\n");
    return 0;
    
}

