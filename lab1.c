#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NUM_DAYS_IN_WEEK 7
typedef struct
{
char *acDayName;
int iDate;
char *acActivity;
} DAYTYPE;
void fnFreeCal (DAYTYPE *);
void fnDispCal (DAYTYPE *);
void fnReadCal (DAYTYPE *);
DAYTYPE *fnCreateCal();
int main()
{
DAYTYPE *weeklyCalendar = fnCreateCal();
fnReadCal (weeklyCalendar);
fnDispCal (weeklyCalendar);
fnFreeCal (weeklyCalendar);
return 0;
}
DAYTYPE *fnCreateCal ()
{
DAYTYPE *calendar = (DAYTYPE *)malloc( NUM_DAYS_IN_WEEK *sizeof(DAYTYPE));
for (int i = 0; i < NUM_DAYS_IN_WEEK; i++)
{
calendar[i].acDayName = NULL;
calendar[i].iDate = 0;
calendar[i].acActivity = NULL;
}
return calendar;
}
void fnReadCal (DAYTYPE *calendar)
{
char cChoice;
for (int i = 0; i < NUM_DAYS_IN_WEEK; i++)
{
printf("Do you want to enter details for day %d [Y/N]: ", i + 1);
scanf("%c", &cChoice);
getchar();
if (tolower(cChoice) == 'n')
continue;
printf("Day Name: ");
char nameBuffer[50];
scanf("%s", &nameBuffer);
calendar[i].acDayName = strdup (nameBuffer);
printf("Date: ");
scanf("%d", &calendar[i].iDate);
printf("Activity: ");
char activityBuffer[100];
scanf("%S", &activityBuffer); 
calendar[i].acActivity = strdup (activityBuffer);
printf("\n");
getchar(); 
}
}
void fnDispCal (DAYTYPE *calendar)
{
printf("\nWeek's Activity Details:\n");
for (int i = 0; i < NUM_DAYS_IN_WEEK; i++)
{
printf("Day %d:\n", i + 1);
if (calendar[i].iDate == 0)
{
printf("No Activity\n\n");
continue;
}
printf(" Day Name: %s\n", calendar[i].acDayName);
printf(" Date: %d\n", calendar [i].iDate);
printf(" Activity: %s\n\n", calendar[i].acActivity);
}
}
void fnFreeCal (DAYTYPE *calendar)
{
for(int i = 0; i < NUM_DAYS_IN_WEEK; i++)
{
free (calendar[i].acDayName);
free (calendar[i].acActivity);
}
free(calendar);
}