#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
char acMainStr[200], acSrchStr[30], acRepStr[30], acResStr[200], acCopyStr[200];
int i=0, j=0 ,k=0, l, iMtchCnt, iStop, len, iNumOfMatch=0;
printf("\nEnter the main string :\n");
scanf(" %[^\n]", acMainStr);
printf("\nEnter the Pattern string :\n");
scanf(" %[^\n]", acSrchStr);
printf("\nEnter the Replace string :\n");
scanf(" %[^\n]", acRepStr);
strcpy(acCopyStr, acMainStr);
for(i=0;i<(strlen(acMainStr)-strlen(acSrchStr)+1);i++)
{
iMtchCnt = 0;
for(j=0;j<strlen(acSrchStr);j++)
{
if(acMainStr[i+j] == acSrchStr[j])
{
iMtchCnt++;
}
else
{
break;
}
if(iMtchCnt == strlen(acSrchStr)) 
{
iNumOfMatch++; 
for(k=0;k<i;k++)
{
acResStr[k] = acMainStr[k]; 
}
iStop = k + strlen(acSrchStr); 
acResStr[k] = '\0';
strcat(acResStr, acRepStr); 
len = strlen(acResStr);
for(k=iStop, l=0; acMainStr[k] != '\0';k++, l++)
    {
acResStr[len+l] = acMainStr[k];
}
acResStr[len+l] = '\0';
strcpy(acMainStr,acResStr);
}
}
}
printf("\nInput Text :\n");
printf("%s\n",acCopyStr);
if(iNumOfMatch > 0)
{
printf("\n%d matches occured\n\nText after replacing matched patterns is shown below\n", iNumOfMatch);
printf("\n%s\n",acResStr);
}
else
{
printf("\nPattern String not found in Text\n");
}
return 0;
}
