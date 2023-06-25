#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<ctype.h>
void CaesarEncrypt(int, char*);
char* CaesarDecrypt(int, char*);
void BruteForceAttack(char*, char*); 

int main(){
 
  char ciphertext[1024];  
  char keyword[1024];

  /*
    Get the ciphertext and the keyword from keyboard. 
    If keyword is not specified (no keyword), press ENTER.
    
    Hint: 
      - You might want to use the gets() function to get a string from keyboard.
  */
  printf("Input ciphertext: ");
  fgets(ciphertext, 1024, stdin);

  printf("Input keyword: ");
  fgets(keyword, 1024, stdin);

  BruteForceAttack(ciphertext, keyword);
  return 0;

}

void CaesarEncrypt(int key, char *plaintext){
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

char* CaesarDecrypt(int key, char *ciphertext){
  printf("ciphertext: %s", ciphertext);
  
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
  return ciphertext;
}

void BruteForceAttack(char *ciphertext, char *keyword){
  /*
  Brute force attack function that takes a ciphertext (string) and a keyword (string). 
  If the keyword is null, print all the keys and associated decryptions. 
  Otherwise, the function should only print out potential plaintexts that contain that keyword.
  
  Hint: 
    - You might want to use a FOR/WHILE loop to check all possible key (recall that 1 <= key <= 25). 
    - You should call the function CaesarDecrypt() many times to make the Brute Force attack. 
    - To check whether the potential plaintext contains the keyword, you might want to use the strstr() function.
  */
 char plain[1024];
 int key;
 if(keyword == NULL || keyword[0] == '\n'){
  for(int i = 1; i <=25; i++){
    strcpy(plain, CaesarDecrypt(i, ciphertext));
    printf("Plaintext after decryption with key=%d : %s\n", i, plain);
    CaesarEncrypt(i,ciphertext);
  }
 }
 else{
  for(key = 1; key <=25; key++){
    strcpy(plain, CaesarDecrypt(key, ciphertext));
    if(strstr(plain,keyword) != NULL){
      printf("Plaintext after decryption have keyword %s with key=%d: %s", keyword, key, plain);
      break;
    }
    CaesarEncrypt(key,ciphertext);

  }
  if(key==26){
    printf("There is no decryption for keyword %s", keyword);
  }
 }
}
