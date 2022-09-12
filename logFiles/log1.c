#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#pragma warning (disable:4996)

void Log(char[]);
void LogError(char[]);
void LogEvent(char[]);

int main()
{
	int num;
	char input[100], ch[100], Error[100], Event[100];
	sprintf(Event, "Program is running\n");
	LogEvent(Event);
	FILE* f = fopen("Numbers.txt", "w");
	if (!f)
	{
		sprintf(Error, "File Not Opened");
		LogError(Error);
		return 1;
	}
	
	sprintf(Event, "File has opened\n");
	LogEvent(Event);
	printf("Enter a number: ");
	scanf("%d", &num);
	
	sprintf(input, "The user has entered: %d\n",num);
	LogEvent(input);
	
	for (int i = 1; i <= num; i++)
	{
		sprintf(ch, "%d ", i);
		fputs(ch, f);
	}
	sprintf(input, "End of Program\n");
	LogEvent(input);
	return 0;
}

void Log(char str[])
{
	char Log[100];
	strcpy(Log, str);
	time_t t;
	time(&t);
	struct tm* timeInfo;
	timeInfo = localtime(&t);
	sprintf(Log,"%d %d %d: %02d:%02d:%02d- %s", timeInfo->tm_year + 1900, timeInfo->tm_mon+1, timeInfo->tm_mday,timeInfo->tm_hour,timeInfo->tm_min,timeInfo->tm_sec, str);
	FILE* f = fopen("myProg.log", "a");
	if (!f)
	{
		printf("File Error");
		exit(1);
	}
	fputs(Log, f);
	fclose(f);
}

void LogError(char str[])
{
	char Error[100];
	sprintf(Error, "Error - %s", str);
	Log(str);
}

void LogEvent(char str[])
{
	char Event[100];
	sprintf(Event,"Event - %s",str);
	Log(Event);
}