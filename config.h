//SSID and Password of your WiFi router

const char* ssid = "ssid";
const char* password = "password";




//Fächer max.15 entsprechen den Pins(0-15) an den Schieberegistern (Beispiel)

#define M 1 //Mathe
#define G 2 //Geschichte
#define MU 3  //Musik
#define SPORT 4 //Sport
#define EK 5  //Erdkunde
#define E 6 //Englisch
#define BIO 7 //Biologie
#define PH 8  //Physik
#define BK 9  //Bk
#define R 10  //Religion
#define NWT 11  //NwT
#define CH 12 //Chemie
#define F 13  //Französich
#define GK 14 //Gemeinschaftskunde
#define D 15  //Deutsch

//Stundenplan für max. 15 Fächer je Tag (Beispiel)

const int timetable [5] [16] = {
  {EK, NWT, D, M},  //Montag
  {BIO, SPORT, PH, MU, BK}, //Dienstag
  {R, G, D, M, NWT}, //Mittwoch
  {NWT, CH, BIO, F, E}, //Donnerstag
  {SPORT, F, GK, E, PH} //Freitag
};


