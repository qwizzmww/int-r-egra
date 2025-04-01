#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

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
    return equation;
}

void GetCoefficients(char *str, float coefficients[3]){
    int i = 0;
    char *token = strtok(str, "+-");
    float sign = 1.0;
    coefficients[0] = coefficients[1] = coefficients[2] = 0.0;

    while (token != NULL && i < 3){
        char *prev = token - 2;
        if (i>0 && prev >= str && *prev == "-") {
            sign = -1.0;
        }else{
            sign = 1.0;
        }
        coefficients[i] = sign * atof(token);
        i++;
        token = strtok(NULL, "+-");
    }
}

float CalculateRoots(float a, float b, float c){
    float discriminant, x1, x2;
    discriminant = (pow(b, 2)) - (4 * a * c);
    if (discriminant >= 0){
        x1 = (-b - pow(discriminant, 0.5))/2;
        x2 = (-b + pow(discriminant, 0.5))/2;

        printf("\n%f\n", x1);
        printf("\n%f\n", x2);
    }else{
        printf("D<0");
    }
    
}

int main(){
    char equation[50];
    float coefficients[3];
    float a, b, c;
    char *result = GetUserInput(equation);
    GetString(equation);
    GetCoefficients(result, coefficients);
    a = coefficients[0]; 
    b = coefficients[1]; 
    c = coefficients[2]; 

    CalculateRoots(a,b,c);

    return 0;
}