
#include <stdio.h>  
#include <string.h>  
  
#define max 100  
int top,stack[max];  
  
void push(char y){  
  
      if(top == max-1){  
          printf("stack overflow");  
      }  else {  
          stack[++top]=y;  
      }  
  
}  
  
void pop(){  
      printf("%c",stack[top--]);  
}  
  
  
 int main()  
{   char str[max] ;
    printf("Enter the string: ");
    scanf("%[^\n]s",str);
    
   int len = strlen(str);  
   int j;  
  
   for(j=0;j<len;j++)  
        push(str[j]);  
  
   for(j=0;j<len;j++)  
      pop();  
}
