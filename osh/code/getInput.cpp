#include "header.h"

// Xu ly dau vao.
int getInput(vector <char*>& args, vector <string>& history)
{
    string line;

    cout << "osh> ";
    getline(cin, line);
    
    // Luu dong lenh gan nhat.
    vector <char*> args_old = args;
    args.clear();
    history.push_back("");

    // Xu ly chuoi dau vao.
    istringstream iss(line);
    string tmp;
    while (iss >> tmp)
    {
        // Thuc hien lenh gan nhat trong lich su.
        if (tmp == "!!")
        {
            if (history[history.size() - 2] == "")
                cout << "No commands in history!\n";         
            else
            {
                // Chen dong lenh cu vao vong lenh moi.
                for (auto x : args_old)
                {
                     args.push_back(x); 
                     history.back() += x;
                     history.back() += ' '; 
                }  
                cout << history.back() << '\n';      
            }
        }
        else
        {
            // Nap lenh vao args va lich su.
            char* c = new char[tmp.length() + 1];
            for (size_t i = 0; i < tmp.length(); ++i)
                c[i] = tmp[i];
            c[tmp.length()] = '\0';

            args.push_back(c);
            history.back() += c;
            history.back() += ' '; 
        }   
    }

    //  Luu dong lenh vua nhap.
    save(history);

    // Kiem tra co lenh dac biet nao khong.
    int check = special(history);
    if (check != 1)
        return check;

    // Neu khong co lenh thi tra ve -1 de khong thuc thi.
    if (args.empty())
        return -1;

    return 1;
}