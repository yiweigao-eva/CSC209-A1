#include <stdio.h>
#include <stdlib.h>


// Hash manipulation functions in hash_functions.c
void hash(char *hash_val, long block_size);
int check_hash(const char *hash1, const char *hash2, long block_size);

#ifndef MAX_BLOCK_SIZE
    #define MAX_BLOCK_SIZE 1024
#endif

/* Converts hexstr, a string of hexadecimal digits, into hash_val, an an
 * array of char.  Each pair of digits in hexstr is converted to its
 * numeric 8-bit value and stored in an element of hash_val.
 * Preconditions:
 *    - hash_val must have enough space to store block_size elements
 *    - hexstr must be block_size * 2 characters in length
 */

void xstr_to_hash(char *hash_val, char *hexstr, int block_size) {
    for(int i = 0; i < block_size*2; i += 2) {
        char str[3];
        str[0] = hexstr[i];
        str[1] = hexstr[i + 1];
        str[2] = '\0';
        hash_val[i/2] = strtol(str, NULL, 16);
    }
}

// Print the values of hash_val in hex
void show_hash(char *hash_val, long block_size) {
    for(int i = 0; i < block_size; i++) {
        printf("%.2hhx ", hash_val[i]);
    }
    printf("\n");
}


int main(int argc, char **argv) {
    char hash_val[MAX_BLOCK_SIZE] = {'\0'};
    long block_size;
    char hv[MAX_BLOCK_SIZE] = {'\0'};

    if(argc <= 3 && argc>=2){  //no more than two arguments,
      //The first argument is required and should be an integer representing the “block size”:
      //the number of bytes that the computed hash should be.
      //The second argument is optional and is a string of hexadecimal digits representing a hash value.
      block_size = strtol(argv[1], NULL, 10);
      if(block_size <= 0 || block_size > MAX_BLOCK_SIZE){
        printf(" The block size should be a positive integer less than %d.", MAX_BLOCK_SIZE);
      }
      else{
        hash(hash_val, block_size);
        show_hash(hash_val,block_size);
        if(argc == 3){
          xstr_to_hash(hv, argv[2], block_size);
          check_hash(hash_val, hv, block_size);
        }
      }
    }
    else{
      printf("Usage: compute_hash BLOCK_SIZE [ COMPARISON_HASH ]");
    }

    return 0;
}
