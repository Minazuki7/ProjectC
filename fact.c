#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fact.h"
#include <gtk/gtk.h>
enum
{
   CIN,
   NOM,
   DATE,
   TYPE_RESERVATOIN,
   COLUMNS
};
void afficher_fact(GtkWidget *liste)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
  char cin[20];
  char nom[20];
  char date[20];
  char type_reservation[20];
  store=NULL;

  FILE *f1;
  FILE *f2;

  store=gtk_tree_view_get_model(liste);
  if (store==NULL)
  { renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(" cin", renderer, "text",CIN, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
    
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",NOM, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(" date", renderer, "text",DATE, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(" type_reservation", renderer, "text",TYPE_RESERVATION, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    
   store = gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

   f1 = fopen("client.txt", "r");
   f2 = fopen("reservation.txt", "r");
   if((f1==NULL)&&(f2==NULL))
   {
     return;
   }
   else

   { f1 = fopen("voitures.txt", "a+");
     f2 = fopen("reservation.txt", "a+");
             while((fscanf(f1,"%s %s \n",cin,nom)!=EOF)&&(fscanf(f2,"%s %s \n",date,type_reservation))
       {
    gtk_list_store_append (store, &iter);
    gtk_list_store_set (store, &iter,CIN, cin,NOM, nom, DATE, date,TYPE_RESERVATION, type_reservation, -1);
        }
        fclose(f1);
        fclose(f2);
    gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
    g_object_unref (store);
   }
}
}
