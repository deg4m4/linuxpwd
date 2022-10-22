#include "stdio.h"
#include "unistd.h"
#include "pwd.h"
#include "sys/wait.h"

int main()
{

    uid_t uid;
    struct passwd *pw;

    uid = getuid();
    pw = getpwuid(uid);

    char cmd[1024];
    sprintf(cmd, "passwd %s", "degama");
    FILE *fp= popen(cmd, "w");
    fprintf(fp, "%s\n", "qaz");
    fprintf(fp, "%s\n", "qaz");
    printf("Return value: %i\n", WEXITSTATUS(pclose(fp)));

    return 0;
}
