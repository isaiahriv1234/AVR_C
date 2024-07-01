#include "unolib.h"
#include "pinMode.h"
#include "digitalWrite.h"
#include "delay.h"
 
int main(void)
{
    // use built-in led and set to output
    pinMode(LED_BUILTIN, OUTPUT);

    while(1) 
    {
        // toggle led on and off
        digitalWrite(LED_BUILTIN, HIGH);
        delay(2000);
        digitalWrite(LED_BUILTIN, LOW);
        delay(2000);
    }
    return 0; 
}
#define max_cmd_len 4 # this is the maximun number of characters for the command
char cmd[max_cmd_len] = {}; # defines the variable which will hold the command
strncpy(cmd, tokens[0], max_cmd_len); # assigns the first token found to be a command
