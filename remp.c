#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX_LONGUEUR_LIGNE 256

void content_type();
void contenu();
void start();
void end();
void terminated();
void tableau();
void clean();
void copy();

int main()
{

	content_type();
	start();
	contenu();
	end();
	
}
void content_type()
{
	printf("content-type: text/html\n\n");
}
void start()
{
		printf("<HTML> \n"
				"  <HEAD> "
				"    <TITLE> FORMULAIRE</TITLE>"
				"        <META charset=\"UTF-8\">"
				 "<STYLE>"
				".select-menu {"
				"   padding: 5px; "
				"   border: 1px solid #007bff; "
				"	border-radius: 5px; "
				"	background-color: #BA2BE2;"
				"	cursor: pointer;} "
				"body {\n"
				"    font-family: Arial, sans-serif;\n");
		printf("    background-color: #f4f4f4;\n");
		printf("    color: #333;\n");
		printf("    text-align: center;\n");
		printf("    margin: 0;\n");
		printf("    padding: 0;\n");
		printf("}\n");
		printf(".container {\n");
		printf("    width: 80%%;\n");
		printf("    margin: auto;\n");
		printf("    padding: 20px;\n");
		printf("    background: white;\n");
		printf("    border-radius: 8px;\n");
		printf("    box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);\n");
		printf("}\n");
		printf("</STYLE>"                   
			   "</HEAD>"
			" <BODY>");		
}
void contenu()
{
	char *chaine;
	char *token;
	chaine=getenv("QUERY_STRING");
	token = strtok(chaine, "=");      
	token= strtok(NULL ,"="); 
	 
	char *rep = token; 
	 if(chaine)
	 {
		if(strcmp(rep,"Y") == 0)
		{
				    tableau();	
				    printf("<div class=\"container\">\n");
					printf("<h1>Inscription Terminée</h1>\n");
					printf("<p>Toutes les inscriptions sont complètes. Tout le monde a été inscrit avec succès !</p>\n");
					printf("<a href=\"fic.html\" class=\"button\">Voir la liste </a>\n");
					printf("</div>\n");
		}
		else 
		{
			
			printf("<FORM ACTION=\"remplir.cgi\" METHOD=\"GET\">\n\
					<INPUT TYPE=\"SUBMIT\" VALUE=\"suivant(e)\" />\n\
			        </FORM>\n");
		}
	 }
	

}
void end()
{
	printf("</BODY> \n"
		   "  </HTML> \n");
		   	
}
void tableau()
{
	FILE *fichier=NULL;
	FILE *file_txt;
	char line[256];
	char *token;
	
    fichier=fopen("fic.html","r+");                                                       //efa créer mialoha avec permission 777 
    file_txt=fopen("/home/mit/fic.txt","r+");
   
    if(fichier == NULL || file_txt == NULL)
    {
        printf("opening file ERROR \n");
    }
    else
    {
		fprintf(fichier,"<HTML>\n"
						"        <HEAD>\n"
						"		  <TITLE> Fichier d'inscription</TITLE>\n");
		fprintf(fichier,"<STYLE>"
					"table {\n"
					"    width: 100%%;\n"
					"    border-collapse:collapse;\n"
					"}\n"
					"th, td {\n"
					"    padding: 12px;\n"
					"    border: 1px solid #ddd;\n"
					"    text-align: left;\n"
					"}\n"
					"tr:hover {\n"
					"    background-color: #ddd;\n"
					"}\n"
					"tr:active {\n"
					"    background-color: #ffeb3b; "
					"		</STYLE>"
					"		 </HEAD>"
					"	      <BODY>\n"
					"            <TABLE border=\"1\" bgcolor=\"white\" \n");
		clean();
		copy();
		fprintf(fichier,"<TR>\n <TD><FONT color=#6A5ACD>NOM</FONT></TD>\n<TD><FONT color=#6A5ACD>PRENOM</FONT></TD>\n<TD><FONT color=#6A5ACD>GENRE</FONT></TD>\n</TR>");
				int id=0;
		while(fgets(line,sizeof(line),file_txt) != NULL)
		{
			id++;
				token = strtok(line,";");    
				char *name=token;
				token= strtok(NULL ,";");       
				char *first=token;
				token= strtok(NULL,";");
				char *genre=token;	
				fprintf(fichier,"<TR>\n <TD> %s </TD>",name);
				fprintf(fichier,"\n <TD> %s </TD>",first);
				fprintf(fichier,"\n <TD> %s </TD>",genre);
				fprintf(fichier,"\n <TD><A href=\"modifier.cgi?id=%d\">Modifier</A><TD>",id);
				fprintf(fichier,"\n <TD><A href=\"delete.cgi?id=%d\" >Supprimer</A><TD>",id);
		}
		fprintf(fichier," </TABLE>\n"
				" </BODY>\n"
				"</HTML>\n");
		fclose(fichier);
				      
	}
	
}
int est_duplicate(char *ligne,char **lignes,int compte) 
{
	int i;
    for(i=0 ; i<compte ; i++) 
    {
        if (strcmp(ligne, lignes[i]) == 0) 
        {
            return 1;                                                    // La ligne est un doublon
        }
    }
    return 0;                                                           // La ligne n'est pas un doublon
}
// Fonction pour nettoyer le fichier en supprimant les doublons
void clean() 
{
    char ligne[MAX_LONGUEUR_LIGNE];
    char **lignes = malloc(sizeof(char*)*100);                                   
    int capacite=100;
    int compte=0;
	int i;
    FILE *fichier_entree = fopen("/home/mit/fic.txt", "a+");
    FILE *fichier_sortie = fopen("/home/mit/newfile.txt","a+");

    if (fichier_entree == NULL || fichier_sortie == NULL) 
    {
        printf("Opening file ERROR");
        exit(EXIT_FAILURE);
    }

    while (fgets(ligne, sizeof(ligne), fichier_entree) != NULL) 
    {
                                                                            // Enlever le caractère de nouvelle ligne s'il est présent
        ligne[strcspn(ligne, "\n")] = '\0';

        if (!est_duplicate(ligne, lignes, compte)) 
        {
                                                                           // Réallouer de la mémoire si nécessaire
            if (compte >= capacite) 
            {
                capacite *= 2;
                lignes = realloc(lignes, sizeof(char*) * capacite);
            }
                                                                         // Allouer de la mémoire pour la nouvelle ligne et la copier
            lignes[compte] = strdup(ligne);  
            fprintf(fichier_sortie,"%s\n",lignes[compte]);
            compte++;
        }
    }

// Libérer la mémoire allouée
    for (i=0; i < compte; ++i)
    {
        free(lignes[i]);
    }
    free(lignes);
    fclose(fichier_entree);
    fclose(fichier_sortie);
    
}
void copy()
{
	
	char line[256];
	FILE *fichier=NULL;
	FILE *newfile=NULL;
	fichier=fopen("/home/mit/fic.txt","w+");
	newfile=fopen("/home/mit/newfile.txt","r+");
	
	if(fichier == NULL || newfile == NULL)
    {
        printf("opening file ERROR \n");
    }
    else
    {
		while(fgets(line,sizeof(line),newfile) != NULL)
		{
			 fprintf(fichier,"%s",line);
		}
	}	
	fclose(fichier);
	fclose(newfile);
	remove("/home/mit/newfile.txt");

}

