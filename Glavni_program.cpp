/// PROBLEM HEURISITKE RESITI DODAVANJEM NIZA POLJA KOJI JE SORTIRAN PO REDU KOJIM SE POLJA TREBAJU POSECIVATI I RESETOVATI IH POSLE SVAKOG POKUSAJA
#include<bits/stdc++.h>
using namespace std;
char MatricaKaraktera[100][100], KopijaMatrice[100][100], KopijaMatrice2[100][100], Resenje[100][100];
int X, Y, Red[100], Kolona[100], br, BrBrodova, br_ispisa;
bool Provera1 = 1, Provera2 = 1, Provera3 = 1, Provera4;
string str;
stack<int> stek;
int Velicina, Jedinice, Dvojke, Trojke, Cetvorke, Brojac, brHeuristike, slobodni, priv1, priv2, kvadrat;
bool temp;
struct slog
{
   int koordx;
   int koordy;
   int velr;
   int velk;
};
slog Heuristika[150];
bool pos[100][100];
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

bool cmp(slog a, slog b)
{
   return a.velr < b.velr;
   return a.velk < b.velk;
}
void ULAZ() /// DESPAGETIRAN
{
   /// RESETOVANJE MATRICA RADI IZBEGAVANJA GRESAKA
   memset(MatricaKaraktera, '#', sizeof(MatricaKaraktera));
   memset(KopijaMatrice, '#', sizeof(KopijaMatrice));

   /// UCITAVANJE PODATAKA IZ FAJLA
   freopen("Ships.in", "r", stdin);

   /// DIMENZIJE TABLE
   cin >> X >> Y;


   for(int i=1; i<=Y; i++)
   {
      /// POLJA U MATRICI
      for(int j=1; j<=X; j++)
         cin >> MatricaKaraktera[i][j];

      /// UNOS BROJA BRODOVA U REDU
      if(i != Y)
         cin >> Red[i];

      /// UNOS BROJA BRODOVA POSLEDNJEG REDA
      else
      {
         cin >> str;
         Red[i] = str[0]-48;
      }
   }

   /// UNOS BROJA BRODOVA PO KOLONAMA
   for(int i=1; i<str.size(); i++)
      Kolona[i] = str[i] - 48;

   /// CITANJE SE VRACA NA KOZOLU
   freopen("CON", "r", stdin);
}

void INICIJALIZACIJA() /// DESPAGETIRAN
{
   /// e - POLUKRUG OKRENUT KA DESNO
   /// MOZE SE ZAKLJUCITI DA JEDAN BROD STOJI DESNO OD NJEGA I VODA STOJI OKO TA DVA POLJA
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
   /// MOZE SE ZAKLJUCITI DA JEDAN BROD STOJI DOLE OD NJEGA I DA VODA STOJI OKO TA DVA POLJA
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
   /// MOZE SE ZAKLJUCITI DA JEDAN BROD STOJI GORE OD NJEGA I DA VODA STOJI OKO TA DVA POLJA
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
   /// MOZE SE ZAKLJUCITI DA JEDAN BROD STOJI LEVO OD NJEGA I DA VODA STOJI OKO TA DVA POLJA
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
   /// MOZE SE ZAKLJUCITI DA VODA STOJI DIJAGONALNO OD NJEGA POSTO NE ZNAMO KAKO JE BROD ORIJENTISAN
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
   /// MOZE SE ZAKLJUCITI DA KRUG VODE STOJI OKO NJEGA
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

bool UPIS_VODE() /// DESPAGETIRAN
{
   /// TEMP - VREDNOST KOJU VRACA
   temp = 0;

   for(int i=1; i<=Y; i++)
   {
      /// BROJI ZAUZETA POLJA U REDU
      br = 0;
      for(int j=1; j<=X; j++)
      {
         if(MatricaKaraktera[i][j] != '#' and MatricaKaraktera[i][j] != '.')
            br++;
      }

      /// AKO JE RED ISPUNJEN BRODOVIMA UPISE VODU U OSTATKU REDA
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
      /// BROJI ZAUZETA POLJA U KOLONI
      br = 0;
      for(int j=1; j<=Y; j++)
      {
         if(MatricaKaraktera[j][i] != '#' and MatricaKaraktera[j][i] != '.')
            br++;
      }

      /// AKO JE KOLONA ISPUNJENA BRODOVIMA UPISE VODU U OSTATKU KOLONE
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

   /// AKO JE PROMENIO NESTO VRATI 1
   return temp;
}

bool PROVERA_BRODOVA() /// DESPAGETIRAN
{
   temp = 0;
   /// PROVERA REDA - OK JE
   for(int i=1; i<=Y; i++)
   {
      /// PROVERA MOGUCNOSTI UPISIVANJE BRODOVA U SVA PRAZNA POLJA U REDU
      br = 0;
      BrBrodova = 0;
      for(int j=1; j<=X; j++)
      {
         /// ZBIR SVIH PRAZNIH POLJA
         if(MatricaKaraktera[i][j] == '.')
            br++;

         /// ZBIR SVIH POLJA ISPUNJENIH BRODOVIMA
         if(MatricaKaraktera[i][j] != '.' and MatricaKaraktera[i][j] != '#')
            BrBrodova++;
      }

      /// AKO JE BROJ PRAZNIH POLJA JEDNAK BROJU RAZLICI UKUPNOG BROJA BRODOVA U REDU I BROJA BRODOVA KOJI JE TRENUTNO U REDU I NIJE NULA, ONDA SU SVA PRAZNA POLJA ISPUNJENA BRODOVIMA
      if(br == (Red[i]-BrBrodova) and br != 0)
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
      /// PROVERA MOGUCNOSTI UPISIVANJE BRODOVA U SVA PRAZNA POLJA U KOLONI
      br = 0;
      BrBrodova = 0;
      for(int j=1; j<=Y; j++)
      {
         /// ZBIR SVIH PRAZNIH POLJA
         if(MatricaKaraktera[j][i] == '.')
            br++;

         /// ZBIR SVIH POLJA ISPUNJENIH BRODOVIMA
         if(MatricaKaraktera[j][i] != '.' and MatricaKaraktera[j][i] != '#')
            BrBrodova++;
      }

      /// AKO JE BROJ PRAZNIH POLJA JEDNAK BROJU RAZLICI UKUPNOG BROJA BRODOVA U KOLONI I BROJA BRODOVA KOJI JE TRENUTNO U KOLONI I NIJE NULA, ONDA SU SVA PRAZNA POLJA ISPUNJENA BRODOVIMA
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

bool PROVERA_KVADRATNIH_BRODOVA() /// DESPAGETIRAN
{
   temp = 0;
   for(int i=1; i<=Y; i++)
   {
      for(int j=1; j<=X; j++)
      {
         /// AKO MI JE POLJE KVADRAT
         if(MatricaKaraktera[i][j] == 'c')
         {
            /// AKO JE VODA ISPOD ILI IZNAD
            if(MatricaKaraktera[i+1][j] == '#' or MatricaKaraktera[i-1][j] == '#')
            {
               temp = 1;
               /// OBA POLJA SU VODA ZASIGURNO
               MatricaKaraktera[i+1][j] = '#';
               MatricaKaraktera[i-1][j] = '#';

               /// AKO JE OVAJ KVADRAT VEC OBRADJEN FUNKCIJA NE TREBA DA VRATI 1
               if(MatricaKaraktera[i][j-1] == 'p' and MatricaKaraktera[i][j+1] == 'p')
                  temp = 0;

               /// POLJA LEVO I DESNO SU BROD
               MatricaKaraktera[i][j-1] = 'p';
               MatricaKaraktera[i][j+1] = 'p';

               /// UPISIVANJE VODE U OSTALA POLJA
               MatricaKaraktera[i-1][j-1] = '#';
               MatricaKaraktera[i+1][j-1] = '#';
               MatricaKaraktera[i-1][j+1] = '#';
               MatricaKaraktera[i+1][j+1] = '#';
               MatricaKaraktera[i-1][j-2] = '#';
               MatricaKaraktera[i+1][j-2] = '#';
               MatricaKaraktera[i-1][j+2] = '#';
               MatricaKaraktera[i+1][j+2] = '#';
            }

            /// AKO JE VODA LEVO ILI DESNO OD KVADRATA
            if(MatricaKaraktera[i][j+1] == '#' or MatricaKaraktera[i][j-1] == '#')
            {
               temp = 1;
               /// VODA SIGURNO IDE I LEVO I DESNO
               MatricaKaraktera[i][j+1] = '#';
               MatricaKaraktera[i][j-1] = '#';

               /// AKO JE OVAJ KVADRAT VEC OBRADJEN FUNKCIJA NE TREBA DA VRATI 1
               if(MatricaKaraktera[i-1][j] == 'p' and MatricaKaraktera[i+1][j] == 'p')
                  temp = 0;

               /// POLJA ISPOD I IZNAD SU SIGURNO BROD
               MatricaKaraktera[i-1][j] = 'p';
               MatricaKaraktera[i+1][j] = 'p';

               /// UPSIIVANJE VODE U OSTALA POLJA
               MatricaKaraktera[i-1][j+1] = '#';
               MatricaKaraktera[i-1][j-1] = '#';
               MatricaKaraktera[i+1][j+1] = '#';
               MatricaKaraktera[i+1][j-1] = '#';
               MatricaKaraktera[i-2][j+1] = '#';
               MatricaKaraktera[i-2][j-1] = '#';
               MatricaKaraktera[i+2][j+1] = '#';
               MatricaKaraktera[i+2][j-1] = '#';
            }

            /// ISTO SAMO AKO SKONTA DA JE BROD OKOLO
            if(MatricaKaraktera[i+1][j] == 'p' or MatricaKaraktera[i-1][j] == 'p')
            {
               temp = 1;

               MatricaKaraktera[i+1][j] = 'p';
               MatricaKaraktera[i-1][j] = 'p';

               /// AKO JE OVAJ KVADRAT VEC OBRADJEN FUNKCIJA NE TREBA DA VRATI 1
               if(MatricaKaraktera[i][j-1] == '#' and MatricaKaraktera[i][j+1] == '#')
                  temp = 0;


               /// POLJA LEVO I DESNO SU VODA
               MatricaKaraktera[i][j-1] = '#';
               MatricaKaraktera[i][j+1] = '#';

               /// UPISIVANJE VODE U OSTALA POLJA
               MatricaKaraktera[i+2][j+1] = '#';
               MatricaKaraktera[i+2][j-1] = '#';
               MatricaKaraktera[i-2][j-1] = '#';
               MatricaKaraktera[i-2][j+1] = '#';
            }


            if(MatricaKaraktera[i][j-1] == 'p' or MatricaKaraktera[i][j+1] == 'p')
            {
               temp = 1;

               MatricaKaraktera[i][j+1] = 'p';
               MatricaKaraktera[i][j-1] = 'p';

               /// AKO JE OVAJ KVADRAT VEC OBRADJEN FUNKCIJA NE TREBA DA VRATI 1
               if(MatricaKaraktera[i-1][j] == '#' and MatricaKaraktera[i+1][j] == '#')
                  temp = 0;


               /// POLJA GORE I DOLE SU VODA
               MatricaKaraktera[i-1][j] = '#';
               MatricaKaraktera[i+1][j] = '#';

               /// UPISIVANJE VODE U OSTALA POLJA
               MatricaKaraktera[i+1][j+2] = '#';
               MatricaKaraktera[i+1][j-2] = '#';
               MatricaKaraktera[i-1][j-2] = '#';
               MatricaKaraktera[i-1][j+2] = '#';
            }
         }
      }
   }

   return temp;
}

void KOPIRAJ_MATRICU() /// DESPAGETIRAN
{
   /// PREPISI MATRICU U KOPIJUMATRICE
   for(int i=1; i<=Y; i++)
   {
      for(int j=1; j<=X; j++)
         KopijaMatrice[i][j] = MatricaKaraktera[i][j];
   }

   for(int i=1; i<=Y; i++)
   {
      for(int j=1; j<=X; j++)
         KopijaMatrice2[i][j] = MatricaKaraktera[i][j];
   }
}

bool PUNA() /// DESPAGETIRAN
{
   /// AKO JE MATRICA PUNA VRATI 1 U SUPROTNOM 0
   for(int i=1; i<=Y; i++)
   {
      for(int j=1; j<=X; j++)
      {
         if(KopijaMatrice[i][j] == '.')
            return 0;
      }
   }

   return 1;
}

void DFS(int i, int j) /// DESPAGETIRAN
{
   /// DFS RADI ODREDJIVANJA VELICINE BRODA
   pos[i][j] = 1;
   stek.push(1);

   if(KopijaMatrice[i+1][j] != '#' and pos[i+1][j] == 0)
      DFS(i+1, j);
   if(KopijaMatrice[i-1][j] != '#' and pos[i-1][j] == 0)
      DFS(i-1, j);
   if(KopijaMatrice[i][j+1] != '#' and pos[i][j+1] == 0)
      DFS(i, j+1);
   if(KopijaMatrice[i][j-1] != '#' and pos[i][j-1] == 0)
      DFS(i, j-1);
}

bool USLOVI() /// DESPAGETIRAN
{
   /// INICIJALIZACIJA
   Jedinice = 4;
   Dvojke = 3;
   Trojke = 2;
   Cetvorke = 1;
   memset(pos, 0, sizeof(pos));

   /// PROVERA POSOTJANJA ADEKVATNOG BROJA BRODOVA ODGOVARAJUCIH VELICINA
   for(int i=1; i<=Y; i++)
   {
      for(int j=1; j<=X; j++)
      {
         /// AKO JE POLJE NEPOSECENI BROD ODREDI NJEGOVU VELICINU
         if(KopijaMatrice[i][j] != '#' and pos[i][j] == 0)
         {
            while(stek.empty() == false)
               stek.pop();
            DFS(i, j);
            Velicina = stek.size();
            //cout << Velicina << "\n";
            if(Velicina == 1)
               Jedinice--;

            if(Velicina == 2)
               Dvojke--;

            if(Velicina == 3)
               Trojke--;

            if(Velicina == 4)
               Cetvorke--;
         }
      }
   }

   /// AKO SU SVI USLOVI ZADOVOLJENI IMAS RESENJE
   if(Jedinice == 0 and Dvojke == 0 and Trojke == 0 and Cetvorke == 0)
      return 1;
   return 0;
}

void KOPIRAJ_RESENJE() /// DESPAGETIRAN
{
   /// KOPIRANJE MATRICE U CITLJIVIJI PRIKAZ
   for(int i=1; i<=Y; i++)
   {
      for(int j=1; j<=X; j++)
      {
         if(KopijaMatrice[i][j] == '#')
            Resenje[i][j] = '.';
         else
            Resenje[i][j] = 'b';
      }
   }
}

void ISPIS_KOPIJE() /// DESPAGETIRAN - UKLONITI U FINALNOJ VERZIJI
{
   /// ISPIS KOPIJE MATRICE - SAMO RADI DEBUGOVANJA
   for(int i=1; i<=Y; i++)
   {
      for(int j=1; j<=X; j++)
         cout << KopijaMatrice2[i][j] << " ";
      cout << "\n";
   }
   cout << "\n\n";
}

bool PROVERA_ZBIRA() /// DESPAGETIRAN
{
   Brojac = 0;

   /// PROVERA ZBIRA BROJA BRODOVA PO REDOVIMA
   for(int i=1; i<=Y; i++)
   {
      Brojac = 0;
      for(int j=1; j<=X; j++)
      {
         if(KopijaMatrice[i][j] != '#')
            Brojac++;
      }

      if(Red[i] != Brojac)
         return 0;
   }

   /// PROVERA ZBIRA BROJA BRODOVA PO KOLONAMA
   for(int i=1; i<=Y; i++)
   {
      Brojac = 0;
      for(int j=1; j<=X; j++)
      {
         if(KopijaMatrice[j][i] != '#')
            Brojac++;
      }

      if(Kolona[i] != Brojac)
         return 0;
   }

   return 1;
}

bool PROVERA_DIJAGONALA() /// DESPAGETIRAN
{
   /// AKO SE BROD NALAZI DIJAGONALNO OD POLJA RESENJE NIJE ISPRAVNO
   for(int i=1; i<=Y; i++)
   {
      for(int j=1; j<=X; j++)
      {
         if(KopijaMatrice[i][j] != '#')
         {
            //cout << i << " " << j << ": " << KopijaMatrice[i+1][j+1] << " "  << KopijaMatrice[i-1][j-1] << " " << KopijaMatrice[i-1][j+1]  << " " << KopijaMatrice[i+1][j-1] << "\n";
            if(KopijaMatrice[i+1][j+1] != '#' or KopijaMatrice[i-1][j-1] != '#' or KopijaMatrice[i-1][j+1] != '#' or KopijaMatrice[i+1][j-1] != '#')
               return 0;
         }
      }
   }
   return 1;
}

bool ODGOVARA() /// DESPAGETIRAN
{
   /// AKO JE MATRICA PUNA I AKO SU SVI USLOVI ZADOVOLJENI IMAS RESENJE
   if(PUNA())
   {
      /// PROVERA POSTOJANJA ADEKVATNOG BROJA BRODOVA RAZLICITIH VELICINA I NJIHOVOG RASPOREDA
      if(USLOVI() and PROVERA_ZBIRA() and PROVERA_DIJAGONALA())
         return 1;
   }
   return 0;
}

bool VALIDAN_ZBIR(int a, int b) /// DESPAGETIRAN
{
   /// PROVERA PRELASKA OGRANICENJA ZA RED
   Brojac = 0;
   for(int i=1; i<=X; i++)
   {
      if(KopijaMatrice[a][i] != '#' and KopijaMatrice[a][i] != '.')
         Brojac++;
   }
   if(Brojac > Red[a])
      return 0;

   /// PROVERA PRELASKA OGRANICENJA ZA KOLONU
   Brojac = 0;
   for(int i=1; i<=X; i++)
   {
      if(KopijaMatrice[i][b] != '#' and KopijaMatrice[i][b] != '.')
         Brojac++;
   }
   if(Brojac > Kolona[b])
      return 0;

   return 1;
}

void ISPIS_RESENJA() /// DESPAGETIRAN
{
   cout << "\n\n\n. - voda, b - brod\n";
   /// ISPIS
   for(int i=1; i<=Y; i++)
   {
      for(int j=1; j<=X; j++)
         cout << Resenje[i][j] << " ";
      cout << "\n";
   }
}

string HEURISTICNI_KVADRAT() /// NE RADI, ZNAM STA DODUSE - TEKST UNUTRA
{
   string str;
   /// OBRATIM PAZNJU NA REKURZIJU POSLE SVAKOG POZIVA VREDNOST U MATRICI SE RESETUJE NA PRAZNO POLJE FALI MI IMPLEMENTACIJA TOGA JER POSLE SVIH PRVOG FILOVANJA KAKO STIGNE ON NE KRENE DA CISTI MATRICU I PROBAVA NOVE MOGUCNOSTI
   brHeuristike = 0;
   memset(Heuristika, 0, sizeof(Heuristika));

   /// ODREDJIVANJE POLJA KOJA SU SLOBODNA I BROJA SLOBODNIH POLJA U NJIHOVIM REDOVIMA I KOLONAMA
   for(int i=1; i<=Y; i++)
   {
      for(int j=1; j<=X; j++)
      {
         if(KopijaMatrice[i][j] == '.')
         {
            brHeuristike++;
            Heuristika[brHeuristike].koordx = i;
            Heuristika[brHeuristike].koordy = j;

            /// BROJ SLOBODNIH MESTA U REDU
            slobodni = 0;
            for(int k=1; k<=X; k++)
            {
               if(KopijaMatrice[i][k] == '.')
                  slobodni++;
            }
            Heuristika[brHeuristike].velr = slobodni;

            slobodni = 0;
            for(int k=1; k<=X; k++)
            {
               if(KopijaMatrice[k][j] == '.')
                  slobodni++;
            }
            Heuristika[brHeuristike].velk = slobodni;
         }
      }
   }

   /// STAVLJAMO MANJI BROJ NA PRVO MESTO RADI LAKSEG ODREDJIVANJA KVADRATA
   for(int i=1; i<=brHeuristike; i++)
   {
      priv1 = Heuristika[i].velr;
      priv2 = Heuristika[i].velk;

      Heuristika[i].velr = min(priv1, priv2);
      Heuristika[i].velk = max(priv1, priv2);

      //cout << Heuristika[i].koordx << " " << Heuristika[i].koordy << " " << Heuristika[i].velr << " " << Heuristika[i].velr << "\n";
   }


   /// TRPAM SVE U STRING KAKO BIH MU MOGAO PRISTUPITI U REKURZIJI
   sort(Heuristika+1, Heuristika+1+brHeuristike, cmp);
   for(int i=1; i<=brHeuristike; i+=2)
   {
      str[i-1] = Heuristika[i].koordx + 48;
      str[i] = Heuristika[i].koordy + 48;
   }
   return str;
}


void REKURZIJA(int a, int b) /// DESPAGETIRAN
{
   /// PROBAJ SA BRODOM, DODAJ ODSECANJE DA NE MOZE AKO USLOVI NISU ISPUNJENI, TJ. AKO JE OVO > OD USLOVA
   KopijaMatrice[a][b] = 'p';


   /// PROVERA MOGUCNOSTI UPISIVANJA BRODA
   if(VALIDAN_ZBIR(a, b))
   {
      /// PROVERA RESENJA - SMANJENO U JEDNU FUNKCIJU RADI CITKOSTI
      if(ODGOVARA())
      {
         KOPIRAJ_RESENJE();
         if(!br_ispisa)
            ISPIS_RESENJA();
         br_ispisa++;
         return;
      }

      for(int i=1; i<=Y; i++)
      {
         for(int j=1; j<=X; j++)
         {
            if(KopijaMatrice[i][j] == '.')
            {
               REKURZIJA(i, j);
               KopijaMatrice[i][j] = '.';
            }
         }
      }

      /// SALJE REKURZIJU DALJE
      //string obidji = HEURISTICNI_KVADRAT();
      //for(int i=0; i<obidji.size(); i+=2)
      //{
      //   REKURZIJA(obidji[i]-48, obidji[i+1]-48);
      //   KopijaMatrice[obidji[i]-48][obidji[i+1]-48] = '.';
      //}
   }




   /// PROBAJ SA VODOM
   KopijaMatrice[a][b] = '#';


   /// PROVERA RESENJA - SMANJENO U JEDNU FUNKCIJU RADI CITKOSTI
   if(ODGOVARA())
   {
      KOPIRAJ_RESENJE();
      if(!br_ispisa)
            ISPIS_RESENJA();
         br_ispisa++;
      return;
   }

   /// SALJE REKURZIJU DALJE

   for(int i=1; i<=Y; i++)
   {
      for(int j=1; j<=X; j++)
      {
         if(KopijaMatrice[i][j] == '.')
         {
            REKURZIJA(i, j);
            KopijaMatrice[i][j] = '.';
         }
      }
   }


   /// SALJE REKURZIJU DALJE
   //string obidji = HEURISTICNI_KVADRAT();
   //for(int i=0; i<obidji.size(); i+=2)
   //{
   //   REKURZIJA(obidji[i]-48, obidji[i+1]-48);
   //   KopijaMatrice[obidji[i]-48][obidji[i+1]-48] = '.';
   //}

}

bool PROVERA_UZASTOPNOSTI() /// DESPAGETIRAN
{
   int prUzastopnosti = 0;
   bool ret = 0;

   /// AKO SE BROD POJAVLJUJE VODORAVNO ISPOD I IZNAD NJEGA IDE VODA
   for(int i=1; i<=Y; i++)
   {
      for(int j=1; j<=X; j++)
      {
         if(MatricaKaraktera[i][j] != '.' and MatricaKaraktera[i][j] != '#')
            prUzastopnosti++;

         else
         {
            if(prUzastopnosti > 1)
            {
               for(int k=0; k<prUzastopnosti; k++)
               {
                  if(MatricaKaraktera[i-1][j-prUzastopnosti+k] != '#' or MatricaKaraktera[i+1][j-prUzastopnosti+k] != '#')
                     ret = 1;

                  MatricaKaraktera[i-1][j-prUzastopnosti+k] = '#';
                  MatricaKaraktera[i+1][j-prUzastopnosti+k] = '#';
               }
            }
            prUzastopnosti = 0;
         }
      }
   }
   prUzastopnosti = 0;


   /// AKO SE BROD POJAVLJUJE VERTIKALNO LEVO I DESNO JE VODA
   for(int i=1; i<=Y; i++)
   {
      for(int j=1; j<=X; j++)
      {
         if(MatricaKaraktera[j][i] != '.' and MatricaKaraktera[j][i] != '#')
            prUzastopnosti++;

         else
         {
            if(prUzastopnosti > 1)
            {
               for(int k=0; k<prUzastopnosti; k++)
               {
                  if(MatricaKaraktera[j-prUzastopnosti+k][i+1] != '#' or MatricaKaraktera[j-prUzastopnosti+k][i-1] != '#')
                     ret = 1;

                  MatricaKaraktera[j-prUzastopnosti+k][i+1] = '#';
                  MatricaKaraktera[j-prUzastopnosti+k][i-1] = '#';
               }
            }
            prUzastopnosti = 0;
         }
      }
   }
   return ret;
}

int main()
{
   ULAZ();
   INICIJALIZACIJA();

   /// SKENIRANJE - UPISIVANJE U POLJA CIJA SE STANJA MOGU ODREDITI DETERMINISTICKI
   while(Provera1 or Provera2 or Provera3)
   {
      Provera1 = UPIS_VODE();
      Provera2 = PROVERA_KVADRATNIH_BRODOVA();
      Provera3 = PROVERA_BRODOVA();

      /// NE RADI SKROZ
      Provera4 = 0;//PROVERA_UZASTOPNOSTI();
      cout << Provera1 << " " << Provera2 << " " << Provera3 << " " << Provera4 << "\n";
   }


   /// KOPIRANJE MATRICE RADI IZBEGAVANJA GRESAKA
   KOPIRAJ_MATRICU();

   // CISTO RADI TESTIRANJA
   ISPIS_KOPIJE();
   cout << "POCETAK REKURZIJE \n";

   /// REKURZIJA
   for(int i=1; i<=Y; i++)
   {
      for(int j=1; j<=X; j++)
      {
         if(KopijaMatrice[i][j] == '.')
         {
            REKURZIJA(i, j);
            break;
            //KopijaMatrice[i][j] = '.';
         }
      }
   }

   /*
   /// SALJE REKURZIJU DALJE
   string obidji = HEURISTICNI_KVADRAT();
   for(int i=0; i<obidji.size(); i+=2)
   {
      REKURZIJA(obidji[i]-48, obidji[i+1]-48);
      KopijaMatrice[obidji[i]-48][obidji[i+1]-48] = '.';
   }
   */
   return 0;
}
