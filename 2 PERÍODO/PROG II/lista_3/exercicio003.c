/*
3. Qual � a sa�da deste programa supondo que i ocupa o endere�o 4094 na mem�ria?
main() {
int i=5, *p;
p = &i;
printf("%x %d %d \n", p, *p+2, 3**p);
}
*/

#include <stdio.h>

int main() {
    int i=5, *p;
    p = &i;
    printf("%x %d %d \n", p, *p+2, 3**p); //Respectivamente: Endere�o da variavel ponteiro p, 7, 15
    return 0;
}
