#include <stdio.h>


int countDigits(long number);
void checkCardType(long number);
void checksum(int length,long number);


long card = 4003600000000014;
int main(void){

  int digits = countDigits(card);

  printf("%i digits \n",digits);
  printf("Card number = %li \n",card);
  checksum(digits,card);
}






void checkCardType(long number){
  /* finds type of card */
    if (number == 51 || number == 52 || number == 53 || number == 54 || number == 55){
      printf("Card is of type 'MasterCard'");
    } else if (number == 34 || number == 37){
      printf("Card is of type American Express");
    } else {
      number = number/10;
      if (number == 4){
        printf("Card is of type Visa");
      } else {
        printf("Bogus Card ");
      }
    }
}


void checksum(int length,long number){
  /* calculates checksum based on Luhn's algorithm */
  int odds=0;
  int evens=0;
  for (int i=0; i<length; i++){
    if (i%2==0){
      odds = odds + number%10;
    } else {
      int products = 2*(number%10);
      int prod_length = countDigits(products);
      for (int j = 0; j<prod_length; j++){
        evens = evens + products%10;
        products = products/10;
      }
    }
    number = number/10;
}


if ((evens+odds)%10==0){
  printf("Valid, checksum = %i",evens+odds);
} else{
  printf("Invalid, checksum = %i",evens+odds);
}
}


int countDigits(long number){
  /* counts the length of the card */
  int num_digits = 0;
  while (number != 0){
    number = number/10;
    if (number < 100 && number > 10){
    checkCardType(number);
    printf("\n");
  }
    num_digits++;
  }
  return num_digits;
}
