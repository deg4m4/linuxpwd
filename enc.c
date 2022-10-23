#include "stdio.h"
#include "crypt.h"

int main(int argc, char **args) {

    char *toCrackCiph1 = crypt("pka", "AAaVBaUFktFmM");
    printf("%s\n", toCrackCiph1);

    return 0;
}
