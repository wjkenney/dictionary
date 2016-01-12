#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int x=1;

int main(void)
{
    char* hello =malloc(6);
    
    hello="hello";
          
    for (int i=0; i<6; i++)
    {
         hello[i]=toupper(hello[i]);
    }
    printf("%s %i\n", hello, x);
 }   
