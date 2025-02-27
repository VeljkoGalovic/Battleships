#include<bits/stdc++.h>
using namespace std;
char MatricaKaraktera[100][100];
int X, Y, Red[100], Kolona[100], br, BrBrodova;
bool Provera1 = 1, Provera2 = 1, Provera3 = 1;
string str;

/// LEGENDA:
/// e - POLUKRUG OKRENUT KA DESNO
/// f - POLUKRUG OKRENUT KA DOLE
/// d - POLUKRUG OKRENUT KA GORE
/// g - POLUKRUG OKRENUT KA LEVO
/// c - KVADRAT
/// b - KRUG
/// p - BROD KOJI JE DODAO PROGRAM
/// # - VODA
/// . - PRAZNO

void ULAZ()
{
   memset(MatricaKaraktera, '#', sizeof(MatricaKaraktera));

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


   /// c -  VODA IDE DIJAGONALNO OD NJEGA
   for(int i=1; i<=Y; i++)
   {
      for(int j=1; j<=X; j++)
      {
         if(MatricaKaraktera[i][j] == 'c') /// AKO JE KVADRAT TU
         {
            MatricaKaraktera[i+1][j-1] = '#';
            MatricaKaraktera[i+1][j+1] = '#';
            MatricaKaraktera[i-1][j-1] = '#';
            MatricaKaraktera[i-1][j+1] = '#';
         }
      }
   }


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

bool PROVERA_VODE()
{
   bool temp = 0;

   for(int i=1; i<=Y; i++)
   {
      br = 0;
      for(int j=1; j<=X; j++)
      {
         if(MatricaKaraktera[i][j] != '#' and MatricaKaraktera[i][j] != '.') /// AKO IMA DOVOLJNO BRODOVA
            br++;
      }

      if(br == Red[i])
      {
         for(int j=1; j<=X; j++)
         {
            if(MatricaKaraktera[i][j] == '.')
            {
               MatricaKaraktera[i][j] = '#';
               temp = 1;
            }
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
            {
               MatricaKaraktera[j][i] = '#';
               temp = 1;
            }
         }
      }
   }

   return temp;
}
bool PROVERA_BRODOVA()
{
   bool temp = 0;
   /// PROVERA REDA - OK JE
   for(int i=1; i<=Y; i++)
   {
      br = 0;
      BrBrodova = 0;
      for(int j=1; j<=X; j++)
      {
         if(MatricaKaraktera[i][j] == '.') /// SABERI SVA PRAZNA POLJA
            br++;

         if(MatricaKaraktera[i][j] != '.' and MatricaKaraktera[i][j] != '#') /// SABERI SVE BRODOVE
            BrBrodova++;
      }



      if(br == (Red[i]-BrBrodova) and br != 0) /// AKO JE JEDANKO, SVA PRAZNA POLJA SU BRODOVI
      {
         for(int j=1; j<=X; j++)
         {
            if(MatricaKaraktera[i][j] == '.')
            {
               MatricaKaraktera[i][j] = 'p';
               temp = 1;
            }
         }
      }
   }


   for(int i=1; i<=X; i++)
   {
      br = 0;
      BrBrodova = 0;

      for(int j=1; j<=Y; j++)
      {
         if(MatricaKaraktera[j][i] == '.') /// SABERI SVA PRAZNA POLJA
            br++;

         if(MatricaKaraktera[j][i] != '.' and MatricaKaraktera[j][i] != '#') /// SABERI SVE BRODOVE
            BrBrodova++;
      }

      if(br == (Kolona[i]-BrBrodova) and br != 0)
      {
         for(int j=1; j<=Y; j++)
         {
            if(MatricaKaraktera[j][i] == '.')
            {
               MatricaKaraktera[j][i] = 'p';
               temp = 1;
            }
         }
      }
   }

   return temp;
}
bool PROVERA_KVADRATA()
{
   bool temp = 0;
   for(int i=1; i<=Y; i++)
   {
      for(int j=1; j<=X; j++)
      {
         if(MatricaKaraktera[i][j] == 'c')
         {
            if(MatricaKaraktera[i+1][j] == '#' or MatricaKaraktera[i-1][j] == '#')
            {
               temp = 1;
               MatricaKaraktera[i+1][j] = '#'; /// OBA SU MI VODA ZASIGURNO
               MatricaKaraktera[i-1][j] = '#';

               if(MatricaKaraktera[i][j-1] == 'p' and MatricaKaraktera[i][j+1] == 'p')
                  temp = 0;

               MatricaKaraktera[i][j-1] = 'p'; /// IMAM BROD SA NJEGOVE OBE STRANE
               MatricaKaraktera[i][j+1] = 'p';

               MatricaKaraktera[i-1][j-1] = '#'; /// VODA ISPOD I IZNAD OVA DVA SA STRANE
               MatricaKaraktera[i+1][j-1] = '#';
               MatricaKaraktera[i-1][j+1] = '#';
               MatricaKaraktera[i+1][j+1] = '#';


               MatricaKaraktera[i-1][j-2] = '#'; /// VODA DIJAGONALNO OD OVA DVA SA STRANE
               MatricaKaraktera[i+1][j-2] = '#';
               MatricaKaraktera[i-1][j+2] = '#';
               MatricaKaraktera[i+1][j+2] = '#';
            }

            if(MatricaKaraktera[i][j+1] == '#' or MatricaKaraktera[i][j-1] == '#')
            {
               temp = 1;
               MatricaKaraktera[i][j+1] = '#'; /// VODA SIGURNO IDE I LEVO I DESNO
               MatricaKaraktera[i][j-1] = '#';

               if(MatricaKaraktera[i][j-1] == 'p' and MatricaKaraktera[i][j+1] == 'p')
                  temp = 0;

               MatricaKaraktera[i-1][j] = 'p'; /// BRODOVI SIGURNO IDU GORE I DOLE
               MatricaKaraktera[i+1][j] = 'p';

               MatricaKaraktera[i-1][j+1] = '#'; /// VODA IDE SA STRANE BRODOVA GORE I DOLE
               MatricaKaraktera[i-1][j-1] = '#';
               MatricaKaraktera[i+1][j+1] = '#';
               MatricaKaraktera[i+1][j-1] = '#';

               MatricaKaraktera[i-2][j+1] = '#'; /// VODA IDE DIJAGONALNO OD BRODOVA
               MatricaKaraktera[i-2][j-1] = '#';
               MatricaKaraktera[i+2][j+1] = '#';
               MatricaKaraktera[i+2][j-1] = '#';
            }
         }
      }
   }

   return temp;
}

int main()
{
   ULAZ();
   ISPIS_MATRICE();
   INICIJALIZACIJA();

   while(Provera1 or Provera2 or Provera3) /// SKENIRANJE - UPISUJE STVARI KOJE ZNA ZASIGURNO
   {
      Provera1 = PROVERA_VODE();
      Provera2 = PROVERA_KVADRATA();
      Provera3 = PROVERA_BRODOVA();
   }

   /// OVDE JOS SAMO DODATI REKURZIJU
   ISPIS_MATRICE();
   return 0;
}
