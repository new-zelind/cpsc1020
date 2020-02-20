/****************
Zach Lindler
zelindl
lab3.c
Section 002
Hunter Ross
*****************/

#include "src/crypto.h"

int main(int argc, char const *argv[]) {

  //Open the scrambled image, the key, and create an output ppm file
  FILE* image_file  = fopen(argv[1], "r");
  FILE* key_file    = fopen(argv[2], "r");
  FILE* out_image   = fopen(argv[3], "w");

  // Read image
  header_t header;
  img_t img;
  read_header(image_file, &header);
  read_image(image_file, &img, &header);

  // Read secret key
  int seed;
  read_seed(key_file, &seed);
  sp_rand(seed);

  //Ask the user if they want to encrypt or decrypt, then run the sym_crypt
  //function appropriately.
  /** NO ERROR HERE **/
  printf("Encrypt[1] or Decrypt[2]?\n");
  int choice;
  while(true) {
    scanf("%d",&choice);
    if(choice == 1 || choice == 2) {
      sym_crypt(out_image, &header, &img, choice);
      break;
    } else {
      printf("Please enter 1 or 2\n");
    }
  }
  /********************/

  //Close the scrambled image, key, and decrypted image files.
  fclose(image_file);
  fclose(key_file);
  fclose(out_image);

  //End program
  return 0;
}
