//mfarazsohail
// part c
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

FILE *fp1,*fp2,fp3;

struct student {
    char firstname[40];
    char lastname[40];
    int id;
    float GPA;
    int year; };
typedef struct student Student;

void InputStdRecord(Student *StdList, const char *FileName);
void PrintStdList(const Student *StdList);
void SaveStdList(const Student *StdList, const char *FileName);

int main() {
    //FILE *fp1,*fp2,fp3;
    //fp1=fopen("stdInfo.txt",)
    Student StdList[5];
    InputStdRecord(StdList, "stdInfo.txt");
    PrintStdList(StdList);
    SaveStdList(StdList, "stdInfoDA.dat");
    return 0; }

void InputStdRecord(Student *StdList, const char *FileName)
{
    fp1=fopen(FileName,"r");
    if(FileName==NULL)
    {
        printf("Unable to open file");
        return 1;
    }
    else
    {
        for(int i=0;i<2;i++)
        {
            fscanf(fp1,"%s  %s  %d  %f  %d ",(StdList[i]).firstname,(StdList[i]).lastname,&(StdList[i]).id,&(StdList[i]).GPA,&(StdList[i]).year);
        }
        fclose(fp1);
    }
}

void PrintStdList(const Student *StdList)
{
    //fp2=fopen()
    for(int i=0;i<2;i++){
    //fprintf(fp2,"%s\t\t%s\t\t%d\t\t%f\t\t%d\n",(StdList[i]).firstname,(StdList[i]).lastname,(StdList[i]).id,(StdList[i]).GPA,(StdList[i]).year);
    printf("%s\t\t%s\t\t%d\t\t%f\t\t%d\n",(StdList[i]).firstname,(StdList[i]).lastname,(StdList[i]).id,(StdList[i]).GPA,(StdList[i]).year);
}
}

void SaveStdList(const Student *StdList, const char *FileName)
{
    fp2=fopen(FileName,"wb");
    if(FileName==NULL)
    {
        printf("Unable to open binary file");
        return 1;
    }
    else
    {
            fwrite(StdList,sizeof(Student),2,fp2);
    }
    fclose(fp2);
}

