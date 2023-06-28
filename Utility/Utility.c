/*
 * Utility.c
 *
 *  Created on: Jun 26, 2023
 *      Author: vanti
 */
#include "Utility.h"
#include "math.h"
void reverseStr(char* str, int len)
{
    int i = 0, j = len - 1, temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}
int intToStr(int x, char str[], int d)
{
    int i = 0;
    while (x) {
        str[i++] = (x % 10) + '0';
        x = x / 10;
    }

    // If number of digits required is more, then
    // add 0s at the beginning
    while (i < d)
        str[i++] = '0';

    reverseStr(str, i);
    str[i] = '\0';
    return i;
}
static int pow10[] = {
        1, 10, 100, 1000, 10000,
        100000, 1000000, 10000000, 100000000, 1000000000
    };

int quick_pow10(int n)
{
    return pow10[n];
}

int FloatToStr(float n, char* res, int afterpoint)
{

	if(afterpoint > sizeof(pow10)) return 1;
    // Extract integer part
    int ipart = (int)n;

    // Extract floating part
    float fpart = n - (float)ipart;

    // convert integer part to string
    int i = intToStr(ipart, res, 0);

    // check for display option after point
    if (afterpoint != 0) {
        res[i] = '.'; // add dot

        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter
        // is needed to handle cases like 233.007
        fpart = fpart * quick_pow10(afterpoint);
//        fpart = fpart*10;
//        fpart = fpart* pow(10, afterpoint);

        intToStr((int)fpart, res + i + 1, afterpoint);
    }
    return 0;
}

float StrToFloat(char *string)
{
    float result= 0.0;
    int len = strlen(string);
    int dotPosition = 0;

    for (int i = 0; i < len; i++)
    {
        if (string[i] == '.')
        {
          dotPosition = len - i  - 1;
        }
        else
        {
          result = result * 10.0 + (string[i]-'0');
        }
      }

      while (dotPosition--)
      {
        result /= 10.0;
      }

    return result;
}
