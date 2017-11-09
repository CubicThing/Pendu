#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAILLE 50
void cacher(char mot[TAILLE],char hidden[TAILLE]);
int issolved(char str1[TAILLE]);
void lowercase(char str[TAILLE]);


int main()
{
    int vies = 6;
    char Adeviner[TAILLE] = "error";
    char MotCache[TAILLE] = "";
    char Tentative = " ";
    int i = 0;
    int boolean = 0;
    int WrongLetterCOunt = 0;
    char WrongLetters[6] = "";

    printf("ENtrez le mot a deviner : ");
    gets(Adeviner);
    lowercase(Adeviner);
    cacher(Adeviner,MotCache);
    system("cls");

    do {
        printf("Entrez une lettre. Le mot a deviner est : %s . Il vous reste %i vies.\n",MotCache,vies);
        scanf("%c",&Tentative);
        fflush(stdin);

        if (strchr(WrongLetters,Tentative)) do{

            printf("La lettre que vous avez entrée est deja etablie comme fausse. Entez-en une nouvelle.\n");
            scanf("%c",&Tentative);
            fflush(stdin);

        } while (strchr(WrongLetters,Tentative));

        boolean = 0;

        //On cherche si la lettre cherchée est dans le mot
        for (i=0;i < strlen(Adeviner); i++) {
            if (Tentative == Adeviner[i]){
                MotCache[i] = Tentative;
                boolean = 1;
            }
        }


        //Si la booléenne indique que la lettre n'a pas été trouvée, on ajoute la lettre au tableau de lettre déjà essayées.
        if (boolean == 0){

                WrongLetters[WrongLetterCOunt] = Tentative;
                WrongLetterCOunt++;
                vies--;

        }

    }while ((issolved(MotCache) == 1) & (vies > 0));

    if (vies == 0) {
        printf("Vous avez ete pendu!");
    } else printf("VOus avez gagné!");

    return 0;

}

void cacher(char mot[TAILLE],char hidden[TAILLE]){
    int i = 0;
    for (i=0;i < strlen(mot); i++) hidden[i]='-';
}

int issolved(char str1[TAILLE]){
    int i = 0;
    int boolean = 0;

    for (i=0;i < strlen(str1); i++) if(str1[i] == '-') boolean = 1;

    return boolean;
}

void lowercase(char str[TAILLE]){

    int i = 0;

    for (i=0;i < strlen(str); i++) str[i]= tolower(str[i]);

}


