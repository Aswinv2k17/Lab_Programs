//Student Details
#include<stdio.h>

struct stu{
 char name[30];
int roll_num,age;
float marks;
}s[50];

int main()
{
  int i,n,k;
  printf("Enter the total number of students\n");
  scanf("%d",&n);
  for(i=0;i<n;i++);
  {
    printf("Enter the student details \n");
    printf("\nName: \n");
    scanf("%s",&s[i].name);
    printf("\nEnter the roll number:\n");
    scanf("%d",&s[i].roll_num);
    printf("\nEnter age:\n");
    scanf("%d",&s[i].age);
    printf("\nEnter the marks:\n");
    scanf("%f",&s[i].marks);
  }
  printf("\nEnter the roll number to display details\n");
  scanf("%d",&k);
  for(i=0;i<n;i++)
  {
    if(k==s[i].roll_num)
    {
      printf("\nStudent Details \n");
      printf("\n Name:%s\n",s[i].name);
      printf("\n Roll Number:%d\n",s[i].roll_num);
      printf("\n Age:%d\n",s[i].age);
      printf("\n Marks:%f\n",s[i].marks);
    }
    else
    {
      printf("Student Not Found\n");
      break;
    }
  }
}
