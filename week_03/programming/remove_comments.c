#include <stdio.h>

int main() {
  int c;
  int s_quote = 0;
  int d_quote = 0;
  int block_cmt = 0;
  int line_cmt = 0;
  int escape = 0;

  while ((c = getchar()) != EOF) {
    if (block_cmt) {
      if (c == '*') {
        int next = getchar();
        if (next == '/') {
          block_cmt = 0;
        } 
        else if (next != EOF) {
          ungetc(next, stdin);
        }
      }
    } 
    else if (line_cmt) {
      if (c == '\n') {
        line_cmt = 0;
        putchar(c);
      }
    } 
    else if (s_quote || d_quote) {
      putchar(c);
      if (escape) {
        escape = 0;
      } 
      else if (c == '\\') {
        escape = 1;
      } 
      else if (s_quote && c == '\'') {
        s_quote = 0;
      } 
      else if (d_quote && c == '"') {
        d_quote = 0;
      }
    } 
    else {
      if (c == '/') {
        int next = getchar();
        if (next == '*') {
          block_cmt = 1;
        } 
        else if (next == '/') {
          line_cmt = 1;
        } 
        else {
          putchar(c);
          if (next != EOF) {
            ungetc(next, stdin);
          }
        }
      } 
      else {
        if (c == '\'') {
          s_quote = 1;
        } 
        else if (c == '"') {
          d_quote = 1;
        }
        putchar(c);
      }
    }
  }
  
  return 0;
}
