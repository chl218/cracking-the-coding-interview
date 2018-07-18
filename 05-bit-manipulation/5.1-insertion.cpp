/* 5.1 Insertion: You are given two 32-bit numbers, N and M, and two bit
 *     positions, i and j. Write a method to insert M into N such that M starts
 *     at bit j and ends at bit i. you can assume that the bits j through i
 *     have enough space to fit all of M. That is, if M = 10011, you can assume
 *     that there are at least 5 bits between j and i. You would not, for
 *     example, have j = 3 and i = 2, becaue M could not fully fit between bit
 *     3 and bit 2.
 *
 *     EXAMPLE:
 *
 *     Input:  N = 10000000000, M = 10011, i = 2, j = 6
 *     Output: N = 10001001100
 *
 **/


#include <stdlib.h>
#include <stdio.h>

void print_bits(int num, int amt) {
   for(int i = amt-1; i >= 0; i--) {
      int mask = 1 << i;
      int bit = (num & mask) >> i;
      printf("%d", bit);
   }
   printf("\n");
}

int insertion(int N, int M, int i, int j) {
   int n = j - i + 1;
   int mask = 0;
  
   // create n amount of 1s 
   for(int ii = 0; ii < n; ii++) {
      mask = (mask << 1) | 1;
   }

   // shift the mask bits into place and reverse bits for AND operation
   mask = ~(mask << i);
   
   // clear masked bits in N, OR with M shifted into the correct position 
   return (N & mask) | (M << i);
}


int main() {
   int N = 0b10000000000;
   int M = 0b10011;
   int i = 2;
   int j = 6;

   printf("N: "); print_bits(N, 11);
   printf("M: "); print_bits(M, 5);
   
   printf("Result: "); print_bits(insertion(N, M, i, j), 11);

   return 0;
}
