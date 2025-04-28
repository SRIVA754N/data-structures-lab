//Importing necessary modules
#include <iostream>
#include <stdio.h>
# include <cstdlib>
# include <vector>
# include <cstring>
# include <string>
using namespace std;

void execute(int n);


// Main function
int main(){
    int t;
    cout << "Enter number of test cases\t";
    cin >> t;
    int n;

    
    while(t--){
        cout << "Enter the number of words\t";
        cin >> n;
        execute(n);
        
    }
    return 0;
}

void execute(int n){
    
    
    vector <string> arr1;
    vector <string> arr2;
    vector <string> arr3;

    string s;
    

    int points1=0;
    int points2=0;
    int points3=0;

    char temp[3];

    cout << "Enter the words for player 1\n";

    for (int i=0;i<n;i++){         
            cin >> temp;
            s=temp;
            
            arr1.push_back(s);
            
            }
    cout << arr1[0] << arr1[1] << arr1[2]<< '\n';

    cout << "Enter the words for player 2\n";

    for (int i=0;i<n;i++){
            cin >> temp;
            s=temp;
            arr2.push_back(s);
          
   
            }
    cout << arr2[0] << arr2[1] << arr2[2] << '\n';

    cout << "Enter the words for player 3\n";
    for (int i=0;i<n;i++){
            cin >> temp;
            s=temp;
            arr3.push_back(s);
   
            }
    cout << arr3[0] << arr3[1] << arr3[2] << '\n';
    int f1;
    int f2;
    int f3;

    //points for player 1
    for(int i=0;i<n;i++){
        
        cout <<"Checking for player 1\n";
        f2=0;
        f3=0;
        for (int j=0;j<n;j++){
            if (arr1[i]==arr2[j]){
                f2=1;
                printf("Encountered with player 2\n");
                break;
            }
        for (int j=0;j<n;j++){
            if (arr1[i]==arr3[j]){
                f3=1;
                printf("Encountered with player 3\n");
                break;
            }
        }
        printf("%d %d \n",f2,f3);
        if ((f2+f3) ==0){
            points1+=3;
        }
        else if ((f2+f3)==1){
            points1+=1;
        }
        }
    }
    //points for player 2
    for(int i=0;i<n;i++){
        f1=0;
        f3=0;
        for (int j=0;j<n;j++){
            if (arr2[i]==arr1[j]){
                f1=1;
                break;
            }
        for (int j=0;j<n;j++){
            if (a){
                f3=1;
                break;
            }
        }
        if ((f1+f3) ==0){
            points2+=3;
        }
        else if ((f1+f3)==1){
            points2+=1;
        }
        }
    }
    //points for player 3
    for(int i=0;i<n;i++){
        f2=0;
        f1=0;
        for (int j=0;j<n;j++){
            if (strcmp(arr3[i],arr2[j])){
                f2=1;
                break;
            }
        for (int j=0;j<n;j++){
            if (strcmp(arr3[i],arr1[j])){
                f1=1;
                break;
            }
        }
        if ((f2+f1) ==0){
            points3+=3;
        }
        else if ((f2+f1)==1){
            points3+=1;
        }
        }
    }
    printf("%d %d %d",points1,points2,points3); 
}