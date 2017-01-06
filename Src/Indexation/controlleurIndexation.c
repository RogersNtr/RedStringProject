#include <stdio.h>
#include "pileDescripteur.h"
#include "Fichier.h"
#include <stdlib.h>
#include <string.h>
#include "indexationTexte.h"

//Constante contenant le chemin en local. Sera remplacé par le fichier de
//configuration.
#define CHEMIN "/home/sebastien/Documents/UPSSITECH/RedStringProject"

//Méthode gérant l'indexation de toute la base.
void runIndexation(){
    //Variable pour les commandes
    char cmd_touch[150] ;
    char cmd_ls[150] ;

    //Les différentes pile
    t_PileDescripteur pile_texte;
    t_PileDescripteur pile_image;
    t_PileDescripteur pile_son;
    init_pile(&pile_texte);
    init_pile(&pile_image);
    init_pile(&pile_son);

    FILE * ptr_ficListe;
    char nomFic[100];

    //Création des fichiers base_descripteur_*
    strcpy(cmd_touch, "touch ");
    system(strcat(strcat(cmd_touch,CHEMIN),"/Data/base_descripteur_image.txt"));

    strcpy(cmd_touch,"touch ");
    system(strcat(strcat(cmd_touch,CHEMIN),"/Data/base_descripteur_texte.txt"));

    strcpy(cmd_touch,"touch ");
    system(strcat(strcat(cmd_touch,CHEMIN),"/Data/base_descripteur_son.txt"));

    //Generation des descripteur textes
    //Copie de tous les noms de textes dans le fichier all_textes. ls avec redirection
    strcpy(cmd_ls, "ls ");
    strcat(cmd_ls,CHEMIN) ;
    strcat(cmd_ls,"/Data/Textes/");
    strcat(cmd_ls," > ");
    strcat(cmd_ls,CHEMIN);
    strcat(cmd_ls,"/Data/all_textes.txt");
    system(cmd_ls); //Copie

    char alltxtPath[150];//Chemin vers le fichier all_textes
    strcpy(alltxtPath,CHEMIN);
    strcat(alltxtPath,"/Data/all_textes.txt");

    //Ouverture du fichier contenant les noms de tous les textes
    ptr_ficListe = fopen(alltxtPath, "r");
    while(!feof(ptr_ficListe)){//Tant qu'on est pas a la fin du document
        fscanf(ptr_ficListe, "%s", nomFic);//On recupère la ligne courante
        t_Fichier *temp_fichier= malloc(sizeof(t_Fichier));
        temp_fichier->chemin_nom = nomFic;//Création du fichier
        //Ajout du fichier dans la pile_texte. Voir indexationImage.h pour
        //des détails sur la méthode.
        genDescripteurTexte(*temp_fichier, &pile_texte);
    }

}

//Méthode ecrivant les déscripteur dans le fichier de la base descripteur
void ecrireDescripteur(t_PileDescripteur pileDescripteur, char * type){
    //TODO
}

//Main de test.
int main(){
    printf("HEYDEBUT\n");
    runIndexation();
}
