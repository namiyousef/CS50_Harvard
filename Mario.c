#include <stdio.h>

void buildPyramid(int height);
void print_efficient(int row);



int size = 8;

int main(void){

  buildPyramid(size);

}


void buildPyramid(int height){

  for (int row=0; row< height; row++){

    print_efficient(row);
    printf("\n");
  }

}


void print_efficient(int row){
  int max_pos = 2*size +2;
  for (int k = 0; k<max_pos; k++){
    if ((k < size && k > size - row - 2) || (k > size + 1 && k < size + row + 3 )){
      printf("#");
    } else {
      printf(" ");
    }
  }
}
