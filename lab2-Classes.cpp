#include <stdio.h>
#include<cstdlib>

class shapes{
    public:
    int l;
    int b;
    int h;
    int calcArea(int l,int b,int h){
        int area=((l*b)+(b*h)+(h*l));
        return area;
    }

};

int main(){
    int flag=1;
    while(flag!=0){
        printf("Find area of \n");
        printf("1.Square \n2.Rectangle \n3.Cube \n4.Cuboid\n5.Exit\nEnter choice\t");
        int choice;
        scanf("%d",&choice);
        shapes shape ;
        int area;
        int length;
        int breadth;
        int height;

        switch(choice){
            case 1:
            printf("Enter side length of square\t");
            scanf("%d",&length);
            shape.l=length;
            shape.b=length;
            shape.h=0;
            area=shape.calcArea(shape.l,shape.b,shape.h);
            printf("Area of square is equal to %d\n",area);
            break;

            case 2:
            printf("Enter length of rectangle\t");
            scanf("%d",&length);
            printf("Enter breadth of rectangle\t");
            scanf("%d",&breadth);
            shape.l=length;
            shape.b=breadth;
            shape.h=0;
            area=shape.calcArea(shape.l,shape.b,shape.h);
            printf("Area of rectangle is equal to %d\n",area);
            break;

            case 3:
            printf("Enter side length of cube\t");
            scanf("%d",&length);
            shape.l=length;
            shape.b=length;
            shape.h=length;
            area=2*shape.calcArea(shape.l,shape.b,shape.h);
            printf("Area of cube is equal to %d\n",area);
            break;

            case 4:
            printf("Enter length of cuboid\t");
            scanf("%d",&length);
            printf("Enter breadth of cuboid\t");
            scanf("%d",&breadth);
            printf("Enter heigth of cuboid\t");
            scanf("%d",&height);
            shape.l=length;
            shape.b=breadth;
            shape.h=height;
            area=2*shape.calcArea(shape.l,shape.b,shape.h);
            printf("Area of cuboid is equal to %d\n",area);
            break;

            case 5:
            flag=0;
            printf("Code over\n");
            break;

            default:
            printf("Enter a valid choice from above \n");
            break;

        }


}
}