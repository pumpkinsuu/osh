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
    {
        perror("Load failed!");
        return;
    }    
    
    string tmp;
    while (getline(in, tmp))
        history.push_back(tmp); 
}

// Luu lich su vao file history.txt trong thu muc co duong dan cwd.
void save(const vector <string>& history, char cwd[])
{
    ofstream out;
    string path = cwd;
    path += "/history.txt";

    out.open(path);
    if (!out.is_open())
    {
        perror("Save failed!");
        return;
    } 
        
    for (auto x : history)
        out << x << '\n';
}