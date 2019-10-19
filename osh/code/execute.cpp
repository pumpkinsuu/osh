#include "header.h"

// Xu ly lenh.
int execute(vector <char*> args)
{
    bool concurrent = false;
    // Kiem tra xem co thuc thi dong thoi hay lan luot.
    if (args.back()[0] == '&')
    {
        concurrent = true;
        args.pop_back();
    }

    // Tao tien trinh con.
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        // Tao pipe neu co.
        createPipe(args);
        // input va output redirection neu co.
        redirect(args);

        // Thuc thi dong lenh.
        if (execvp(args[0], args.data()) == -1)
        {
            perror(args[0]);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        // Neu khong co & thi cho tien trinh con.
        if (!concurrent)
        {
            int status;
            waitpid(pid, &status, WUNTRACED);
        }
    }
    
    return 1;
}