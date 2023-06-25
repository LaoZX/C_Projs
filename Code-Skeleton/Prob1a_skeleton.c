#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/* Caesar Encryption */
void CaesarEncrypt(int, char*);
/* Caesar Decryption */
void CaesarDecrypt(int, char*);

/*int checkStr(char str1[]);*/

int main(){
  char plaintext[1024];
  char ciphertext[1024];
  char decrypttext[1024];
  
  int key;

  
  printf("Input plaintext: ");
  fgets(plaintext, 1024, stdin);
  /*printf("Input ciphertext: ");
  fgets(ciphertext, 1024, stdin);*/
  
  printf("Input key (0<=key<=25): ");
  scanf("%d", &key);
  while(key>25 && key<0){
    printf("You input wrong key, please input key again: ");
    scanf("%d", &key);
  }

  
  CaesarEncrypt(key, plaintext);
  printf("Ciphertext: %s", &plaintext);
  
  strcpy(ciphertext,plaintext);
  CaesarDecrypt(key, ciphertext);
  printf("Decrypted plaintext: %s", &ciphertext);
}

void CaesarEncrypt(int key, char *plaintext){
  /*
  Encryption function that takes a key (as an integer in 0, 1, 2, … , 25) and a string (the plaintext) and returns the ciphertext. The function should only operate on the characters ‘a’, ‘b’, … ‘z’ (both upper and lower case), and it should leave any other characters, unchanged.  
  
  Arguments:
    key         : the key for Caesar encryption
    plaintext   : a string   
 
  Returns:
    ciphertext  : the encrypted text   

  Hint: 
    - You might want to use a FOR loop to iterate over all characters in the string "plaintext", then replace each character with an appropriate character selected based on the encryption key "key". 
    - Remember to check whether the character c in the ciphertext is uppercase (like A, B, C, ..) or lowercase (like a, b, c).  
  */
  char* ch = plaintext;
  int i=0;
  while(*ch != '\0'){
    if (islower(plaintext[i])) {
      plaintext[i] = (plaintext[i] - 'a' + key) % 26 + 'a';
    }
    else if (isupper(plaintext[i])) {
      plaintext[i] = (plaintext[i] - 'A' + key) % 26 + 'A';
    }
    else if (plaintext[i] ==' '){}
    i++;
    ch++;
  }
}

void CaesarDecrypt(int key, char *ciphertext){
  /*
  Decryption function that takes a key and a string (the ciphertext) and returns the plaintext (a string)
  
  Arguments:
    key           : the key for Caesar decryption
    ciphertext    : a string   
  
  Returns:
    decrypttext   : the decrypted text   

  Hint: 
    - You might want to use a FOR loop to iterate over all characters in the string "ciphertext", then replace each character with an appropriate character selected based on descryption key "key". 
    - Remember to check whether the character c in the ciphertext is uppercase (like A, B, C, ..) or lowercase (like a, b, c).  
  */
  char* ch=ciphertext;
  int i=0;
  while(*ch != '\0'){
    if(islower(ciphertext[i])){
      ciphertext[i] = (ciphertext[i] - 'a' - key + 26) % 26 + 'a';
    }
    else if (isupper(ciphertext[i])) {
      ciphertext[i] = (ciphertext[i] - 'A' - key + 26) % 26 + 'A';
    }
    else if (ciphertext[i]==' '){}
    i++;
    ch++;
  }
}