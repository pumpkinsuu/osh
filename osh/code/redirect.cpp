#include "header.h"

// Chuyen huong.
void redirect(vector <char*>& args)
{
    size_t n = args.size();   

    // Kiem ra dong lenh co tu 3 lenh tro len.
    if (n > 2)
    {
        if (args[n - 2][0] == '>')
        {
            int fd;
            // Neu co >> thi viet tiep len file, > thi viet de.
            if (args[n - 2][1] == '>')
                fd = open(args[n - 1], O_RDWR | O_CREAT | O_APPEND, S_IRWXU);
            else
                fd = open(args[n - 1], O_RDWR | O_CREAT | O_TRUNC, S_IRWXU); 
                
            if (fd < 0)
            {
                perror("Open failed");
                exit(EXIT_FAILURE);
            }

            // Tao ban sao va ghi stdout vao file.                
            dup2(fd, 1);
            // Dong file.
            close(fd);

            args.pop_back();
            args.pop_back();
        }
        else if (args[n - 2][0] == '<')
        {
            // Neu co < thi doc tu file.
            int fd = open(args[n - 1], O_RDONLY);
            if (fd < 0)
            {
                // Loi file khong mo duoc.
                perror("Read failed");
                exit(EXIT_FAILURE);
            }

            // Tao ban sao va doc file vao stdin.
            dup2(fd, 0);
            // Dong file.
            close(fd);

            args.pop_back();
            args.pop_back();
        }  
    }
      
    args.push_back(nullptr);
}