#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf

int main(int argc, char* argv[]){
//    printf("%s %s", argv[1], argv[2]);
    FILE *fp1, *fp2;
    uint32_t a=0,b=0;
    if((fp1 = fopen(argv[1], "r"))==NULL || (fp2 = fopen(argv[2], "r"))==NULL)
        printf("error!");
    if(fread(&a,4,1,fp1)!=1 || fread(&b,4,1,fp2)!=1)
        printf("error");
    a = __builtin_bswap32(a);
    b = __builtin_bswap32(b);
    printf("%u(%#x) + %u(%#x) = %u(%#x)\n", a,a, b,b,a+b, a+b);
    return 0;
}
