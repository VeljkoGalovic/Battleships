#include<bits/stdc++.h>
using namespace std;
string str, zapamti, izlaz;
int poc, kraj, br;
int sx, sy;
char prvi, drugi;

void DIMENZIJA_X()
{
   sx = str.find("sx");
   prvi = str[sx+4];
   drugi = str[sx+5];

   sx = 0;
   sx = prvi - 48;

   if(drugi - 48 >=0 and drugi - 48 <= 9)
   {
      sx = sx * 10;
      sx = sx + (drugi - 48);
   }
   //cout << "sx: " << prvi << " " << drugi << "\n";
}

void DIMENZIJA_Y()
{
   sy = str.find("sy");
   prvi = str[sy+4];
   drugi = str[sy+5];

   sy = 0;
   sy = prvi - 48;

   if(drugi - 48 >=0 and drugi - 48 <= 9)
   {
      sy = sy * 10;
      sy = sy + (drugi - 48);
   }
}

int main()
{
   freopen("Source.txt", "r", stdin);
   freopen("Ships.in", "w", stdout);

   while(getline(cin, str))
   {
      if (str.find("ggSDK.embed") != string::npos)
         zapamti = str;
   }

   poc = 0;
   kraj = 0;
   str.clear();
   //cout << zapamti << " aaa\n";
   for(int i=0; i<zapamti.size(); i++)
   {
      if(zapamti[i] == '{')
         poc = 1;

      if(poc == 1 and kraj == 0)
         str.push_back(zapamti[i]);


      if(zapamti[i] == '}')
         kraj = 1;
   }
   //cout << str << "\n";
   DIMENZIJA_X();
   DIMENZIJA_Y();

   br = 0;
   for(int i=0; i<str.size(); i++)
   {
      if(str[i] == 39)
      {
         br++;

         if(br == 3)
         {
            poc = i;
            break;
         }
      }
   }


   for(int i=poc+1; i<str.size()-2; i++)
      izlaz.push_back(str[i]);

   cout << sx << "\n" << sy << "\n" << izlaz << "\n";
   return 0;
}
