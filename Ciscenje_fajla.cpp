#include<fstream>
using namespace std;
fstream ofs;
int main()
{
   ofs.open("Source.txt", ios::out | ios::trunc);
   ofs.close(); //Using microsoft incremental linker version 14
   return 0;
}
