#include<bits/stdc++.h>
using namespace std;
char MatricaKaraktera[100][100];
int X, Y, Red[100], Kolona[100], br;
string str;

/// LEGENDA:
/// e - POLUKRUG OKRENUT KA DESNO
/// f - POLUKRUG OKRENUT KA DOLE
/// d - POLUKRUG OKRENUT KA GORE
/// g - POLUKRUG OKRENUT KA LEVO
/// c - KVADRAT
/// b - KRUG
/// p - ONAJ STO JE PROGRAM DODAO
/// # - VODA
/// . - PRAZNO

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

void INICIJALIZACIJA()
{
   /// e - POLUKRUG OKRENUT KA DESNO
   for(int i=1; i<=Y; i++)
   {
      for(int j=1; j<=X; j++)
      {
         if(MatricaKaraktera[i][j] == 'e')
         {
            MatricaKaraktera[i][j-1] = 'p';

            MatricaKaraktera[i-1][j] = '#';
            MatricaKaraktera[i+1][j] = '#';
            MatricaKaraktera[i][j+1] = '#';
            MatricaKaraktera[i-1][j-1] = '#';
            MatricaKaraktera[i+1][j-1] = '#';
            MatricaKaraktera[i-1][j+1] = '#';
            MatricaKaraktera[i+1][j+1] = '#';
            MatricaKaraktera[i-1][j-2] = '#';
            MatricaKaraktera[i+1][j-2] = '#';
         }
      }
   }

   /// f - POLUKRUG OKRENUT KA DOLE
   for(int i=1; i<=Y; i++)
   {
      for(int j=1; j<=X; j++)
      {
         if(MatricaKaraktera[i][j] == 'f')
         {
            MatricaKaraktera[i-1][j] = 'p';

            MatricaKaraktera[i+1][j] = '#';
            MatricaKaraktera[i][j+1] = '#';
            MatricaKaraktera[i][j-1] = '#';
            MatricaKaraktera[i-1][j+1] = '#';
            MatricaKaraktera[i-1][j-1] = '#';
            MatricaKaraktera[i-2][j+1] = '#';
            MatricaKaraktera[i-2][j-1] = '#';
            MatricaKaraktera[i+1][j-1] = '#';
            MatricaKaraktera[i+1][j+1] = '#';
         }
      }
   }

   /// d - POLUKRUG OKRENUT KA GORE
   for(int i=1; i<=Y; i++)
   {
      for(int j=1; j<=X; j++)
      {
         if(MatricaKaraktera[i][j] == 'd')
         {
            MatricaKaraktera[i+1][j] = 'p';

            MatricaKaraktera[i+1][j-1] = '#';
            MatricaKaraktera[i+1][j+1] = '#';

            MatricaKaraktera[i][j-1] = '#';
            MatricaKaraktera[i][j+1] = '#';

            MatricaKaraktera[i-1][j-1] = '#';
            MatricaKaraktera[i-1][j] = '#';
            MatricaKaraktera[i-1][j+1] = '#';

            MatricaKaraktera[i+2][j-1] = '#';
            MatricaKaraktera[i+2][j+1] = '#';
         }
      }
   }

   /// g - POLUKRUG OKRENUT KA LEVO
   for(int i=1; i<=Y; i++)
   {
      for(int j=1; j<=X; j++)
      {
         if(MatricaKaraktera[i][j] == 'g')
         {
            MatricaKaraktera[i][j+1] = 'p';

            MatricaKaraktera[i-1][j+2] = '#';
            MatricaKaraktera[i-1][j] = '#';
            MatricaKaraktera[i-1][j+1] = '#';


            MatricaKaraktera[i+1][j+2] = '#';
            MatricaKaraktera[i+1][j] = '#';
            MatricaKaraktera[i+1][j+1] = '#';

            MatricaKaraktera[i-1][j-1] = '#';
            MatricaKaraktera[i+1][j-1] = '#';
            MatricaKaraktera[i][j-1] = '#';
         }
      }
   }


   /// c -  NISTA SE NE MOZE ZAKLJUCITI

   /// b - KRUG VODE OKOLO
   for(int i=1; i<=Y; i++)
   {
      for(int j=1; j<=X; j++)
      {
         if(MatricaKaraktera[i][j] == 'b')
         {
            MatricaKaraktera[i-1][j-1] = '#';
            MatricaKaraktera[i-1][j] = '#';
            MatricaKaraktera[i-1][j+1] = '#';

            MatricaKaraktera[i][j-1] = '#';
            MatricaKaraktera[i][j+1] = '#';

            MatricaKaraktera[i+1][j-1] = '#';
            MatricaKaraktera[i+1][j] = '#';
            MatricaKaraktera[i+1][j+1] = '#';
         }
      }
   }
}

void UPISIVANJE_VODE()
{
   for(int i=1; i<=Y; i++)
   {
      br = 0;
      for(int j=1; j<=X; j++)
      {
         if(MatricaKaraktera[i][j] != '#' and MatricaKaraktera[i][j] != '.')
            br++;
      }

      if(br == Red[i])
      {
         for(int j=1; j<=X; j++)
         {
            if(MatricaKaraktera[i][j] == '.')
               MatricaKaraktera[i][j] = '#';
         }
      }
   }


   for(int i=1; i<=X; i++)
   {
      br = 0;
      for(int j=1; j<=Y; j++)
      {
         if(MatricaKaraktera[j][i] != '#' and MatricaKaraktera[j][i] != '.')
            br++;
      }

      if(br == Kolona[i])
      {
         for(int j=1; j<=Y; j++)
         {
            if(MatricaKaraktera[j][i] == '.')
               MatricaKaraktera[j][i] = '#';
         }
      }
   }
}

int main()
{
   ULAZ();

   INICIJALIZACIJA();
   UPISIVANJE_VODE();

   ISPIS_MATRICE();
   return 0;
}
