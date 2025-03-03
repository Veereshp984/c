#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_BITS 2048  // RSA key size
#define MAX_LEN 256    // Max buffer length

void handle_errors(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    ERR_print_errors_fp(stderr);
    exit(1);
}

// Generate RSA key pair
RSA* generate_key() {
    RSA *rsa = RSA_new();
    BIGNUM *bn = BN_new();
    if (!BN_set_word(bn, RSA_F4) || !RSA_generate_key_ex(rsa, KEY_BITS, bn, NULL))
        handle_errors("Key generation failed!");
    BN_free(bn);
    return rsa;
}

int main() {
    RSA *rsa = generate_key();  // Step 1: Generate RSA Key Pair
    const char *msg = "Hello, RSA!";
    unsigned char enc[MAX_LEN], dec[MAX_LEN];

    printf("Original message: %s\n", msg);

    // Encrypt
    int enc_len = RSA_public_encrypt(strlen(msg), (unsigned char*)msg, enc, rsa, RSA_PKCS1_OAEP_PADDING);
    if (enc_len == -1) handle_errors("Encryption failed!");
    
    printf("Encrypted (hex): ");
    for (int i = 0; i < enc_len; i++) printf("%02x", enc[i]);
    printf("\n");

    // Decrypt
    int dec_len = RSA_private_decrypt(enc_len, enc, dec, rsa, RSA_PKCS1_OAEP_PADDING);
    if (dec_len == -1) handle_errors("Decryption failed!");
    
    dec[dec_len] = '\0'; // Null-terminate decrypted string
    printf("Decrypted message: %s\n", dec);

    RSA_free(rsa); // Clean up
    return 0;
}