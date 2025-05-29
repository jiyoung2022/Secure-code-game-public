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
    // 1. 일반 사용자 계정 생성 ("pwned")
    int uid = create_user_account("pwned");
    if (uid == INVALID_USER_ID) {
        fprintf(stderr, "user creation failed\n");
        return 1;
    }

    printf("Before username update:\n");
    print_user_info(uid);

    // 2. 공격 시도: 이름을 "pwnedadmin"으로 덮어쓰기
    update_username(uid, "pwnedadmin");  // 이 때도 isAdmin은 자동 계산됨

    printf("After username update (exploit attempt):\n");
    print_user_info(uid);

    // 3. 관리자 권한 상승 여부 확인
    if (is_admin(uid)) {
        printf("[!] Privilege escalation succeeded (unexpected!)\n");
    } else {
        printf("[✓] Privilege escalation correctly blocked.\n");
    }

    return 0;
}
