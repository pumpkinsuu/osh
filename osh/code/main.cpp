#include "header.h"

int main()
{
    vector <char*> args;
    vector <string> history;

    // Nap lich su vao bo nho.
    load(history);
    char cwd[1024];
    // Lay duong dan cua file luu lich su.
    getcwd(cwd, sizeof(cwd));

    int status = 1;

    while (status)
    {
        // Xu ly dau vao.
        status = getInput(args, history, cwd);

        // Thuc thi cau lenh neu status > 0.
        if (status > 0) 
            execute(args);
    }

    return 0;
}
