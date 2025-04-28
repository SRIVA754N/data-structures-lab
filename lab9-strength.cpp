//Importing necessary modules
# include <stdio.h>
# include <cstdlib>
# include <vector>
# include <algorithm>

// Main function
int main(){
    int t;
    printf("Enter number of test cases\t");
    scanf("%d",&t);
    int n;

    int temp;
    std::vector <int> s;
    std::vector <int> out;
    // Loop for testcases
    for (int i=0;i<t;i++){
        s.clear();
        out.clear();
        printf("Enter n lenght of array\t");
        scanf("%d",&n);
        printf("Enter S1,S2,...Sn\t");
        printf("\n");
        int max=0;
        int max2=0;
        for (int j=0;j<n;j++){
            scanf("%d",&temp);
            if (temp>max){
                if (max>max2){
                    max2=max;
                }
                max=temp;
                
            }
            else if(temp<max && temp>max2){
                max2=temp;
            }
            s.push_back(temp);
        }
        for (int k=0;k<n;k++){
            if (s[k]==max){
                out.push_back(max-max2);
            }
            else{
                out.push_back(s[k]-max);
            }
        }
        for (int q=0;q<n;q++){
            printf("%d\t",out[q]);
        }
    }
    return 0;
}