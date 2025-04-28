//Importing necessary modules
# include <stdio.h>
# include <cstdlib>
# include <vector>
# include <unordered_set>
using namespace std;

int execute(vector <int> arr,int n);

// Main function
int main(){
    int t;
    printf("Enter number of test cases\t");
    scanf("%d",&t);
    int n;
    int out;
    int temp;
    vector <int> arr;
    
    while(t--){
        arr.clear();
        printf("Enter the number of elements\t");
        scanf("%d",&n);
        for (int i=0;i<n;i++){
            scanf("%d",&temp);
            arr.push_back(temp);
            
        }
        printf("\n");
        out=execute(arr,n);
        printf("%d\n",out);
    }
    return 0;
}

int execute(vector <int> arr,int n){
    unordered_set <int> set;
    int count=0;
    for (int i=n-1;i>=0;i--){
        if (set.count(arr[i])){
            break;
        }
        else{
            set.insert(arr[i]);
            count+=1;
        }

    }
    return n-count;
    
}