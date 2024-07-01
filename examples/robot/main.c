// serialio - This program prompts the user with text which explains what the code is doing.
// STRTOK() is the code that points to the first character of the untokenized portion(the portion before the string is seperated)

#include <stdio.h>
#include <string.h>
#include "uart.h"
#include "readLine.h"

#define MAX_BUFFER 24
#define MAX_TOKENS (MAX_BUFFER/2)
#define MAX_DELIMS 3
// Array for movement instructions
#define max_cmd_len 7 //joint1
#define max_motor_len 7 //joint1
#define max_dir_len 3 //up/dn rt/lt
#define max_dis_len 5 // up to 9999+1


//puts("Array for movement instructions");
//printf("Enter number for movement of arm");
//printf("For users");


int main(void) {    

    init_serial();
    char input[MAX_BUFFER + 1] = {};
    char delims[MAX_DELIMS + 1] = {" ,."};

    puts("Serial I/O Test: readLine with tokens");
    printf("Enter text up to %i characters, or end w/ CR\n", MAX_BUFFER);
    printf("Line will be parsed into tokens\n");
    printf("Possible delimitors are (w/ ASCII code): ");
    for (uint8_t delim=0; delim < MAX_DELIMS; delim++)
    {
        printf("'%c' 0x%x ", delims[delim], delims[delim]);
    }
    printf("\n");
    uint8_t num_char = readLine(input, MAX_BUFFER);

    printf("You entered %i characters\n", num_char);

    for (uint8_t out_char=0; out_char<num_char; out_char++)
    {
        printf("%c", input[out_char]);
    }
    printf("\n");

    // break input line into tokens
    char *tokens[MAX_TOKENS];
    uint8_t index = 0;
    tokens[index] = strtok(input, delims);
    while ( (tokens[index] != NULL) && (index < MAX_TOKENS - 1) ) {
        index++;
        tokens[index] = strtok(NULL, delims);
    }
    uint8_t tokens_found = index;

    printf("The %i tokens parsed are:\n", tokens_found);
    printf("index token\n");
    for (index=0; index<tokens_found; index++)
    {
        printf("%5i %s\n", index, tokens[index]);

    }
    puts("Command for moving motor");
    // cmd - Command for moving motor
    char cmd[max_cmd_len] = {};
    strncpy(cmd, tokens[0], max_cmd_len);
    printf("Command is: %s\n", cmd);

    // motor - Motor determines part of robot being moved
    char motor[max_motor_len] = {};
    strncpy(motor, tokens[0], max_motor_len);
    printf("Motor is: %s\n", motor);

    // dir - Direction such as, up/dn rt/lt
    char dir[max_dir_len] = {};
    strncpy(dir, tokens[1], max_dir_len);
    printf("Direction is: %s\n", dir);

    // dis - Distance travelled
    char dis[max_dis_len] = {};
    strncpy(dis, tokens[3], max_dis_len);
    printf("Distance is: %s\n", dis);
}


