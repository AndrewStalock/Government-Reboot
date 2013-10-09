#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define BUF_SIZE 1024

int is_vowel(char c) {
   if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return 1;
   return 0;
  }

int copy_non_vowel(int num_chars, char* in_buf, char* out_buf) {
  int i;
  int j;
  int count = 0;
  int chars[num_chars];

  for(i = 0; i < num_chars; ++i) {
    int charOut = is_vowel(in_buf[i]);
    if(charOut == 0){
	count++;
    }
  chars[i] = charOut;
  }
  for(i = 0, j = 0; i < (num_chars - 1); i++){
	if(chars[i] == 0 && in_buf[i] > 0){
		out_buf[j] = in_buf[i];
		++j;
	}
  }
  return count;
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
  char inputBuffer[BUF_SIZE];
  char outputBuffer[BUF_SIZE];

  int len = fread(inputBuffer, sizeof(char), BUF_SIZE, inputFile);
  int newLength = copy_non_vowel(len, inputBuffer, outputBuffer);
  fwrite(outputBuffer, sizeof(char), newLength - 1, outputFile);
  }


int main(int argc, char *argv[]) {
  FILE *inputFile;
  FILE *outputFile;

  if(argc == 1) {
	disemvowel(stdin, stdout);
} else if (argc == 2){
	inputFile = fopen(argv[1], "r");
	disemvowel(inputFile, stdout);
} else if (argc == 3){
	inputFile = fopen(argv[1], "r");
	outputFile = fopen(argv[2], "w");
	disemvowel(inputFile, outputFile);
}

  return 0;
}
