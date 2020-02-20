/*************
NO ERRORS HERE
*************/

#ifndef CRYPTO_H
#define CRYPTO_H value

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

extern int P_RAND_SEED;

typedef struct header_t {
  char* type;
  int w, h, cs;
} header_t;

typedef struct pixel_t {
  unsigned char r,g,b;
} pixel_t;

typedef struct img_t {
  pixel_t** data;
} img_t;

void read_header(FILE* in_img, header_t* header);
void read_image(FILE* in_img, img_t* image, header_t* header);
void read_seed(FILE* seed_file, int* seed);
void sym_crypt(FILE* out_img, header_t* header, img_t* image, int mode);

// Dumb random number generator
void sp_rand(unsigned int seed);
unsigned int p_rand(unsigned int init);

#endif
