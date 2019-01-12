//mfarazsohail
//part b

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct student {
  char firstname[40];
  char lastname[40];
  int id;
  float GPA;
  int year;
};
typedef struct student Student;



void wordCap(char *word)
{
    while(*word!='\0')
	{
		if(*word>='a' && *word<='z')
		{
			*word = *word - 32;
		}
		word++;
	}

}

int main()
{
    Student StudentList[5];
    FILE *pf;
    pf=fopen("stdInfo.txt","r");
    if(pf==NULL)
    {
        printf("Unable to open file");
        return 1;
    }
    else
    {
        for(int i=0;i<5;i++){
        fscanf(pf,"%s  %s  %d  %f  %d ",(StudentList[i]).firstname,(StudentList[i]).lastname,&(StudentList[i]).id,&(StudentList[i]).GPA,&(StudentList[i]).year);
        wordCap((StudentList[i]).firstname);
        wordCap((StudentList[i]).lastname);
        //fprintf(pf,"%s\t\t%s\t\t%d\t\t%f\t\t%d\n",(StudentList[i]).firstname,(StudentList[i]).lastname,(StudentList[i]).id,(StudentList[i]).GPA,(StudentList[i]).year);
        //printf("%s \t\t %s \t\t %d \t\t %f \t\t %d \n",(StudentList[i]).firstname,(StudentList[i]).lastname,(StudentList[i]).id,(StudentList[i]).GPA,(StudentList[i]).year);
    }
    }
    fclose(pf);

    FILE *pf2;
    pf2=fopen("stdInfo.txt","w");
    if(pf2==NULL)
    {
        printf("Unable to open file");
        return 1;
    }
    else
    {
        for(int i=0;i<5;i++){

            fprintf(pf,"%s\t\t%s\t\t%d\t\t%f\t\t%d\n",(StudentList[i]).firstname,(StudentList[i]).lastname,(StudentList[i]).id,(StudentList[i]).GPA,(StudentList[i]).year);
            printf("%s\t\t%s\t\t%d\t\t%f\t\t%d\n",(StudentList[i]).firstname,(StudentList[i]).lastname,(StudentList[i]).id,(StudentList[i]).GPA,(StudentList[i]).year);
        }
    }
    fclose(pf2);


    return 0;
}
