#include "header.h"

// Cac ham dat biet.
int special(vector <string>& history)
{
    // Lay dong lenh moi nhat trong lich su.
    istringstream line(history.back());
    string tmp;
    while (line >> tmp)
    {
        // Thoat.
        if (tmp == "exit") return 0;  
        // Doi thu muc.
        if (tmp == "cd")
        {
            if (line >> tmp)
            {
                if (chdir(tmp.c_str()) < 0)
                    perror(tmp.c_str());
            }
            return -1;
        }

        if (tmp == "history")
        {
            if (line >> tmp)
            {
                // Xoa lich su.
                if (tmp == "-c")
                    history.clear();
            }
            else
            {
                // Xem lich su.
                for (size_t i = 0; i < history.size(); ++i)
                    cout << i + 1 << "  " << history[i] << '\n';
            }
            return -1;    
        }
    }

    return 1;
}

// Nap lich su tu file history.txt.
void load(vector <string>& history)
{
    ifstream in;
    in.open("history.txt");
    if (!in.is_open())
        return;    
    
    string tmp;
    while (getline(in, tmp))
        history.push_back(tmp); 
}

// Luu lich su vao file history.txt.
void save(const vector <string>& history)
{
    ofstream out;
   
    // Lay duong dan cua osh de luu lish su.
    std::string path = "";
    pid_t pid = getpid();
    char buf[20] = {0};
    sprintf(buf,"%d",pid);
    std::string _link = "/proc/";
    _link.append( buf );
    _link.append( "/exe");
    char proc[512];
    int ch = readlink(_link.c_str(),proc,512);
    if (ch != -1) {
        proc[ch] = 0;
        path = proc;
        std::string::size_type t = path.find_last_of("/");
        path = path.substr(0,t);
    }

    path = path + string("/") + "history.txt";

    out.open(path);
    if (!out.is_open())
    {
        perror(path.c_str());
        return;
    } 
        
    for (auto x : history)
        out << x << '\n';
}