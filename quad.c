#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


char* GetUserInput(char *equation){
    printf("%s", "enter the equation: ");
    scanf("%s", equation);
    return equation;
}

char* GetString(char *equation){
    char *pos1 = strstr(equation, "x^2");
    if(pos1){
        memmove(pos1, pos1 + 3, strlen(pos1+3)+1);
    }
    char *pos2 = strstr(equation, "x");
    if(pos2){
        memmove(pos2, pos2+1, strlen(pos2+1)+1);
    }
    char *pos3 = strstr(equation, "=");
    if (pos3){
        memmove(pos3, pos3+2, strlen(pos3+2)+1);
    }
    printf("%s", equation);
    return equation;
}

void GetCoefficients(char *str, float coefficients[3]){

}

int main(){
    char equation[50];
    GetUserInput(equation);
    GetString(equation);

}