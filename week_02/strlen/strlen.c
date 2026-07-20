#include<stdio.h>

int lenstr(char* str){
  int len = 0;
  while(*str != '\0'){ 
    str+=1;
    len++;
  }  
  return len;
}

int main(){
  char str[] = "some string";
  printf("length of str is: %d\n",lenstr(str));
}
