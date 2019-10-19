#include "header.h"

// Tao pipe.
void createPipe(vector <char*>& args)
{
    size_t k = args.size() - 1;
    vector <char*> cm;

    int flag = 0;
    // Tim vi tri cua pipe.
    while (k > 0 && args[k][0] != '|')
    {
        if (flag)
        {
            // Neu co 2 redirection cat 2 ra.
            if (args[k][0] == '<' || args[k][0] == '>')
            {
                k = flag;
                char* c = new char[4];
                c[0] = 'c';
                c[1] = 'a';
                c[2] = 't';
                c[3] = '\0';
                cm.push_back(c);
                cm.push_back(args[k]);
                break;
            }
        }
        else
        {
            if (args[k][0] == '<' || args[k][0] == '>')
            {
                if (args[k - 1][0] != '<' && args[k - 1][0] != '>')
                    flag = k;
            }
        }      

        --k;
    }  

    if (!k)
        return;

    // Cat chuoi lam 2.
    for (size_t i = k + 1; i < args.size(); ++i)
        cm.push_back(args[i]);
   
    args.erase(args.begin() + k, args.end());

    // Tao pipe
    int pipefd[2];
    if (pipe(pipefd) < 0)
    {
        perror("Pipe failed");
        exit(EXIT_FAILURE);
    }

    // Tao them tien trinh con.
    pid_t pid;
    pid = fork();

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
        
        // Tao ban sao va ghi stdout vao pipe.
        dup2(pipefd[1], 1);
        // Dong pipe read.
        close(pipefd[0]);

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
        int status;
        waitpid(pid, &status, WUNTRACED);      
    }

    // Tao ban sao va doc pipe vao stdin.
    dup2(pipefd[0], 0);
    // Dong pipe write.
    close(pipefd[1]); 
    args = cm;
}