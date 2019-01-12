//mfarazsohail
//part d
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct student {


	char firstname[40];
	char lastname[40];
	int id;
	float GPA;
	int year;
};
typedef struct student Student;

int main()
{
    Student data1,data2;
    //int len=sizeof(Student);
    FILE *fp1,*fp2;
    fp1=fopen("stdInfoDA.dat","rb+");
    if(fp1==NULL)
    {
        printf("Unable to open binary file.");
        return 1;
    }
    else
    {
        while(!EOF)
        {
            while(!EOF)
            {	//fseek(fp1,sizeof(Student)*-2,SEEK_CUR);
                fread(&data1,sizeof(Student),1,fp1);
                fread(&data2,sizeof(Student),1,fp1);

                if(data1.GPA<data2.GPA)
                {
					fseek(fp1,sizeof(Student)*-2,SEEK_CUR);
                    fwrite(&data2,sizeof(Student),1,fp1);
					fwrite(&data1,sizeof(Student),1,fp1);

                }
                else
                {
					fseek(fp1,sizeof(Student)*-2,SEEK_CUR);
                    fwrite(&data1,sizeof(Student),1,fp1);
					fwrite(&data2,sizeof(Student),1,fp1);
                }
            }
        }
    }
	fclose(fp1);

	Student A;
	fp2=fopen("stdInfoDA.dat","rb");
	if(fp2==NULL)
	{
		printf("Unable to open binary file");
		return 1;
	}
	else
	{
		for(int i=0;i<5;i++)
		{
			fread(&A,sizeof(Student),1,fp2);
			printf("%s\t\t%s\t\t%d\t\t%f\t\t%d\n",A.firstname,A.lastname,A.id,A.GPA,A.year);
		}
	}

    return 0;
}
