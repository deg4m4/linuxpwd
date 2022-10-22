#include "shadow.h"
#include "stdio.h"

int main(int argc, char **args)
{

    struct spwd spass;
    spass.sp_expire = -1;
    spass.sp_flag = -1;
    spass.sp_inact = -1;
    spass.sp_lstchg = 1201;
    spass.sp_max = 9999;
    spass.sp_min = 0;
    spass.sp_namp = args[1];
    spass.sp_pwdp = args[2];
    spass.sp_warn = 0;

    FILE *pwdfile;
    pwdfile = fopen("pass","a+");

    putspent(&spass, pwdfile);

    return 0;
}
