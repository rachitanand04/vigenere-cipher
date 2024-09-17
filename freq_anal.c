#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_LENGTH 10000
void initHash(double table[], int len){
    for(int i = 0; i < len; i++){
        table[i] = 0;
    }
}
int key_breaker(const char *text, int letter){
    double freq[26];
    initHash(freq,26);
    double difference = 100.0;
    int index = -1;
    double temp = 0;

    double letterFrequencies[26] = {
    8.2, 1.5, 2.8, 4.3, 12.7, 2.2, 2.0, 
    6.1, 7.0, 0.2, 0.8, 4.0, 2.4, 6.7,
    7.5, 1.9, 0.1, 6.0, 9.0, 2.8, 0.1,
    2.8, 1.0, 0.2, 2.0, 0.1};
    //double letterFrequencies[26] = {3.8, 5.3, 3.1, 1.6, 2.0, 7.2, 3.3, 3.9, 4.8, 3.2, 3.7, 4.0, 5.4, 3.9, 3.3, 2.4, 1.4, 1.9, 4.2, 3.1, 5.7, 4.2, 4.2, 4.4, 6.5, 3.7};

    int len = strlen(text);

    for(int i = 0; i < len; i++){
        freq[text[i]-97] += 1;
    }

    for(int i = 0; i < 26; i++){
        freq[i] = (freq[i]/len)*100;
        temp = letterFrequencies[letter] - freq[i];
        if(fabs(temp) < difference){
            difference = temp;
            index = i;
        }
        
    }
    index = index - letter;

    if(index < 0){
        index = index + 26;
    }
    return index;
}
    

double index_of_coincidence(const char *text) {
    int freq[26] = {0};
    int n = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char c = tolower(text[i]);
            freq[c - 'a']++;
            n++;
        }
    }

    double ic = 0.0;
    for (int i = 0; i < 26; i++) {
        ic += (double)freq[i] * (freq[i] - 1);
    }
    if (n > 1) {
        ic /= (n * (n - 1));
    }
    return ic;
}


void freq_Analysis(char text[], int keylength){
    int len = strlen(text);
    int index = 0;
    char letter;
    char key[keylength];
    for(int i = 0; i < keylength; i++){
        index = 0;
        char string[MAX_LENGTH];
        int count = 0;
        printf("String %d\n",i+1);
        for(int j = i; j < len; j=j+keylength){
            string[count] = text[j];
            count++;      
        }
        printf("%s\n",string);
        printf("Index of Coincidence: %f\n",index_of_coincidence(string));
        key[i] = key_breaker(string,4)+97;
    }
    printf("%s\n",key);
}

int main(){
    char text[MAX_LENGTH];
    int keylen;
    printf("Enter string: \n");scanf("%s",text);
    printf("Enter key length: "); scanf("%d",&keylen);
    freq_Analysis(text,keylen);
    return 0;
}