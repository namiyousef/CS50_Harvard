#include <stdio.h>

void checkChar(int *ptr_letters, char *ptr_punc, char *ptr_text, int *ptr_words, int *ptr_sentence);

char text[] = "ENTER YOUR TEXT HERE."; //length of letters = 8, words = 2
char punc[] = " \\/\'\".?!,:;-_{}[]()|~``^@+*$#%"; //array of all the possibile punctuation

// variables for counting the number of items
int letters = 0;
int num_words = 0;
int sentences = 0;

// setting pointers
int *ptr_letters = &letters;
char *ptr_punc = &punc[0];
char *ptr_text = &text[0];
int *ptr_words = &num_words;
int *ptr_sentence = &sentences;

int main(void){

  while (*ptr_text !=0){ //signals end of string in memory storage
    checkChar(ptr_letters, ptr_punc,ptr_text,ptr_words,ptr_sentence);
    ptr_text++; //signals a movement to the next character in the string array!
    (*ptr_letters)++;
  }

  //the grading index calculation
  double index = 5.88 * (((float) letters)/((float) num_words)) - 29.6* (((float) sentences)/((float) num_words))- 15.8;
  if (index > 16){
    printf("Grade: %i+\n",(int) index);
  } else {
    printf("Grade: %i\n",(int) index);
  }

}


void checkChar(int *ptr_letters, char *ptr_punc, char *ptr_text, int *ptr_words, int *ptr_sentence){
  while(*ptr_punc != 0){
    
    if (*ptr_text == *ptr_punc){
      (*ptr_letters)--;

      if (*ptr_text == ' ' || *(ptr_text+1) == 0){
        (*ptr_words)++;
      }

      if (*ptr_text == '.' || *ptr_text == '?' || *ptr_text == '!'){
        (*ptr_sentence)++;
      }

      break;
    }

    ptr_punc++;

  }
}
