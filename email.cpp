#include <string>
#include <cstring>

using namespace std;

const int MAX_USER = 10;
const int MAX_FR = 10;
const int MAX_AREA = 10;
struct User {
    int uid;
    int fr[20];
    int reserved;
};

struct Package {
    int pid;
    int area;
    string name;

    void push_back(int _pid, int _area, string _name){
        pid = _pid;
        area = _area;
        name = _name; 

    }
};

vector<Package> packages;
User user[100];
int area[MAX_AREA];

int main() {
    packages.push_Back

    return 0;
}