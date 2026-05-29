#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main()
{
    char command[32];

    unsigned long long public_key;
    unsigned long long private_key;
    unsigned long long data;
    unsigned long long encrypt_prime_product;
    unsigned long long decrypt_prime_product;


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

            unsigned long long temp = 1;
            for (unsigned long long i = 0; i < public_key; i++)
            {
                temp = (temp * data) % encrypt_prime_product;
            }

            printf("Encrypted data: %llu\n", temp % encrypt_prime_product);
        }
        else if (strcmp(command, "decrypt") == 0)
        {
            printf("data: ");
            scanf("%llu", &data);

            unsigned long long temp = 1;
            for (unsigned long long i = 0; i < private_key; i++)
            {
                temp = (temp * data) % decrypt_prime_product;
            }

            printf("Decrypted data: %llu\n", temp % decrypt_prime_product);
        }
    }

    return 0;
}