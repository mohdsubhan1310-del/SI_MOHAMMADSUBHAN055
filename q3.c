#include <stdio.h>

int main() {
    float num1 ,num2 ,result;
    char op;

     printf("Enter an Opertion( + , - , * , / ): ");
     scanf("%c",&op);

    printf("Enter two numbers:");
    scanf("%f %f",&num1,&num2);

   
    switch(op)
    {

        case '+':
        result=num1+num2;
        printf("Result = %f",result );
        break;

        case '-':
        result=num1-num2;
        printf("Result = %f",result );
        break;

        case '*':
        result=num1*num2;
        printf("Result = %f",result );
        break;

        case '/':
        result=num1/num2;
        printf("Result = %f",result );
        break;

        default:
        break;
    }

    return 0;
}
