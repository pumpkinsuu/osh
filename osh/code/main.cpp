#include "header.h"

int main()
{
    vector <char*> args;
    vector <string> history;

    // Nap lich su vao bo nho.
    load(history);

    int status = 1;

    while (status)
    {
        // Xu ly dau vao.
        status = getInput(args, history);

        // Thuc thi cau lenh neu status > 0.
        if (status > 0) 
            execute(args);
    }

    return 0;
}
