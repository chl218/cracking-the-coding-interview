/* 5.2   Binary to String: Given a real number between 0 and 1 (e.g., 0.72) that
 *       is passed in as a double, print the binary representation. If the
 *       number cannot be represented accurately in binary with at most 32
 *       characters, print "ERROR".
 *
 **/

#include <stdio.h>
#include <string>

void binary_to_string(double num) {
   if(num < 0 || num > 1) {
      printf("ERROR\n");
      return;
   }

   std::string str = "0.";
   
   while(num > 0) {
      if(str.length() > 32) {
         printf("ERROR\n");
         return;
      }

      double val = num * 2;
      if(val >= 1) {
         str.append("1");
         val = val - 1;
      }
      else {
         str.append("0");
      }
      num = val;
   }

   printf("%s\n", str.c_str());
}

int main() {

   binary_to_string(0.625);
   binary_to_string(0.75);
   binary_to_string(0.123);
   binary_to_string(0.73046875);
   return 0;
}
 
