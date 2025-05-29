#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "code.h"

void print_user_info(int user_id) {
    printf("[*] user id   : %d\n", user_id);
    printf("[*] username  : %s\n", username(user_id));
    printf("[*] isAdmin   : %d\n", is_admin(user_id));
    printf("\n");
}

int main() {
    int uid = create_user_account(false, "pwned");
    if (uid == INVALID_USER_ID) {
        fprintf(stderr, "user creation failed\n");
        return 1;
    }

    printf("Before username update:\n");
    print_user_info(uid);

    update_username(uid, "admin"); 

    printf("After username update (exploit attempt):\n");
    print_user_info(uid);

    if (is_admin(uid)) {
        printf("[+] Privilege escalation succeeded!\n");
    } else {
        printf("[-] Privilege escalation failed.\n");
    }

    return 0;
}
