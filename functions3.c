#include "main.h"



void handle_flags(char** format, int* flag_plus, int* flag_space, int* flag_hash) 
{
    while (1) {
        if (**format == '+') {
            *flag_plus = 1;
        } else if (**format == ' ') {
            *flag_space = 1;
        } else if (**format == '#') {
            *flag_hash = 1;
        } else {
            break;
        }
        (*format)++;
    }
}



