#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream fp;

    fp.open("logs.csv");

    while (fp.good()) {
        string line;
        getline(fp, line);
        cout << line << endl;
    }
}
