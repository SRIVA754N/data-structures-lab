// Circular List

#include <stdio.h>
#include<cstdlib>

//Structure element definition
struct element{
    int node;
    struct element* nextptr;
};

// Circular linked list definition
class CircularLinkedList{
    private:
    struct element * headptr;
    int current;

    public:
    CircularLinkedList(){
        headptr=NULL;
        current=0;
    }

    //Function prototypes
    int insertbeg(int);
    int insertend(int);
    int insertpos(int,int);
    int deletebeg();
    int deleteend();
    int deletepos(int);


    int search(int);

    int display();

};

//main function
int main(){

    class CircularLinkedList cll;
    
    //Initialisation Variables needed for the code
    int choice;
    int result;
    int value;
    int position;

    int flag=1;//flag to control the while loop

    //while loop
    while (flag!=0){
        //Menu
        printf("1.Add element at beginning\n2.Add elemnt at position\n3.Add element at end\n4.Delete element at beginning\n5.Delete element at position\n6.Delete element at end\n7.Search\n8.Display\n9.Exit\n");
        printf("Enter choice\t");
        scanf("%d",&choice);
        switch (choice){
            // Handling of all choices

            case 1:
            printf("Enter the element to be added\t");
            scanf("%d",&value);
            result=cll.insertbeg(value);
            if (result==0){
                printf("Element was not added\n");
            }
            
            break;

            case 2:
            printf("Enter the element to be added\t");
            scanf("%d",&value);
            printf("Enter the positon the element to be added\t");
            scanf("%d",&position);
            result=cll.insertpos(value,position);
            if (result==0){
                printf("Element was not added\n");
            }

            break;

            case 3:
            printf("Enter the element to be added\t");
            scanf("%d",&value);
            result=cll.insertend(value);
            if (result==0){
                printf("Element was not added\n");
            }
            break;

            case 4:
            result=cll.deletebeg();
            if (result==-1){
                printf("Linked List empty\n");
            }
            else{
                printf("%d\n",result);
            }
            break;

            case 5:
            printf("Enter the position to be removed\t");
            scanf("%d",&position);
            result=cll.deletepos(position);
            if (result==-1){
                printf("Linked List empty or position out of range \n");
            }
            else{
                printf("%d\n",result);
            }
            break;

            case 6:
            result=cll.deleteend();
            if (result==-1){
                printf("Linked List empty\n");
            }
            else{
                printf("%d\n",result);
            }
            break;

            case 7:
            printf("Enter the element to be searched\t");
            scanf("%d",&value);
            result=cll.search(value);
            if (result==-1){
                printf("Element not found\n");
            }
            else{
                printf("Element %d found at position %d\n",value,result);
            }
            break;

            case 8:
            result=cll.display();
            if (result==0){
                printf("Linked List Empty\n");
            }
    
            break;

            case 9:
            printf("CODE OVER");
            flag=0;// Flag  marking the end of while loop 
            break;

            default:
            printf("Enter a valid choice between 1 to 9\n");
            break;
        }
    }
}
// Insert at beginning function
int CircularLinkedList::insertbeg(int value){
    struct element * newnode;
    newnode=(struct element *)malloc(sizeof(struct element));
    newnode->node=value;
    if (headptr==NULL){
        
        headptr=newnode;
        newnode->nextptr=newnode;
        current+=1;
        return 1;
    }
    struct element * currnode;
    currnode=headptr;
    
    while (currnode->nextptr!=headptr){
        currnode=currnode->nextptr;
    }
    newnode->nextptr=headptr;
    headptr=newnode;
    currnode->nextptr=headptr;
    current+=1;
    return 1;
}
// Delete at beginning function
int CircularLinkedList::deletebeg(){
    if (headptr==NULL){
        return -1;
    }
    int result=headptr->node;
    if(current==1){
        headptr=NULL;
        return result;
    }

    
    struct element * currnode;
    currnode=headptr;
    while(currnode->nextptr!=headptr){
        currnode=currnode->nextptr;
    }
    currnode->nextptr=headptr->nextptr;
    headptr=headptr->nextptr;
    current-=1;
    return result;

}


// Insert at end function
int CircularLinkedList::insertend(int value){
    struct element * currnode;
    currnode=headptr;
    struct element * newnode;
    newnode=(struct element *)malloc(sizeof(struct element));
    newnode->node=value;
    while (currnode->nextptr!=headptr){
        currnode=currnode->nextptr;
    }
    newnode->nextptr=headptr;
    currnode->nextptr=newnode;
    current+=1;
        return 1;
}

// Delete at end function
int CircularLinkedList::deleteend(){
    if (headptr==NULL){
        return -1;
    }
    int result;
    if (current==1){
        result=headptr->node;
        headptr=NULL;
        current-=1;
        return result;
    }
    struct element * currnode;
    currnode=headptr;
    while(currnode->nextptr->nextptr!=headptr){
        currnode=currnode->nextptr;
    }
    result=currnode->nextptr->node;
    currnode->nextptr=headptr;
    current-=1;
    return result;
}
// Insert at position 
int CircularLinkedList::insertpos(int value,int pos){
    int result;
    if(pos<1 || pos> current+1){
        return 0;
    }

    
    else if (pos==1){
        result=insertbeg(value);
        return result;
    }
    else if (pos == current +1){
        result=insertend(value);
        return result;
    }

    // Structure elemnt to create a new node
    struct element * newnode;
    newnode=(struct element *)malloc(sizeof(struct element));
    newnode->node=value;

    // Structure elemnt to traverse the circular linked list
    struct element * currnode;
    currnode=headptr;

    for(int i=2;i<pos;i++){
        currnode=currnode->nextptr;
    }

    
    newnode->nextptr=currnode->nextptr;
    
    currnode->nextptr=newnode;
    current+=1;
    return 1;

}

// Display function
int CircularLinkedList::display(){
    if(headptr==NULL){
        return 0;
    }
    struct element * currnode;
    currnode=headptr;
    while(currnode->nextptr!=headptr){
        printf("%d\t",currnode->node);
        currnode=currnode->nextptr;
    }
    printf("%d\t",currnode->node);
}





// Delete at position
int CircularLinkedList::deletepos(int pos){
    int result;
    if (pos<1 || pos>current || current<1 ){
        return -1;
    }
    if (pos==1){
        result=deletebeg();
        return result;
    }
    else if (pos==current){
        result=deleteend();
        return result;
    }

    // Structure elemnt to traverse the Doubly linked list
    struct element * currnode;
    currnode=headptr;

    for(int i=2;i<pos;i++){
        currnode=currnode->nextptr;
    }
    result=currnode->nextptr->node;
    currnode->nextptr=currnode->nextptr->nextptr;
    current-=1;
    return result;




}

// Search function
// search function
int CircularLinkedList::search(int value){
    if (headptr==NULL){
        return -1;
    }
    
    struct element * currnode;
    currnode=headptr;

    int pos=1;
    
 
    while(currnode->nextptr!=headptr){
        if (currnode->node==value){
            return pos;
        }
        pos+=1;
        currnode=currnode->nextptr;
    }
    return -1;
}
