#include <stdio.h>
#include <string.h>
#define MAX_CHARACTERS 10000

int checkPrime(int a){
    for(int i = 2; i < a/2; i++){
        if(a % i == 0){
            return 0;
        }
    }
    return 1;
}

int existsInArray(int array[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return 1; 
        }
    }
    return 0;
}

int findMostOccurringElement(int arr[], int size) {
    int hash[MAX_CHARACTERS] = {0}; 
    int maxCount = 0;
    int mostOccurringElement = arr[0];

    for (int i = 0; i < size; i++) {
        int value = arr[i];
        if(value != 1){
        hash[value]++;
        if (hash[value] > maxCount) {
            maxCount = hash[value];
            mostOccurringElement = value;
        }            
        }
    }

    return mostOccurringElement;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void crypto_analysis(char ciphertext[]) {
    int differences[MAX_CHARACTERS];
    int gcds[MAX_CHARACTERS];
    int gcdCount = 0;
    int count = 0;
    int len = strlen(ciphertext);
    int index_difference[MAX_CHARACTERS];
    int substrings = 0;

    for (int length_of_subsequence = 3; length_of_subsequence < 4; length_of_subsequence++) {
        for (int i = 0; i <= len - length_of_subsequence; i++) {
            for (int j = i + length_of_subsequence; j <= len - length_of_subsequence; j++) {
                int present = 1;

                for (int k = 0; k < length_of_subsequence; k++) {
                    if (ciphertext[i + k] != ciphertext[j + k]) {
                        present = 0;
                        break;
                    }
                }

                if (present) {
                    int difference = j - i;
                    if(checkPrime(difference) == 0){
                        if (!existsInArray(differences, count, difference)) {
                        differences[count] = difference;
                        count++;
                    }
                    }
                    if(checkPrime(difference) == 0){
                        index_difference[substrings] = difference;
                        printf("Sub-Sequence: %.*s at index %d and %d, distance: %d\n", length_of_subsequence, &ciphertext[i], i, j, difference);
                        substrings++;
                    }
                }
            }
        }
    }
    for(int i = 0.; i < count; i=i+2){
        gcds[gcdCount] = gcd(differences[i],differences[i+1]);
        // printf("%d\n",gcds[gcdCount]);
        gcdCount++;
    }

    if (substrings > 0) {
        printf("Length of Key: %d\n", findMostOccurringElement(gcds,gcdCount));
    }

    else {
        printf("Can't find length of key, no repeating sub-sequences found.\n");
    }
}

int main() {
    char ciphertext[MAX_CHARACTERS];
    char key[MAX_CHARACTERS];

    printf("Enter ciphertext: \n");
    scanf("%s",ciphertext);
    crypto_analysis(ciphertext);
    return 0;
}