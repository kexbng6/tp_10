#include <stdbool.h>
#include "stdio.h"
#include "stdlib.h"
#include <string.h>

/*
void testFile(){
    FILE *handle = fopen(,"r");
    int var = 67;

    fprintf(handle,"%d",var);
    while (!feof(handle)){
        printf("Erreur de fichier");
        fscanf(handle,"%d",&var);
    }
    fclose(handle);
}*/

char ** creerTab(int file_size, int nbChar){
    char **tab;
    tab = (char**) malloc(file_size * sizeof(char*));
    for (int i = 0; i < file_size; ++i) {
        tab[i] = (char*) malloc(nbChar * sizeof(char));
    }
    return tab;
}

void afficherTab(char ** string, int nbString){
    for(int i=0;i<nbString;i++){
        printf("%d ",i);
        printf("%s\n",string[i]);
    }
}

void tri_bulle(char **tab, int file_size) {
    bool permut = true;
    char *temp;
    while (permut == true) {
        permut = false;
        for (int i = 0; i <file_size - 2; i++){
            if (strcmp(tab[i], tab[i + 1])>0){
                temp = (char *) malloc(sizeof(char*) * strlen(tab[i]) + 1);
                strcpy(temp, tab[i]);
                strcpy(tab[i], tab[i + 1]);
                strcpy(tab[i + 1], temp);
                permut = true;
            }
        }
    }
    free(temp);
}

void detruireTab(char ** tab, int file_size){
    for (int i = 0; i < file_size; i++)
    {
        free(tab[i]);
    }
    free(tab);
}

int main()
{
    const int TAILLE_FICH = 300;
    const int MAX_CHAR = 80;
    const char NOMFICHIER[] = "etudiants2.txt";
    FILE *fid;
    char **unStr = creerTab(TAILLE_FICH,MAX_CHAR);
    int i;
    fid = fopen(NOMFICHIER, "r"); // ouverture du fichier
    for (i=0; i<TAILLE_FICH; i++)
    {
        fscanf(fid, "%s", unStr[i]);
    }
    // fermeture du fichier
    fclose(fid);
// lit une chaîne de caract.
    tri_bulle(unStr,TAILLE_FICH);
    afficherTab(unStr,TAILLE_FICH);
    detruireTab(unStr,TAILLE_FICH);
    return 0;
}

/*
