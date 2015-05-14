#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

int isLeapYear(int year)
{
	return ( year %4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getWeekday(int year, int month, int day)
{
	int Y, L, D, w;
	                   //31,28,31,30,  31, 30, 31, 31,30,  31, 30, 31
	int mdays[2][13]={{0,31,59,90,120,151,181,212,243,273,304,334,365},
	                  {0,31,60,91,121,152,182,213,244,274,305,335,366}};
	Y = year;
	
	L = (year -1) / 4 - (year -1) / 100 + (year -1) / 400;
	if( year > 0) L += 1;  
	
	D = mdays[isLeapYear(year)][month - 1] + day;
	
	w = (6 + Y + L + D - 1) % 7;
	
	return w;
}

void printCalendar(int year, int month)
{
	int i,j,weekday;
	int months[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
	                   {0,31,29,31,30,31,30,31,31,30,31,30,31}};
	
	weekday = getWeekday(year,month,1);
                  
	printf("     %4d年%2d月     \n",year,month);
	printf("日 一 二 三 四 五 六\n");
	for(i = 0; i < weekday; i++)
	{
		printf("   ");
	}
	for(j = 1; j <= months[isLeapYear(year)][month]; j++, i = (i + 1) % 7)
	{
		printf("%2d%s",j,i == 6 ? "\n":" "); 
	}
	printf("\n\n");
}

int main(int argc, char *argv[]) 
{
	int year = 1900, month = 1;
	char *tmp;
	struct tm *pSysTime;
	time_t nowtime;
	
	if(argc >= 2)
	{
		year = atoi(argv[1]);
		tmp = strstr(argv[1], "/");
		month = atoi(tmp+1);
	}
	else 
	{
		time( &nowtime );
		pSysTime = localtime( &nowtime );
		year = pSysTime->tm_year+1900;
		month = pSysTime->tm_mon + 1;
	}
	
    printCalendar(year,month);
	
	return 0;
} 
