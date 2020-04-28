/*
 * Trivial implementation of converter function.
 * You may override this file or create your own.
 */
#include "converter.h"

#include <stdlib.h>

/*
void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
  for (unsigned i = 0; i < nlines; i++) {
    nums[i] = atoi(lines[i]);
  }
}
*/

/*
//Naive implementation
//Basic conversion, digit by digit, searching for null terminator
//Multiplying by 10 each time
void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
    for (unsigned i = 0; i < nlines; i++) {
        int place = 0;
        char digit = lines[i][place];
        nums[i] = 0;//Need to initiliaze to zero for multiplication to work
        while( digit != '\0'){
            nums[i] = nums[i]*10;
            int d_value = digit - '0';//convert the digit
            nums[i] += d_value;
            place += 1;
            digit = lines[i][place];//advance to next char
        }
  }
}
*/


void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
    for (unsigned i = 0; i < nlines; i++) {
        int sub = 5328;//does the digit - '0' work for first 3 places; equal to 111*'0'
        char digit = lines[i][0];
        int sum = 0;
        int d_value = digit;
        sum += d_value;

        digit = lines[i][1];
        sum = sum*10;
        d_value = digit;
        sum += d_value;

        digit = lines[i][2];
        sum = sum*10;
        d_value = digit;
        sum += d_value;

        digit = lines[i][3];
        if(digit != '\0'){
            sum = sum*10;
            d_value = digit;
            sum += d_value;
            sub += 48000;//will be subtracting '0' from the thousands place

            digit = lines[i][4];
            if(digit != '\0'){
                sum = sum*10;
                d_value = digit;
                sum += d_value;
                sub += 480000;//and now from the ten thousands
            }
        }
        sum = sum - sub;
        nums[i] = sum;
  }
}
