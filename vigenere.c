#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_LENGTH 10000

void Vig_enc(char plaintext[], char secret_key[]);
void Vig_dec(char plaintext[], char secret_key[]);
void remove_spaces(char* s) {
    char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}

void main(){
    char input[MAX_LENGTH];
    char key[MAX_LENGTH];
    int num;
    printf("What do you want to do?:\n1.Encrypt\n2.Decrypt\n");
    scanf("%d",&num);
    if(num == 1){
        printf("Enter plaintext: \n");
        scanf("%s",input);
        printf("Enter key: ");
        scanf("%s",key);
        printf("===================\n");
        Vig_enc(input,key);
    }
    if(num == 2){
        printf("Enter ciphertext: \n");
        scanf("%s",input);
        printf("Enter key: ");
        scanf("%s",key);
        printf("===================\n");
        Vig_dec(input,key);
    }
}

void Vig_enc(char plaintext[], char secret_key[]){
    int textlen = strlen(plaintext);
    int keylen = strlen(secret_key);
    char out[textlen];
    int ascii;
    int code;
    int keyIndex = 0;
    for(int i = 0 ; i < textlen; i++){
        ascii = plaintext[i];
        code = ascii-97;
        code += (secret_key[keyIndex]-97);
        code = code % 26;
        code += 97;
        keyIndex++;
        if(keyIndex >= keylen){
            keyIndex = 0;
        }
        printf("%c",code);
    }
    printf("\n");
}

void Vig_dec(char ciphertext[], char secret_key[]) {
    int textlen = strlen(ciphertext);
    int keylen = strlen(secret_key);
    char out[textlen + 1]; 
    int ascii;
    int code;
    int keyIndex = 0;

    for (int i = 0; i < textlen; i++) {
        ascii = ciphertext[i];
        code = ascii - 97; 
        code -= (secret_key[keyIndex] - 97); 
        code = (code + 26) % 26; 
        code += 97;
        
        out[i] = code;
        keyIndex++;
        if (keyIndex >= keylen) {
            keyIndex = 0;
        }
    }
    out[textlen] = '\0';

    printf("%s\n", out);
}