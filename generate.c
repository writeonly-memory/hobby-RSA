#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    unsigned prime1 = 0;
    unsigned prime2 = 0;

    printf("Prime1: ");
    scanf("%d", &prime1);
    printf("Prime2: ");
    scanf("%d", &prime2);

    unsigned long long product = prime1 * prime2;
    unsigned long long product_coprimes = (prime1 - 1) * (prime2 - 1);
    unsigned long long public_key;
    unsigned long long private_key;

    if ((product_coprimes % 65537) != 0)
    {
        public_key = 65537;
    }
    else if ((product_coprimes % 257) != 0)
    {
        public_key = 257;
    }
    else
    {
        printf("Pick new primes because most common public keys are not valid\n");
        return 1;
    }

    for (private_key = 0; private_key < 0xffffffffffffffff; private_key++)
    //no list because the private key works anyway and you can calculate it so its fine with the first one
    {
        if (((public_key * private_key) % product_coprimes) == 1)
        {
            printf("PRIVATE KEY: %d\n", private_key);
            break;
        }
    }
    printf("PUBLIC KEY: %d\nPRODUCT: %d\n", public_key, product);

    return 0;
}