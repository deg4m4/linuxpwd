#include "stdio.h"
#include "unistd.h"
#include "pwd.h"
#include "sys/wait.h"
#include "crypt.h"
#include "string.h"
#include "shadow.h"

int main(int argc, char **args)
{

    uid_t uid;
    struct passwd *pw;

    uid = getuid();
    pw = getpwnam(args[1]);

    if (0 != strcmp(pw->pw_passwd, "x"))
    {
        printf("pwd %s\b", pw->pw_passwd);
    }
    else
    {
        struct spwd *shadowEntry = getspnam(pw->pw_name);
        printf("%ld\n", shadowEntry->sp_expire);
        printf("%ld\n", shadowEntry->sp_flag);
        printf("%ld\n", shadowEntry->sp_inact);
        printf("%ld\n", shadowEntry->sp_lstchg);
        printf("%ld\n", shadowEntry->sp_max);
        printf("%ld\n", shadowEntry->sp_min);
        printf("%s\n", shadowEntry->sp_namp);
        printf("%ld\n", shadowEntry->sp_warn);
        
        printf("%s\n", crypt(args[2], shadowEntry->sp_pwdp));
        printf("%s\n", shadowEntry->sp_pwdp);

        
    }

    return 0;
}
