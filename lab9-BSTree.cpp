# include <stdio.h>
# include <cstdlib>

struct node{
    int data;
    struct node * left;
    struct node * right;
};

class BinSTree{
    
    public:
    struct node * root=NULL;
    struct node * insert(struct node *, int);
    struct node * inorder(struct node *);
    struct node * preorder(struct node *);
    struct node * postorder(struct node *);
    struct node * search(struct node *, int);

};

int main(){
    class BinSTree b1;
    b1.root=b1.insert(b1.root,5);
    b1.root=b1.insert(b1.root,7);
    b1.root=b1.insert(b1.root,4);
    b1.root=b1.insert(b1.root,6);
    b1.root=b1.inorder(b1.root);
    printf("\n");
    b1.root=b1.preorder(b1.root);
    printf("\n");
    b1.root=b1.postorder(b1.root);
    printf("\n");
    b1.root=b1.search(b1.root,8);
    return 0;
}
struct node * BinSTree::insert(struct node * Node,int val){
    if ( Node==NULL){
        struct node * newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=val;
        newnode->left=NULL;
        newnode->right=NULL;
        Node=newnode;
        return Node;
    }
    else if(Node->data>val){
        Node->left=insert(Node->left,val);
    }
    else{
        Node->right=insert(Node->right,val);
    }
    return Node;
}

struct node * BinSTree::inorder(struct node * Node){
    if (Node->left!=NULL){
        Node->left=inorder(Node->left);
    }
    printf("%d\t",Node->data);
    if (Node->right!=NULL){
        Node->right=inorder(Node->right);
    }
    
    return Node;
}

struct node * BinSTree::preorder(struct node * Node){
    printf("%d\t",Node->data);
    if (Node->left!=NULL){
        Node->left=preorder(Node->left);
    }
    if (Node->right!=NULL){
        Node->right=preorder(Node->right);
    }
    
    return Node;
}

struct node * BinSTree::postorder(struct node * Node){
    
    if (Node->left!=NULL){
        Node->left=postorder(Node->left);
    }
    if (Node->right!=NULL){
        Node->right=postorder(Node->right);
    }
    printf("%d\t",Node->data);
    
    return Node;
}

struct node * BinSTree::search(struct node * Node,int val){
    if (Node==NULL){
    printf("Not found");
    }
    else if (Node->data==val){
        printf("Found\n");
        return Node;
    }
    else if (Node->data>val){
        Node->left=search(Node->left,val);
    }
    else if(Node->data<val){
        Node->right=search(Node->right,val);
    }
    return Node;
}