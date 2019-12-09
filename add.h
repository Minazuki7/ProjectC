
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include <gtk/gtk.h>

//typedef struct date
//{
//int jour;
//int mois;
//int annee;
//}date1;
typedef struct
{
//date1 date;
char date[20];
char model[20];
char serie[20];
char couleur[20];
char prix[20];
}voitures;
typedef struct date
{
int jaller;
int maller;
int aaller;
int jrout;
int mrout;
int arout;
}date;
typedef struct
{
//date date;
char cin[10];    
char nom[10];
char prenom[10];
char tel[10];
//char typereservation[20];
char datealler[10];
char dateroutour[10];
}facture;
void ajouter_voitures(voitures *v);
void afficher_voitures(GtkWidget *liste,voitures v);
void search(char *cin);
void ajouter_facture(facture *fact);
void afficher_facture(GtkWidget *liste,facture fact);
facture *searching(char *elem);
void dell_user(char *serie);
void mod_user(char *serie);
void dell_fact(char *cin);
void mod_fact(char *cin);
