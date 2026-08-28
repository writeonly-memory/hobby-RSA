#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    uint64_t prime1 = 0;
    uint64_t prime2 = 0;

    printf("Prime1: ");
    scanf("%llu", &prime1);
    printf("Prime2: ");
    scanf("%llu", &prime2);

    uint64_t product = prime1 * prime2;
    uint64_t product_coprimes = (prime1 - 1) * (prime2 - 1);
    uint64_t public_key;
    uint64_t private_key;

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

    if (product_coprimes <= public_key)
    {
        printf("The number of coprimes (%d) is too low for normal public keys so manual key generation is needed\n", product_coprimes);
        printf("Possible public keys:\n");
        for (uint64_t i = 3; i < product_coprimes; i += 2)
        {
            if ((product_coprimes % i) != 0)
            {
                printf("%d\n", i);
            }
        }
        printf("Choose a public key: ");
        scanf("%llu", &public_key);
    }

    printf("If no output redo with different key choice\n");

    for (private_key = 0; private_key < 0xffffffffffffffff; private_key++)
    //no list because the private key works anyway and you can calculate it so its fine with the first one
    {
        if (((public_key * private_key) % product_coprimes) == 1)
        {
            printf("PRIVATE KEY: %llu\n", private_key);
            break;
        }
    }
    printf("PUBLIC KEY: %llu\nPRODUCT: %llu\n", public_key, product);

    return 0;
}