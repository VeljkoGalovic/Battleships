#include<bits/stdc++.h>
using namespace std;
char MatricaKaraktera[100][100];
int X, Y, Red[100], Kolona[100];
string str;
void ULAZ()
{
   freopen("Ships.in", "r", stdin); /// UCITAVANJE IZ FAJLA
   cin >> X >> Y;

   for(int i=1; i<=Y; i++)
   {
      for(int j=1; j<=X; j++)
      {
         cin >> MatricaKaraktera[i][j];
      }

      if(i != Y)
         cin >> Red[i];

      else
      {
         cin >> str;
         Red[i] = str[0]-48;
      }
   }

   for(int i=1; i<str.size(); i++)
      Kolona[i] = str[i] - 48;

   freopen("CON", "r", stdin); /// UCITAVANJE SE PREBACUJE NA KONZOLU
}

void ISPIS_MATRICE()
{
   for(int i=1; i<=Y; i++)
   {
      for(int j=1; j<=X; j++)
      {
         cout << MatricaKaraktera[i][j] << " ";
      }
      cout << "  " << Red[i] << "\n";
   }

   for(int i=1; i<=X; i++)
      cout << Kolona[i] << " ";
   cout << "\n";
}

int main()
{
   ULAZ();
   ISPIS_MATRICE();
   return 0;
}
