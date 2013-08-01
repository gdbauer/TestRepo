#include <iostream>

#include "PrimzahlenSieben.h"

using namespace std;

const unsigned char AE = static_cast<unsigned char>(142);
const unsigned char ae = static_cast<unsigned char>(132);
const unsigned char OE = static_cast<unsigned char>(153);
const unsigned char oe = static_cast<unsigned char>(148);
const unsigned char UE = static_cast<unsigned char>(154);
const unsigned char ue = static_cast<unsigned char>(129);
const unsigned char ss = static_cast<unsigned char>(225);

bool *feld;

void InitialisiereFeld (int feldgroesse)
{
   feld = new bool[feldgroesse];

   for (int i = 0; i < feldgroesse; ++i) {
      feld[i] = true;
   }

   feld[0] = false;
   feld[1] = false;
   feld[2] = true;
}

void SiebePrimzahlen (int feldgroesse)
{
   for (int i = 2; i*i < feldgroesse; i++) {
      if (feld[i] == true) {
            for (int j = i; j < feldgroesse; ++j) {
               int h = i * j;
               if (h < feldgroesse) {
                  feld[h] = false; 
               }
           }
      }
   }
}

void FeldAusgeben (int feldgroesse)
{
   for (int i = 2; i < feldgroesse; ++i) {
      cout << i << " " << feld[i] << endl;
   }

   delete feld;
}

int main()
{
   int feldgroesse;


   cout << "Geben sie die Maximale Feldgr" << oe << ss << "e an: ";
   cin >> feldgroesse;

   InitialisiereFeld(feldgroesse);
   SiebePrimzahlen(feldgroesse);
   FeldAusgeben(feldgroesse);

   cin >> feldgroesse;

   return 0;
}