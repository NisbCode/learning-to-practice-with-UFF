/*
3. Qual é a saída deste programa supondo que i ocupa o endereço 4094 na memória?
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
    printf("%x %d %d \n", p, *p+2, 3**p); //Respectivamente: Endereço da variavel ponteiro p, 7, 15
    return 0;
}
