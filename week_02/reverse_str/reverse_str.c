#include <stdio.h>
#include <string.h>
void reverse_string(char *str){
  int len = strlen(str);
  char* s = str;
  char* e = str+len-1;
  while(s<e){
    char temp = *s;
    *s = *e;
    *e = temp;
    s++;
    e--;
  }
}

int main(){
  char str[] = "Data Structures";
  printf("Input: %s\n",str);
  reverse_string(str);
  printf("Output: %s\n",str);
}

