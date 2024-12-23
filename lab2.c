#include <stdio.h>
#include <string.h>

int main()
{
    char st[200], srch[30], rep[30], res[200], cpy[200];
    int i=0, j=0 ,k=0, l, mtch, iStop, len, nom=0;

    printf("\nEnter the main string\n");
	scanf(" %[^\n]", st);
    printf("\nEnter the Pattern string\n");
	scanf(" %[^\n]", srch);
    printf("\nEnter the Replace string\n");
	scanf(" %[^\n]", rep);
    strcpy(cpy, st);
    for(i=0;i<(strlen(st)-strlen(srch)+1);i++)
    {
        mtch = 0;
        for(j=0;j<strlen(srch);j++)
        {
         if(st[i+j] == srch[j])
            {
                mtch++;
            }
            else
            {
                break;
            }
            if(mtch == strlen(srch))
            {
                nom++;
                for(k=0;k<i;k++)
                {
                    res[k] = st[k];
                }
                iStop = k + strlen(srch);
                res[k] = '\0';
                strcat(res, rep);
                len = strlen(res);
                for(k=iStop, l=0; st[k] != '\0';k++, l++)
                {
                    res[len+l] = st[k];
                }
                res[len+l] = '\0';
                strcpy(st,res);
            }
        }
    }
    printf("\nInput Text\n");
    printf("%s\n",cpy);
    if(nom > 0)
    {
        printf("\n%d matches occured\n\nText after replacing matched patterns is shown below\n", nom);
        printf("\n%s\n",res);
    }
    else
    {
        printf("\nPattern String not found in Text\n");
    }
    return 0;
}
