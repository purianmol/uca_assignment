#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printBinary(int num, int bits) {
  for (int i = bits - 1; i >= 0; i--) {
    printf("%d", (num >> i) & 1);
  }
  printf("\n");
}

int convertStringToBinary(char *str) {
  int result = 0;
  for (int shift = 2; shift >= 0; shift--) {
    int charInteger = str[2 - shift];
    result = result | (charInteger << shift * 8);
  }
  return result;
}

char *divideInto6BitGroups(int combined24bits, int bytes) {
  char *base64TableLookup =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

  int mask = 63; // 6 bits mask
  char *output = malloc(5);

  for (int shifts = 3; shifts >= 0; shifts--) {
    int sixBitsGrouped = (combined24bits >> (shifts * 6)) & mask;
    output[3 - shifts] = base64TableLookup[sixBitsGrouped];
  }
  if (bytes % 3 == 2) {
    output[3] = '=';
  } else if (bytes % 3 == 1) {
    output[2] = '=';
    output[3] = '=';
  }
  output[4] = '\0';
  return output;
}

int main(int argc, char *argv[]) {
  printf("Base 64 encoding \n");
  char *input = argv[1];
  if (strlen(input) == 0 || argc == 0) {
    exit(1);
  }
  // Break into 3 bytes
  for (int i = 0; i < strlen(input); i += 3) {
    char *str = malloc(4);
    int bytes = 0;
    for (int j = i; j < i + 3; j++) {
      if (j == strlen(input)) {
        break;
      }
      str[j - i] = input[j];
      bytes++;
    }
    str[bytes] = '\0';
    // here we get str string with 3 characters
    int combinedbits = convertStringToBinary(str);
    // printBinary(combined24bits, 24);
    // Now divide te 24 bits into 4 groups of 6 bits and make the base encoding
    char *encodedValue = divideInto6BitGroups(combinedbits, bytes);
    printf("%s", encodedValue);
    free(str);
  }
  printf("\n");
  return 0;
}
