/*------------------------------------------------------
* Filename: encryption_2_YaliLeshem.c
* Description: Save password to encrypt and decrypt gargamel malicious sentence
* Author: Yali Leshem
-------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define STR_MAX_LEN 128
#define SAFE_WORD_LEN 4
#define SAFE_WORD "safe"

int ensure_safe_word(char sentence [], int start) {
    int index;
    const char safe_word[] = "safe";
    for (index = start; index < start+4; index++) {
        if (sentence[index] != safe_word[index])
            return 0;
    }
    return 1;
}


int main() {
    // Added 1 for the null terminators in strings
    char gargamel_sentence[STR_MAX_LEN+1], password_first[STR_MAX_LEN+1], password_second[STR_MAX_LEN+1], password_authorization[STR_MAX_LEN+1]; 
    int index, sum = 0;
    double average;

    printf("Enter gargamel sentence, describing his malicious plan: \n");
    scanf(" %124[^\n]", gargamel_sentence); // Saved four characters for "safe" in gargamel sentence
    
    printf("Enter your password for authorization: \n");
    scanf(" %128[^\n]", password_first);

    printf("Enter your password for authorization once again: \n");
    scanf(" %128[^\n]", password_second);

    if (strcmp(password_second, password_first) != 0) {
        printf("The password for authorization wasn't the same, exiting program \n");
        return 1;
    }

    strcat(gargamel_sentence, SAFE_WORD);
    int sentence_len = strlen(gargamel_sentence) - 1; // For later on, to know where the full sentence lies

    for (index = 0; password_first[index] != '\0'; index++) {
        sum += (int) password_first[index];
    }

    average = ((double)sum/index); // calculating average ASCII value

    for (index = 0; index < sentence_len; index++) {
        gargamel_sentence[index] += (int)average; // Adding to all original characters in sentence the average
    }

    printf("Your data is safe \n");
    
    while (1) {
        printf("Insert password now: \n");
        scanf(" %128[^\n]", password_authorization);

        sum = 0; // have to reset sum to zero before calculating average again
        for (index = 0; password_authorization[index] != '\0'; index++) {
            sum += (int) password_authorization[index];
        }

        average = ((double)sum/index); // calculating average ASCII value

        for (index = 0; index < sentence_len; index++) {
            gargamel_sentence[index] -= (int)average; // Adding to all original characters in sentence the average
        }

        // If 1 is returned - safe word was found. Otherwise - move to next iteration and keep entering password
        if (ensure_safe_word(gargamel_sentence, sentence_len-4)) {
            for (index = 0; index < sentence_len-4; index++) 
                printf("%c", gargamel_sentence[index]); // print original sentence without 'safe'
            return 0;
        }
    }
}
