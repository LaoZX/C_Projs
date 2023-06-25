#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>

struct incidence_pair{         
  char c[26];                                        // Letter in the cipher text
  double freq[26];                                   // Incidence percentage of each letter
};
  
struct incidence_pair getIncidence(char*);           // Computing a histogram of the incidence each letter (ignoring all non alphabet characters)
char* monoalphabetic_substitution(char*, char*);     // Takes a partial mono-alphabetic substitution (subs)  and a ciphertext and returns a potential plaintext

int main(int argc, char *argv[]){
  /*
  You don't need to edit the main() function in this assignment. 
  */
  
  char ciphertext[1024] = "ztmn pxtne cfa peqef kecnp cjt tmn zcwsenp ontmjsw ztnws tf wsvp xtfwvfefw, c feb fcwvtf, xtfxevqea vf gvoenwk, cfa aeavxcwea wt wse rntrtpvwvtf wscw cgg lef cne xnecwea eymcg";
  char plaintext[1024] = "";
  char subs[26] = "";

  struct incidence_pair ip = getIncidence(ciphertext);

  if(argc != 2){
    printf("Not enough or too many arguments!\n");
    exit(1);
  }
  strcpy(subs, argv[1]);
  if(strcmp(subs, "") == 0){
    for(int i = 0; i < 26; i++)
      printf("%c:%5f\n", ip.c[i], ip.freq[i]);
  }

  strcpy(plaintext, monoalphabetic_substitution(ciphertext, subs));
  printf("Potential Plaintext: %s\n", plaintext);
  return 0;
}

struct incidence_pair getIncidence(char *ciphertext){
  /*
  Implement a C function that performs frequency attacks on a mono-alphabetic substitution ciphers. 
  This function should take a ciphertext string compute a histogram of the incidence each letter (ignoring all non-alphabet characters.) and return a list of pair (letter, incidence percentage) sorted by incidence percentage.

  Arguments: 
      ciphertext    : a string, the ciphertext to be cracked. 
  
  Returns: 
      ip            : a struct object of type incidence_pair that you defined in the beginning of this file. 

  Hint: 
    - For sorting, you might want to use the qsort() function in C (the quick sort algorithm). 
    - Beside that, you can also use any other function for sorting or re-implement a simple sorting algorithm if you want. 
  */
}

char* monoalphabetic_substitution(char *ciphertext, char *subs){
  /*
  Implement a C function that takes a partial mono-alphabetic substitution (i.e., subs in Problem2) and a ciphertext and returns a potential plaintext.
  
  The partial mono-alphabetic substitution should be specified as a 26-character string where
    - the character at position i is the substitution of ith character of the alphabet, 
    - OR an underscore ‘_’ if the corresponding substitution is unknown. 
  The potential plaintext should be the ciphertext with values specified by the mono-alphabetic substitution replaced by the lower-case plaintext. 
  If the corresponding character is unknown (i.e. ‘_’ in the monoalphabetic substitution cipher) print the ciphertext as an uppercase character.)

  Arguments: 
      ciphertext      : a string, the ciphertext to be "cracked"
      subs            : a string, the partial mono-alphabetic substitution (the subs in Problem 2)
  
  Returns: 
      plaintext       : the potential plaintext 

  Hint: 
    - You might want to use a FOR loop to iterate over all characters in the ciphertext and replace each one by an appropriated character selected based on the substitution rule "subs". 

  */
}
