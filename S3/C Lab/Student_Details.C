//Student Details
#include<stdio.h>

struct stu{
 char name[30];
int roll_num,age;
float marks;
}s1;

int main()
{
  int i,n;
  printf("Enter the student details \n");
  printf("\nName: \n");
  scanf("%s",s1.name);
  printf("\nEnter the roll number:\n");
  scanf("%d",&s1.roll_num);
  printf("\nEnter age:\n");
  scanf("%d",&s1.age);
  printf("\nEnter the marks:\n");
  scanf("%f",&s1.marks);
  printf("\nStudent Details \n");
  printf("\n Name:%s\n",s1.name);
  printf("\n Roll Number:%d\n",s1.roll_num);
  printf("\n Age:%d\n",s1.age);
  printf("\n Marks:%f\n",s1.marks);
}
