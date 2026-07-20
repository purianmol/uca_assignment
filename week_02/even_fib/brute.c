#include <stdio.h>

int evensum(int num){
  int a = 1;
  int b = 1;
  int  c;
  int sum;
  while(a+b<=num){
    c = a+b;
    if(c<=num && c%2 == 0) sum+=c;
    a = b;
    b = c;
  }
  return sum;
}

int main(){
  int ans = evensum(10);
  printf("%d\n",ans);
}


