#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add.h"
#include <gtk/gtk.h>
#include<ctype.h>


enum
{
   DATE,
   MODEL,
   SERIE,
   COULEUR,
   PRIX,
   COLUMNS
};
facture *searching(char *elem)
{
 facture f;
  FILE *f1 =fopen("facture.bin","rb");
  int r=0;

  while(fread(&f,sizeof(facture),1,f1)==1 && r==0)
     if(strcmp(elem,f.nom) ==0)
         {r=1;
    g_print("found");
        return &f;
      }


fclose(f1);
return NULL;





   

}

void ajouter_voitures(voitures *v)
{
int nbvoitures=0;
FILE* f;
f=fopen("voitures.bin","ab"); 
if(f!=NULL) { 
fwrite(v,sizeof (voitures),1,f);
fclose(f);
}
}
void ajouter_facture(facture *fact)
{
int nbfacture=0;
FILE* f;
f=fopen("facture.bin","ab"); 
if(f!=NULL) { 
fwrite(fact,sizeof (facture),1,f);
fclose(f);
}
}
void afficher_voitures(GtkWidget *liste, voitures v)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;

  
  store=NULL;

  FILE *f;

  store=gtk_tree_view_get_model(liste);
  if (store==NULL)
  { renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(" date", renderer, "text",DATE, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
    
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(" model", renderer, "text",MODEL, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(" serie", renderer, "text",SERIE, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(" couleur", renderer, "text",COULEUR, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(" prix", renderer, "text",PRIX, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
    
   store = gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

   f = fopen("voitures.bin", "rb");
  
   if(f!=NULL)

   { 
             while(!(feof(f)))
       {
    fread(&v,sizeof(voitures),1,f);
   // char r1[20];
   // char r2[20];
   // char r3[20];
   // char date[20]="";
//sprintf(r1,"%d",v.date.jour);
//strcat(date,r1);
//strcat(date,"/");

//sprintf(r2,"%d",v.date.mois);
//strcat(date,r2);
//strcat(date,"/");

//sprintf(r3,"%d",v.date.annee);
//strcat(date,r3);
//strcat(date,"/");
    gtk_list_store_append (store, &iter);
    gtk_list_store_set (store, &iter, DATE, v.date, MODEL, v.model, SERIE, v.serie, COULEUR, v.couleur, PRIX, v.prix, -1);
        }
        fclose(f);
    gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
    g_object_unref (store);
   }
}
}
void dell_user(char *serie)
{
voitures v;
FILE *old;
FILE *new=NULL;

new=fopen("voitures_test.bin","wb");
fclose(new);

old=fopen("voitures.bin","rb");
new=fopen("voitures_test.bin","ab");

int i=0;
while(!(feof(old)))
       {i++;
        fread(&v,1,sizeof(voitures),old);
       }
fclose(old);
old=fopen("voitures.bin","rb");

int j=0;
while(j<i-1)
      {j++;
       fread(&v,1,sizeof(voitures),old);

       if(strcmp(v.serie,serie))
             {
             fwrite(&v,sizeof(voitures),1,new);
             }
      }
fclose(new);
fclose(old);
remove("voitures.bin");
rename("voitures_test.bin","voitures.bin");
}

void mod_user(char *serie)
{
voitures v;
FILE *old;
FILE *new=NULL;
/*****create a temporary file *****/
new=fopen("voit.bin","wb");
fclose(new);
/******copy data from old to new *******/
old=fopen("voitures.bin","rb");
new=fopen("voit.bin","ab");
/**************************/
int i=0;
while(!(feof(old)))
	{i++;
        fread(&v,1,sizeof(voitures),old);
	}
fclose(old);
old=fopen("voitures.bin","rb");
/******************************/
int j=0;
while(j<i)
	{j++;
       fread(&v,1,sizeof(voitures),old);
	
        if(strcmp(v.serie,serie))
             {
             fwrite(&v,sizeof(voitures),1,new);
             }
        else  if(strcmp(v.serie,serie)==0)  
                {
             fread(&v,sizeof(voitures),1,new);

                }
               
	}
fclose(new);
fclose(old);
remove("voitures.bin");//nfas5ou il fichier li9dim
rename("voit.bin","voitures.bin");//enronomiw il fichier ejdid b esm li9dim bech ye5ou blastou
g_print("%s",v.serie);
//return b;

/*****Na3mlo Actualiser lil liste **************/

}

/*void search(char *cin)
{
GtkWidget *entry2CIN;
facture fact;
FILE *old;
FILE *new=NULL;
gchar *CIN;
CIN=gtk_entry_get_text(GTK_ENTRY(entry2CIN));

new=fopen("fact.bin","wb");
fclose(new);

old=fopen("facture.bin","rb");
new=fopen("fact.bin","ab");

int i=0;
while(!(feof(old)))
       {i++;
        fread(&fact,1,sizeof(facture),old);
       }
fclose(old);
old=fopen("facture.bin","rb");

int j=0;
while(j<i-1)
      {j++;
       fread(&fact,1,sizeof(facture),old);

       if(strcmp(CIN,cin))
             {
             fwrite(&fact,sizeof(facture),1,new);
             }
      }
fclose(new);
fclose(old);
remove("facture.bin");
rename("fact.bin","facture.bin");

}*/
enum
{CIN,
NOM,
PRENOM,
Tel,
TYPERESERVATION,
DATEALLER,
DATEROUTOUR
};
void afficher_facture(GtkWidget *liste, facture fact)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;

  
  store=NULL;

  FILE *f;

  store=gtk_tree_view_get_model(liste);
  if (store==NULL)
  { renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(" cin", renderer, "text",CIN, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
    
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",NOM, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(" prenom", renderer, "text",PRENOM, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(" tel", renderer, "text",Tel, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   /* renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(" typereservation", renderer, "text",TYPERESERVATION, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);*/

    /*renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(" datealle", renderer, "text",DATEALLER, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(" dateroutour", renderer, "text",DATEROUTOUR, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
    */
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(" datealler", renderer, "text",DATEALLER, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(" dateroutour", renderer, "text",DATEROUTOUR, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   store = gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING/*, G_TYPE_STRING*/);

   f = fopen("facture.bin", "rb");
  
   if(f!=NULL)

   { 
             while(!(feof(f)))
       {
    fread(&fact,sizeof(facture),1,f);
    /*char r1[20];
    char r2[20];
    char r3[20];
    char r11[20];
    char r22[20];
    char r33[20];
    char date[20]="";
sprintf(r1,"%d",fact.date.jaller);
strcat(date,r1);
strcat(date,"/");

sprintf(r2,"%d",fact.date.maller);
strcat(date,r2);
strcat(date,"/");

sprintf(r3,"%d",fact.date.aaller);
strcat(date,r3);
strcat(date,"/");

sprintf(r11,"%d",fact.date.jrout);
strcat(date,r1);
strcat(date,"/");

sprintf(r22,"%d",fact.date.mrout);
strcat(date,r2);
strcat(date,"/");

sprintf(r33,"%d",fact.date.arout);
strcat(date,r3);
strcat(date,"/");*/
    gtk_list_store_append (store, &iter);
    gtk_list_store_set (store, &iter, CIN, fact.cin, NOM, fact.nom, PRENOM, fact.prenom, Tel, fact.tel, /*TYPERESERVATION, fact.typereservation,*/ DATEALLER, fact.datealler, DATEROUTOUR, fact.dateroutour /*DATEALLER, fact.date.jaller, fact.date.maller, fact.date.aaller, DATEROUTOUR, fact.date.jrout, fact.date.mrout, fact.date.arout*/,  -1);
        }
        fclose(f);
    gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
    g_object_unref (store);
   }
}
}
void dell_fact(char *cin)
{
facture fact;
FILE *old;
FILE *new=NULL;

new=fopen("facture_test.bin","wb");
fclose(new);

old=fopen("facture.bin","rb");
new=fopen("facture_test.bin","ab");

int i=0;
while(!(feof(old)))
       {i++;
        fread(&fact,1,sizeof(facture),old);
       }
fclose(old);
old=fopen("facture.bin","rb");

int j=0;
while(j<i-1)
      {j++;
       fread(&fact,1,sizeof(facture),old);

       if(strcmp(fact.cin,cin))
             {
             fwrite(&fact,sizeof(facture),1,new);
             }
      }
fclose(new);
fclose(old);
remove("facture.bin");
rename("facture_test.bin","voitures.bin");
}

void mod_fact(char *cin)
{
facture fact;
FILE *old;
FILE *new=NULL;
/*****create a temporary file *****/
new=fopen("fact.bin","wb");
fclose(new);
/******copy data from old to new *******/
old=fopen("facture.bin","rb");
new=fopen("fact.bin","ab");
/**************************/
int i=0;
while(!(feof(old)))
	{i++;
        fread(&fact,1,sizeof(facture),old);
	}
fclose(old);
old=fopen("facture.bin","rb");
/******************************/
int j=0;
while(j<i)
	{j++;
       fread(&fact,1,sizeof(facture),old);
	
        if(strcmp(fact.cin,cin))
             {
             fwrite(&fact,sizeof(facture),1,new);
             }
        else  if(strcmp(fact.cin,cin)==0)  
                {
             fread(&fact,sizeof(facture),1,new);

                }
               
	}
fclose(new);
fclose(old);
remove("facture.bin");//nfas5ou il fichier li9dim
rename("fact.bin","facture.bin");//enronomiw il fichier ejdid b esm li9dim bech ye5ou blastou
g_print("%s",fact.cin);
//return b;

/*****Na3mlo Actualiser lil liste **************/

}
