#include <stdio.h>

/* for experimentation
struct errors {
  char error1[20];
  char error2[20];
  char error3[20];
  char error4[20];
};*/

void addString(char message[50], char *error);
int checkKey(char *key, char *error, char *letter);
int charRepeats(char key, char *letter);

char alphabet[26];
char error_message[50];
char *letter = &alphabet[0];

int main(int argc, char *argv[])
{

//struct errors Error; //experiment with this later


char *key = argv[1];
char *text = argv[2];
char *error = &error_message[0];

  if (argc == 3)
  {
    if (checkKey(key, error, letter))
    {
      printf("%s",error);
    } else {
      printf("yes!");
    }
  }
  else if (argc == 2)
  {
    printf("Please enter your KEY first, and then your TEXT. \n");
  }
  else if (argc == 1)
  {
    printf("You entered nothing! Try again. \n");
  } else
  {
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
        break;
      } else {
        letter++;
        *letter = key;
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
