//mfarazsohail
//a
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct student {
  char firstname[40];
  char lastname[40];
  int id;
  float GPA;
  int year;
};
typedef struct student Student;

void InputStdRecord(Student *StdList)
{
  for(int i=0;i<5;i++)
  {
    printf("Write the firstname of student %d:",i+1);
    scanf("%s",(StdList[i]).firstname);
    printf("Write the lastname of student %d:",i+1);
    scanf("%s",(StdList[i]).lastname);
    printf("Write the student id of student %d:",i+1);
    scanf("%d",&(StdList[i]).id);
    printf("Give GPA of the student %d:",i+1);
    scanf("%f",&(StdList[i]).GPA);
    printf("Start Year of student %d:",i+1);
    scanf("%d",&(StdList[i]).year);
  }
}

void PrintStdList(const Student *StdList)
{
  printf("Firstname \t Lastname \t ID \t GPA \t Year \n");
  for(int i=0;i<5;i++)
  {
    printf("%s\t\t%s\t\t%d\t\t%f\t\t%d\n",(StdList[i]).firstname,(StdList[i]).lastname,(StdList[i]).id,(StdList[i]).GPA,(StdList[i]).year);
  }
}

void SaveStdList(const Student *StdList,const char *FileName)
{
  FILE *fp;
  fp=fopen("stdInfo.txt","w");
  if(FileName==NULL)
  {
    printf("Unable to open file.\n");
  }
  else
  {
    for(int i=0;i<5;i++)
    {
      fprintf(fp,"%s\t\t%s\t\t%d\t\t%.2f\t\t%d\n",(StdList[i]).firstname,(StdList[i]).lastname,(StdList[i]).id,(StdList[i]).GPA,(StdList[i]).year);
    }
  }
  fclose(fp);
}

int main()
{
  Student StdList[5];
  InputStdRecord(StdList);
  PrintStdList(StdList);
  SaveStdList(StdList,"stdInfo.txt");
  return 0;
}
