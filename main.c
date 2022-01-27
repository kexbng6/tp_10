#include "stdio.h"

void testFile(){
    FILE *handle = fopen();
    int var = 67;

    fprintf(handle,%d,var);
    while (!feof(handle)){
        printf("Erreur de fichier");
        fscanf(handle,%d,&var);
    }
    fclose(handle);
}

void creerTab(){

}

void afficherTab(){

}

int main()
{
    const int TAILLE_FICH = 300;
    const int MAX_CHAR = 80;
    const char NOMFICHIER[] = "etudiants2.txt";
    FILE *fid;
    char unStr[MAX_CHAR];
    int i;fid = fopen(NOMFICHIER, "r"); // ouverture du fichier
    for (i=0; i<TAILLE_FICH; i++)
    {
        fscanf(fid, "%s", unStr);
        ...
    }
    fclose(fid);
// lit une chaîne de caract.
// fermeture du fichier
    return 0;
}