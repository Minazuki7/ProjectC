#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>

voitures v;
facture fact;
void
on_ajouter_clicked                     (GtkWidget       *Objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window2;

window1 = lookup_widget(Objet,"window6"); 
window2 = lookup_widget(Objet,"window7"); 

gtk_widget_destroy(window1);
window2=create_window7();
gtk_widget_show(window2);

}


void
on_button8_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
voitures v;
//GtkWidget *jour;
//GtkWidget *mois;
//GtkWidget *annee;
GtkWidget *date;
GtkWidget *model;
GtkWidget *serie;
GtkWidget *couleur;
GtkWidget *prix;
GtkWidget *resultat;
GtkWidget *window2;

window2 = lookup_widget(objet,"window7");

//jour = lookup_widget(objet,"jour");
//mois = lookup_widget(objet,"mois");
//annee = lookup_widget(objet,"annee");
date=lookup_widget(objet,"entry11");
model = lookup_widget(objet,"entry7");
serie  = lookup_widget(objet,"entry8");
couleur = lookup_widget(objet,"entry9");
prix = lookup_widget(objet,"entry10");
resultat = lookup_widget(objet,"labelresultat");

//v.date.jour=(int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
//v.date.mois=(int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
//v.date.annee=(int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(v.date,gtk_entry_get_text(GTK_ENTRY(date)));
strcpy(v.model,gtk_entry_get_text(GTK_ENTRY(model)));
strcpy(v.serie,gtk_entry_get_text(GTK_ENTRY(serie)));
strcpy(v.couleur,gtk_entry_get_text(GTK_ENTRY(couleur)));
strcpy(v.prix,gtk_entry_get_text(GTK_ENTRY(prix)));

ajouter_voitures(&v);
gtk_label_set_text(GTK_LABEL(resultat),"Ajouté avec succès");

}




void
on_button9_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{voitures v;
GtkWidget *window2;
GtkWidget *window1;
GtkWidget *treeview1;

window2=lookup_widget(objet,"window7");


window1=lookup_widget(objet,"window6");

window1=create_window6();
gtk_widget_destroy(window2);

gtk_widget_show(window1);

treeview1=lookup_widget(window1,"treeview1");

afficher_voitures(treeview1,v);
}


void
on_Gerer_les_factures_clicked          (GtkWidget      *obj,
                                        gpointer         user_data)
{
      GtkWidget *win;
GtkWidget *treeview2;
//GtkWidget *window2 ;

win = lookup_widget(obj,"window2"); 
 

//gtk_widget_destroy(window10);
win=create_window2();
gtk_widget_show(win);
treeview2=lookup_widget(win,"treeview2");

afficher_facture(treeview2,fact);

}





void
on_Valider_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
//GtkWidget *wind2;
//GtkWidget *wind1;
//GtkWidget *lab;
//char ch[10]="saif";

//wind2=lookup_widget(objet,"window8");


//wind1=lookup_widget(objet,"window4");
//lab= lookup_widget(objet,"label30");

//wind1=create_window4();
//gtk_widget_destroy(wind2);

//gtk_widget_show(wind1);
//gtk_label_set_text(GTK_LABEL(lab),"saif");

}


void
on_Valider2_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{

}


void
on_valid_clicked                       (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *windo2;
GtkWidget *windo1;

windo2=lookup_widget(obj,"window4");


windo1=lookup_widget(obj,"window5");

windo1=create_window5();
gtk_widget_destroy(windo2);

gtk_widget_show(windo1);
}


void
on_Supprimer_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
dell_user(v.serie);
GtkWidget *window6=lookup_widget(GTK_WIDGET(button),"window6");
GtkWidget *treeview1;
window6 = create_window6();
treeview1=lookup_widget(window6,"treeview1");
afficher_voitures(treeview1,v);
 
gtk_widget_show(treeview1);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *str_data0;
gchar *str_data1;
gchar *str_data2;
gchar *str_data3;
gchar *str_data4;
GtkListStore *list_store;
list_store=gtk_tree_view_get_model(treeview);
GtkTreeIter iter;
  if (gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store), &iter , path))
{
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 0, &str_data0, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 1, &str_data1, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 2, &str_data2, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 3, &str_data3, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 4, &str_data4, -1);
}
strcpy(v.date,str_data0);
strcpy(v.model,str_data1);
strcpy(v.serie,str_data2);
strcpy(v.couleur,str_data3);
strcpy(v.prix,str_data4);

}




void
on_Voit_clicked                        (GtkWidget       *button,
                                        gpointer         user_data)
{
voitures v;
GtkWidget *window6 ;
GtkWidget *treeview1;

window6 = lookup_widget(button, "window6");
window6 = create_window6();
gtk_widget_show(window6);


treeview1=lookup_widget(window6,"treeview1");
afficher_voitures(treeview1,v);

}


void
on_recherche_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *win , *inp1,*inp2,*inp3,*inp4,*inp5,*inp6;
   facture *f;
   GtkWidget *inp ;
   win =lookup_widget(GTK_ENTRY(button),"window5");
win = create_window5();
   inp = lookup_widget(GTK_ENTRY(button),"entry2CIN");
   inp1 = lookup_widget(GTK_ENTRY(button),"nom");
inp2 = lookup_widget(GTK_ENTRY(button),"prenom");
 inp3 = lookup_widget(GTK_ENTRY(button),"cin");
   inp4 = lookup_widget(GTK_ENTRY(button),"tel");
inp5 = lookup_widget(GTK_ENTRY(button),"datealler");
 inp6 = lookup_widget(GTK_ENTRY(button),"dateretour");
char temp[50];
  strcpy(temp,gtk_entry_get_text(GTK_ENTRY(inp)));
f=searching(temp);
   if(f!=NULL)
   {


        gtk_label_set_text(GTK_LABEL(inp1),f->nom);
         gtk_label_set_text(GTK_LABEL(inp2),f->prenom);
    gtk_label_set_text(GTK_LABEL(inp3),f->cin);
 gtk_label_set_text(GTK_LABEL(inp4),f->tel);
 gtk_label_set_text(GTK_LABEL(inp5),f->datealler);
 gtk_label_set_text(GTK_LABEL(inp6),f->dateroutour);
      

    

     
   }
else
  {
             gtk_label_set_text(GTK_LABEL(inp1),"");
       gtk_label_set_text(GTK_LABEL(inp2),"");
gtk_label_set_text(GTK_LABEL(inp3),"");
gtk_label_set_text(GTK_LABEL(inp4),"");
gtk_label_set_text(GTK_LABEL(inp5),"");
gtk_label_set_text(GTK_LABEL(inp6),"");
      

  }

   gtk_widget_show(win);

   

/*
search((char *)fact.cin);
GtkWidget *window2=lookup_widget(GTK_WIDGET(button),"window2");
GtkWidget *treeview2;

treeview2=lookup_widget(window2,"treeview2");
afficher_facture(treeview2,fact);
gtk_widget_show(treeview2);*/
}

char cinb[120];
void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *str_data0;
gchar *str_data1;
gchar *str_data2;
gchar *str_data3;
//gchar *str_data4;
gchar *str_data5;
gchar *str_data6;
GtkListStore *list_store;
list_store=gtk_tree_view_get_model(treeview);
GtkTreeIter iter;
  if (gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store), &iter , path))
{
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 0, &str_data0, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 1, &str_data1, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 2, &str_data2, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 3, &str_data3, -1);
//gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 4, &str_data4, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 4, &str_data5, -1);
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 5, &str_data6, -1);
}
strcpy(fact.cin,str_data0);
strcpy(fact.nom,str_data1);
strcpy(fact.prenom,str_data2);
strcpy(fact.tel,str_data3);
strcpy(fact.datealler,str_data5);
//strcpy(fact.typereservation,str_data4);
strcpy(fact.dateroutour,str_data6);
}






void
on_valider_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{/*

GtkWidget *lab;
//char ch[10]="saif";




gtk_label_set_text(GTK_LABEL(lab),"saif");*/
}


void
on_modif_clicked                       (GtkWidget       *button,
                                        gpointer         user_data)
{
//GtkWidget *date,*model,*serie,*couleur,*prix,*entry11;
mod_user((char *)v.serie);
/*****Na3mlo Actualiser lil liste **************/
GtkWidget *window6=lookup_widget(button,"window6");
GtkWidget *window7=lookup_widget(button,"window7");
gtk_widget_destroy(window6);
window7=create_window7();
gtk_widget_show(window7);

GtkWidget *entry11=lookup_widget(window7,"entry11");
gtk_entry_set_text(GTK_LABEL(entry11),v.date);

GtkWidget *entry7=lookup_widget(window7,"entry7");
gtk_entry_set_text(GTK_LABEL(entry7),v.model);

GtkWidget *entry8=lookup_widget(window7,"entry8");
gtk_entry_set_text(GTK_LABEL(entry8),v.serie);

GtkWidget *entry9=lookup_widget(window7,"entry9");
gtk_entry_set_text(GTK_LABEL(entry9),v.couleur);

GtkWidget *entry10=lookup_widget(window7,"entry10");
gtk_entry_set_text(GTK_LABEL(entry10),v.prix);

//gtk_widget_show(cin);
}


void
on_add_fact_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
facture fact;
/*GtkWidget *jaller;
GtkWidget *maller;
GtkWidget *aaller;
GtkWidget *jrout;
GtkWidget *mrout;
GtkWidget *arout;
GtkWidget *date;*/
GtkWidget *cin;
GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *tel;
//GtkWidget *typereservation;
GtkWidget *window2;
//GtkWidget *comboboxentry1;
GtkWidget *datealler;
GtkWidget *dateroutour;
window2 = lookup_widget(objet,"window8");

//jaller = lookup_widget(objet,"jaller");
//maller = lookup_widget(objet,"maller");
//aaller = lookup_widget(objet,"aaller");
datealler=lookup_widget(objet,"datealler");
dateroutour=lookup_widget(objet,"dateroutour");
cin = lookup_widget(objet,"cin");
nom  = lookup_widget(objet,"nom");
prenom = lookup_widget(objet,"prenom");
tel = lookup_widget(objet,"tel");
//typereservation = lookup_widget(objet,"comboboxentry1");
//jrout = lookup_widget(objet,"jrout");
//mrout = lookup_widget(objet,"mrout");
//arout = lookup_widget(objet,"arout");
//resultat = lookup_widget(objet,"labelresultat");

//fact.date.jaller=(int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jaller));
//fact.date.maller=(int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(maller));
//fact.date.aaller=(int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(aaller));
//fact.date.jrout=(int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jrout));
//fact.date.mrout=(int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mrout));
//fact.date.arout=(int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(arout));
strcpy(fact.datealler,gtk_entry_get_text(GTK_ENTRY(datealler)));
strcpy(fact.dateroutour,gtk_entry_get_text(GTK_ENTRY(dateroutour)));
strcpy(fact.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(fact.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(fact.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(fact.tel,gtk_entry_get_text(GTK_ENTRY(tel)));
//strcpy(fact.typereservation,gtk_entry_get_text(GTK_ENTRY(comboboxentry1)));


ajouter_facture(&fact);
//gtk_label_set_text(GTK_LABEL(resultat),"Ajouté avec succès");

}


void
on_ajout_fact_clicked                  (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *windo22;
GtkWidget *windo11;
windo22=lookup_widget(obj,"window2");
windo11=lookup_widget(obj,"window8");

windo11=create_window8();
gtk_widget_destroy(windo22);

gtk_widget_show(windo11);
}






void
on_button10_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{facture fact;
GtkWidget *wind2;
GtkWidget *wind1;
GtkWidget *treeview2;

wind2=lookup_widget(objet,"window8");


wind1=lookup_widget(objet,"window2");

wind1=create_window2();
gtk_widget_destroy(wind2);

gtk_widget_show(wind1);

treeview2=lookup_widget(wind1,"treeview2");

afficher_facture(treeview2,fact);
}

void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
mod_fact((char *)fact.cin);
GtkWidget *window2=lookup_widget(GTK_WIDGET(button),"window2");
GtkWidget *treeview2;
window2 = create_window2();
treeview2=lookup_widget(window2,"treeview2");
afficher_facture(treeview2,fact);
 
gtk_widget_show(treeview2);
}


void
on_mod_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
dell_fact((char *)fact.cin);
/*****Na3mlo Actualiser lil liste **************/
GtkWidget *window2=lookup_widget(button,"window2");
GtkWidget *window8=lookup_widget(button,"window8");
gtk_widget_destroy(window2);
window8=create_window8();
gtk_widget_show(window8);

GtkWidget *cin=lookup_widget(window8,"cin");
gtk_entry_set_text(GTK_LABEL(cin),fact.cin);

GtkWidget *nom=lookup_widget(window8,"nom");
gtk_entry_set_text(GTK_LABEL(nom),fact.nom);

GtkWidget *prenom=lookup_widget(window8,"prenom");
gtk_entry_set_text(GTK_LABEL(prenom),fact.prenom);

GtkWidget *tel=lookup_widget(window8,"tel");
gtk_entry_set_text(GTK_LABEL(tel),fact.tel);

//GtkWidget *typereservation=lookup_widget(window8,"typereservation");
//gtk_entry_set_text(GTK_LABEL(tel),fact.typereservation);

GtkWidget *datealler=lookup_widget(window8,"datealler");
gtk_entry_set_text(GTK_LABEL(datealler),fact.datealler);

GtkWidget *dateroutour=lookup_widget(window8,"dateroutour");
gtk_entry_set_text(GTK_LABEL(dateroutour),fact.dateroutour);

}

