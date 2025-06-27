#include <stdio.h>

int main() {
    int second;
    int minute=0;
    int hour=0;
    printf("Enter a second: ");
    scanf("%d", &second);
  while( second>=60){
          minute++;
          second=second-60;
}
 while(minute>=60){
          hour++;
          minute=minute-60;
}
 printf("time is %d hours:%d min:%d second",hour,minute,second);

}
