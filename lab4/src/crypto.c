/****************
Zach Lindler
zelindl
crypto.c
Section 002
Hunter Ross
*****************/

#include "crypto.h"

int P_RAND_SEED = 1;

/** NO ERRORS HERE! **/
void read_header(FILE* in_img, header_t* header) {
  header->type = malloc(sizeof(char)*3);
  fscanf(in_img, "%s ",     header->type);
  fscanf(in_img, "%d %d ", &header->w, &header->h);
  fscanf(in_img, "%d ",    &header->cs);
  printf("Header:\n%s %d %d %d\n", header->type, header->w, header->h, header->cs);
  free(header->type);
}
/********************/

/** Could be errors... **/
void read_image(FILE* input, img_t* image, header_t* header) {
  int row, col;
  image->data = malloc(sizeof(pixel_t*) * header->h);
  for(row = 0; row < header->h; row++) {
    image->data[row] = malloc(sizeof(pixel_t) * header->w * 3);
    for(col =0; col < header->w; col++) {
      pixel_t pix;
      fscanf(input, "%c%c%c", &pix.r, &pix.g, &pix.b);
      image->data[row][col] = pix;
    }
  }
}

/** NO ERRORS HERE! **/
void read_seed(FILE* seed_file, int* seed) {
  fscanf(seed_file, "%d", seed);
}

/** Could be errors... **/
void sym_crypt(FILE* output, header_t* header, img_t* image, int mode) {
  // Write header of PPM to files
  /** NO ERRORS HERE! **/
  fprintf(output, "%s %d %d %d\n", "P6", header->w, header->h, header->cs);
  /*********************/

  // Encrypt or Decrypt!
  // Could be errors...
  int row, col;
  switch (mode) {
    case 1:
      printf("Encrypt\n");
      for(row = 0; row < header->h; row++) {
        for(col = 0; col < header->w; col++) {
          int swap_row = p_rand(row*row) % header->h;
          int swap_col = p_rand(col*col) % header->w;
          pixel_t swap = image->data[row][col];
          image->data[row][col] = image->data[swap_row][swap_col];
          image->data[swap_row][swap_col] = swap;
        }
      } break;
    case 2:
      printf("Decrypt\n");
      for(row = header->h-1; row >= 0; row--) {
        for(col=header->w-1; col >= 0; col--) {
          int swap_row = p_rand(row*row) % header->h;
          int swap_col = p_rand(col*col) % header->w;
          pixel_t swap = image->data[row][col];
          image->data[row][col] = image->data[swap_row][swap_col];
          image->data[swap_row][swap_col] = swap;
        }
      } break;
    default: break;
  }

  /** NO ERRORS HERE! **/
  for(row = 0; row < header->h; row++) {
    for(col = 0; col < header->w; col++) {
      pixel_t pix = image->data[row][col];
      fprintf(output, "%c%c%c", pix.r, pix.g, pix.b);
    }
  }
  /********************/
}

/** NO ERRORS HERE! **/
void sp_rand(unsigned int seed) {
  P_RAND_SEED = seed;
}
/********************/

/** NO ERRORS HERE! **/
unsigned int p_rand(unsigned int init) {
  return (P_RAND_SEED*init) % INT_MAX;
}
/********************/
