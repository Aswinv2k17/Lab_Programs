//Structure Pointer
#include <stdio.h>

struct stu{
 char name[30];
int roll_num,age;
float marks;
}s1,*s2;

int main()
{
  int i,n;
  s2=&s1;
  printf("Enter the student details \n");
  printf("\nName: \n");
  scanf("%s",s2->name);
  printf("\nEnter the roll number:\n");
  scanf("%d",&s2->roll_num);
  printf("\nEnter age:\n");
  scanf("%d",&s2->age);
  printf("\n Enter the marks:\n");
  scanf("%f",&s2->marks);
  printf("\nStudent Details \n");
  printf("\n Name:%s\n",s2->name);
  printf("\n Roll Number:%d\n",s2->roll_num);
  printf("\n Age:%d\n",s2->age);
  printf("\n Marks:%f\n",s2->marks);
}
