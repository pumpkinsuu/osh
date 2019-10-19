#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

using namespace std;

int getInput(vector <char*>& args, vector <string>& history);
void redirect(vector <char*>& args);
void createPipe(vector <char*>& args);
int execute(vector <char*> args);

int special(vector <string>& history);
void load(vector <string>& history);
void save(const vector <string>& history);