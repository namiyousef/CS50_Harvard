#include <stdio.h>
/*
Scope: this function, given a KEY (24 letters long) and a text (without spaces), will encrypt the text based on the key

*/
void addString(char message[50], char *error);
int checkKey(char *key, char *error, char *letter);
int charRepeats(char key, char *letter);
void encrypt(char *key, char *text);

char alphabet[26];
char error_message[50];
char *letter = &alphabet[0];

int main(int argc, char *argv[])
{


char *key = argv[1]; // stores the encryption key
char *text = argv[2]; // stores the text to be encrypted
char *error = &error_message[0];

  if (argc == 3)
  {
    if (checkKey(key, error, letter))
    {
      printf("%s",error);
    } else {
      encrypt(key,text);
      printf("%s",text);
        }
  }
  else if (argc == 2){
    printf("Please enter your KEY first, and then your TEXT. \n");
  } else if (argc == 1){
    printf("You entered nothing! Try again. \n");
  } else {
    printf("You entered too many fields. Try again. \n");
  }
}

int checkKey(char *key, char *error, char *letter)
{
  int Checker = 0;
  while (*key != 0) {
    if (*key > 122 || *key < 65 || (*key > 90 && *key < 97))
    {
      Checker = 1;
      addString("You have entered an invalid key, try again!\n",error);
      break;
    } else if (charRepeats(*key,letter)) {
      Checker = 1;
      addString("You have entered a key that contains repeated characters, try again!\n",error);
      break;
    }
    key++;
  }
  return Checker;

}

int charRepeats(char key, char *letter) {

  int check = 0;

  if (*letter == 0){
    *letter = key;
  }
  else
  {
      letter = &alphabet[0];
      while (*letter != 0) {
      if (key == *letter){
        check = 1;
        *letter = key;
        break;

      } else {
        letter++;
      }

    }

  }
  return check;
  //checks if characters repeat or not! So annoying...
}
void addString(char message[50], char *error)
{
  int i = 0;
  while (message[i] != 0)
  {
    *error = message[i];
    i++;
    error++;
  }
}

void encrypt(char *key, char *text){
  /*
  Function that receives pointers for the encryption key and text to be encrypted, encrypting the latter
  */
  int adder;
  int index;

  while (*text != '\0'){

    if (*text <96){ // if text is UPPER CASE
      adder = 32;
      index = *text + adder;
    } else {
      index = *text; // this fixed segementation fault 11
      adder = 0;
    }

    if (index > 96) {
      index-=97;
      key += index;
      *text = *key - (adder - 32);
      key -= (int) index;
    }


    text++; // moves pointer of the text to be encrypted
  }

 }
