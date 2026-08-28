#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main()
{
    char command[32];

    uint64_t public_key;
    uint64_t private_key;
    uint64_t data;
    uint64_t encrypt_prime_product;
    uint64_t decrypt_prime_product;


    printf("Their public key: ");
    scanf("%llu", &public_key);
    printf("Your private key: ");
    scanf("%llu", &private_key);
    printf("Their prime product: ");
    scanf("%llu", &encrypt_prime_product);
    printf("Your prime product: ");
    scanf("%llu", &decrypt_prime_product);

    printf("  Valid Commands:\n    encrypt\n    decrypt\n    exit\n");

    while (strcmp(command, "exit") != 0)
    {
        printf("command: ");
        scanf("%s", command);
        if (strcmp(command, "encrypt") == 0)
        {
            printf("data: ");
            scanf("%llu", &data);

            if (data >= encrypt_prime_product)
            {
                printf("----\nERROR: Data too large. Data must be less than product.\n----\n");
                continue;
            }

            uint64_t temp = 1;
            for (uint64_t i = 0; i < public_key; i++)
            {
                temp = (temp * data) % encrypt_prime_product;
            }

            printf("Encrypted data: %llu\n", temp % encrypt_prime_product);
        }
        else if (strcmp(command, "decrypt") == 0)
        {
            printf("data: ");
            scanf("%llu", &data);

            uint64_t temp = 1;
            for (uint64_t i = 0; i < private_key; i++)
            {
                temp = (temp * data) % decrypt_prime_product;
            }

            printf("Decrypted data: %llu\n", temp % decrypt_prime_product);
        }
        else if (strcmp(command, "exit") == 0)
        {
            printf("Goodbye\n");
        }
        else
        {
            printf("----\nERROR: Unrecognized command.\n----\n");
        }
    }

    return 0;
}