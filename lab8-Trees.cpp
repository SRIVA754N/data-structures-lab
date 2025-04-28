#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Tree {
private:
    struct Node {
        Node *left;
        int data;
        Node *right;
    };

public:
    Node *root;

    Tree() {
        root = NULL;
    }

    Node* create();
	void inorderdisplay(Node *root);
    void preorderdisplay(Node *root);
    void postorderdisplay(Node *root);
    vector<vector<int>> levelorderdisplay(Node *root);
    void search(int n, Node *root);
};

Tree::Node* Tree::create() {
    int data;
    cout << "Enter data (-1 for NULL): ";
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    Node *newnode = new Node();  // Use `new` instead of `malloc`
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    cout << "Enter the left child of " << data << endl;
    newnode->left = create();

    cout << "Enter the right child of " << data << endl;
    newnode->right = create();

    return newnode;
}

void Tree::preorderdisplay(Node *root)
{
    if (root == NULL) 
    {
        return ;
    }
    cout<<root->data<<" ";
    preorderdisplay(root->left);
    preorderdisplay(root->right);
}
void Tree::postorderdisplay(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderdisplay(root->left);
    postorderdisplay(root->right);
    cout<<root->data<<" ";
}
void Tree::inorderdisplay(Node *root) {
	if (root == NULL) {
		return;
	}
	inorderdisplay(root->left);
	cout << root->data << " ";
	inorderdisplay(root->right);
}



void Tree::search(int n, Node *root) {
    Node *temp = root;
    //Using Inorder Traversal
    if(root==nullptr)
    {
        return;
    }else{
        search(n,root->left);
        if(root->data==n)
        {
            cout<<"Element found";
            return;
        }
        search(n,root->right);
    }

}
int main()
{
    Tree t;
    int ch;

    while (true) {
        cout << "\n1. Create Tree\n2. Display Inorder\n3. Display Preorder\n4. Display Postorder\n6. Search\n7. Exit\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                t.root = t.create(); 
                break;

            case 2:
                cout << "Inorder Traversal: ";
                t.inorderdisplay(t.root);
                cout << endl;
                break;
            case 3:
                cout << "Preorder Traversal: ";
                t.preorderdisplay(t.root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder Traversal: ";
                t.postorderdisplay(t.root);
                cout << endl;
                break;
      

            case 5:
                int n;
                cout << "Enter the element to be searched: ";
                cin >> n;
                t.search(n,t.root);
                return 0;

            default:
                cout << "Invalid choice! Try again." << endl;
                exit(0);
        }
    }

    return 0;
}