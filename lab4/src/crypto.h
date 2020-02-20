/****************
Zach Lindler
zelindl
crypto.h
Section 002
Hunter Ross
*****************/

#ifndef CRYPTO_H
#define CRYPTO_H value

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

extern int P_RAND_SEED;

//Defines the header structure, with members type, w, h, and cs.
typedef struct header_t {
  char* type;
  int w, h, cs;
} header_t;

//Defines the pixel structure, with members r, g, and b.
typedef struct pixel_t {
  unsigned char r,g,b;
} pixel_t;

//Defines the image structure, which hold a double pointer to the image data.
typedef struct img_t {
  pixel_t** data;
} img_t;

//Define functions (explained in crypto.c)
void read_header(FILE* in_img, header_t* header);
void read_image(FILE* in_img, img_t* image, header_t* header);
void read_seed(FILE* seed_file, int* seed);
void sym_crypt(FILE* out_img, header_t* header, img_t* image, int mode);

// Dumb random number generator
void sp_rand(unsigned int seed);
unsigned int p_rand(unsigned int init);

#endif
