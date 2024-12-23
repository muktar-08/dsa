#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
char acMainStr[200],acSrchstr[30],acRepstr[200],acResstr[200],acCpystr[200];
int i=0,j=0,k=0,l,iMtchcnt,iStop,len,iNumofMatch;
prinf("Enter the main string\n");
scanf("%[^\n]",acMainStr);
printf("Enter the pattern string\n");
scanf("%[^\n]",acSrchstr);
printf("Enter the replace string :");
scanf("%[^\n]",acRepstr);
strcpy(acCpystr,acMainStr);
for(i=0;i<(strlen(acMainStr)-strlen(acSrchstr)+1);i++)
{
    iMtchcnt=0;
    for(j=0;j<strlen(acSrchstr);j++)
    {
        if(acMainStr[i+j]==acSrchstr[j])
        {
            iMtchcnt++;
        }
        else{
            break;
        }
        if(iMtchcnt==strlen(acSrchstr))
        {
            iNumofMatch++;
            for(k=0;k<i;k++)
            {
                acRepstr[k]=acMainStr[k];
            }
            iStop=k+strlen(acSrchstr);
            acResstr='\0';
            strcat(acResstr,acRepstr);
            for(k=iStop,l=0;acMainStr!='\0';k++,l++)
            {
                acResstr[len+1]=acMainStr[k];
            }
            acResstr[len+1]='\0';
            strcpy(acMainStr,acResstr);
        }
        printf("\nInput Text:\n");
        printf("%s",acCpystr);
        if(iNumofMatch>0)
        {
            printf("%d Number of matches found\n\nThe text after replacing the is %s",iNumofMatch,acResstr);
        }
        else{
            printf("Pattern Not Found");
        }
    
    }
}
}