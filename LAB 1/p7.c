#include <stdio.h>

int main() {
    int day;
    int year=0;
    int week=0;
    printf("Enter a day: ");
    scanf("%d", &day);
  while( day>=7){
          week++;
          day=day-7;
}
 while(week>=52){
          year++;
         week=week-52;
}
 printf("time is %d-year:%d-week:%d-day",year,week,day);

}
