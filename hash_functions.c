#include <stdio.h>

// Complete these two functions according to the assignment specifications

void hash(char *hash_val, long block_size) {
  //hash_val = malloc(sizeof(char) * block_size);
  for(int i = 0; i<block_size;i++){
    hash_val[i] = '\0';
  }
  char hs;
  int j =0;
  while(scanf("%c", &hs) != EOF){
    if(j>=block_size){
      j=0;
    }
    hash_val[j] = hash_val[j] ^ hs;
    j++;
  }
}


int check_hash(const char *hash1, const char *hash2, long block_size) {
  int index=block_size;

  for(int i =0;i<block_size;i++){
    if(hash1[i] != hash2[i]){
      index = i;
      break;
    }
  }

  return index;


    // A place holder so that the file will compile without error.
	// Replace with the correct return value.
}
