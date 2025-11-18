/*------------------------------------------------------
* Filename: encryption_YaliLeshem.c
* Description: find the message for Gargamel of a sequence of 26 numbers representing encrypted message
* Author: Yali Leshem
-------------------------------------------------------*/

#include <stdio.h>

#define ENCRYPTION_LEN 26
#define DIV_NUM 7
#define SUBTRACT_NUM 5
#define STEPS_FORWARD 5
#define STEPS_BACK 4

typedef struct {
    int new_index;
    char encrypted_char;
} Encrypt;

/*------------------------------------------------------
* Function Name - find_encrypted_char
*
* Function Purpose - Proccess the number in the message, and find its decrypted value
*
* Parameters –  Int num - encrypted number, int index - the index of number in encrypted message, 
* int prev_num - the previous number in encrypted message
*
* Author - Yali Leshem
-------------------------------------------------------*/

Encrypt find_encrypted_char (int num, int index, int prev_num) {
    Encrypt output;
    char encrypted_char;
    int mid_point = ENCRYPTION_LEN/2; // Using for switching between first/second half

    // In the decryption process - first of all swap halfs
    if (index < mid_point)
        index -= mid_point;
    else
        index += mid_point;

    // Subtracting previous num, unless it's index 0 so zero wil be subtracted
    num -= prev_num;

    // move each index 5 steps forward, in a circular way
    index = (index+STEPS_FORWARD)%ENCRYPTION_LEN;

    if (index%2 == 0) // If index is even, divide by 7 the number
        num /= DIV_NUM;

    // move each index 4 steps back, in a circular way
    index = (index+STEPS_BACK)%ENCRYPTION_LEN;
    
    // subtract from each number 5...
    num -= SUBTRACT_NUM;
    encrypted_char = (char) num; // Convertion to character for decryption

    output.new_index = index;
    output.encrypted_char = encrypted_char;
    return output;
}

int main() {
    int encrypted_num, index, prev_num = 0;
    char decrypted_message[ENCRYPTION_LEN+1]; // Added one to length for inserting later the null terminator

    Encrypt result;

    for (index = 0; index < ENCRYPTION_LEN; index++) {
        if (scanf("%d",&encrypted_num) != 1) { // In case of invalid input - exit program immediately
            printf("Bad input! exiting program");
            return 1;
        }

        result = find_encrypted_char(encrypted_num, index, prev_num); // Recieve the decrypted char and save it into the message string
        decrypted_message[result.new_index] = result.encrypted_char;

        prev_num = encrypted_num; // save for decryption proccess the previous number
    }

    decrypted_message[ENCRYPTION_LEN] = '\0';
    printf("%s", decrypted_message);

    return 0;
}