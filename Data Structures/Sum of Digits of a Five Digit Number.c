#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    scanf("%d", &n);

    int sumn=0;
    while(n>0){
       sumn+=n%10;
       n/=10; 
    }
    printf("%d",sumn);
    return 0;
}