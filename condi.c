#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void content_type();
void start();
void end();
void primo();
void condition(char *nom);
void terminated();
void file(char *nom,char *prenom,char *genre);

int main()
{
	content_type();
	start();
	primo();
	end();

	return 0;
}
void content_type()
{
	printf("content-type: text/html\n\n");
}
void primo()
{
	char *chaine;
	char *token;
	int i;
	
	chaine=getenv("QUERY_STRING");
	token = strtok(chaine, "=&");    
	token= strtok(NULL ,"=&");  
	for(i=0 ; token[i] ; i++)
	{
		if(token[i] == '+')
		{
			token[i]= ' ';
		}
	}     
		char *nom=token;
		token= strtok(NULL,"=&");
		token= strtok(NULL,"=&");
		for(i=0 ; token[i] ; i++)
		{
			if(token[i] == '+')
			{
				token[i]= ' ';
			}
		}
			
		char *prenom = token;	
		token= strtok(NULL,"=&");
		token= strtok(NULL,"=&");
		char *genre=token;	
		
        if(genre && (nom || prenom))
        {
			file(nom,prenom,genre);
			condition(nom);
			terminated();
		}
	
}
void file(char *nom,char *prenom,char *genre)
{
	 
    FILE *fichier;

    fichier=fopen("/home/mit/fic.txt","a+"); 
 
    if(fichier == NULL)
    {
        printf("opening file ERROR \n");
    }
    else
    {
		rewind(fichier);
////Convertir le nom en majuscule
		int i=0;
		while(nom[i] != '\0')
		{
			nom[i]=toupper(nom[i]);
			i++;
		}
		
////Convertir le prenom
		if(prenom[0] != '\0')
		{
			prenom[0]=toupper(prenom[0]);
			
		}

		fprintf(fichier," %s;%s;%s\n",nom, prenom, genre);
		fclose(fichier);
	}
}	
void condition(char *nom)
{
	char last[256];
	char line[256];
	
	int nbr_ligne=0;
	int i=0;
	FILE *fichier=NULL;
    fichier=fopen("/home/mit/fic.txt","a+");
    if(fichier == NULL)
    {
        printf("opening file ERROR \n");
    }
    else
    { 
		if(nom)
		{ 
			while(fgets(line,sizeof(line),fichier) != NULL)
			{
				nbr_ligne++;
				
				strcpy(last,line);
				
			}
			rewind(fichier);
			while(fgets(line,sizeof(line),fichier) != NULL)
			{
				if(strcmp(line,last) == 0)
				{
					i++;
				}
			}
///------------------------------------------------------------------------------------------
			if(i != 1)
			{
				printf("<div class=\"container\">\n");
				printf("<h1>Vous êtes déjà inscrit</h1>\n");
				printf("<p>Nous avons déjà enregistré votre inscription.</p>\n");
				printf("<DIV class=\"stick\"><img src=\"averti.png\" alt=\"Forbidden Icon\"></DIV>\n");
				printf("<a href=\"fic.html\" class=\"button\">Voir la liste d'inscription</a>\n");
				printf("</div>\n");
			}

///--------------------------------------------------------------------------------------
			else
			{
				printf("<div class=\"container\">\n");
				printf("<h1>Inscription Réussie</h1>\n");
				printf("<p>Votre inscription a été effectuée avec succès !</p>\n");
				printf("<img src=\"succes.png\" alt=\"Success Icon\">\n");
				printf("</div>\n");
			  
			}	
///---------------------------------------------------------------------------------------

		}
		fclose(fichier);
	}
}
void terminated()
{
	
     printf("<FORM ACTION=\"remp.cgi\" METHOD=\"GET\">\n\
			   <FONT color=\"grey\"><BR></FONT>\
			  <B>Tout le monde est-il inscrit ?:<B> <SELECT class=\"select-menu\" NAME=\"rep\" >\
						<OPTION>CHOISIR</OPTION>\
						<OPTION VALUE=\"Y\">YES</OPTION>\
						<OPTION VALUE=\"N\">NO</OPTION>\
						</SELECT>\
			   <INPUT TYPE=\"SUBMIT\" VALUE=\"envoyer\" />\n\
			   </FORM>\n");
			   
}
void start()
{
		printf("<HTML> \n"
				 " <HEAD> "
				"    <TITLE> CONDITION </TITLE>"
				"        <META charset=\"UTF-8\">"
				"<STYLE>"
				 "body {\n"
		        "font-family: Arial, sans-serif;\n");
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
		printf("h1 {\n");
		printf("    color: #4CAF50;\n");
		printf("}\n");
		printf("img {\n");
		printf("    width: 100px;\n");
		printf("    height: auto;\n");
		printf("    margin-top: 20px;\n");
		printf("}");
	
		printf(".button-submit "
		"{\n"
				"background-color: rgb(0, 102, 204);\n"
				"color: rgb(255, 255, 255);\n"
				"border: none;\n"
				"padding: 10px 20px;\n"
				"text-align: center;\n"
				"text-decoration: none;\n"
				"display: inline-block;\n"
				"font-size: 16px;\n"
			    "margin: 4px 2px;\n"
				"cursor: pointer;\n"
				"border-radius: 5px;\n"
				"transition: background-color 0.3s;\n"
			"}\n"	
			".button:hover {\n"
			"    background-color: #0056b3;}\n"
			
			"	.stick img"
				"{"
						
					"width: 30px; "
					"height: auto;"
					"transition: opacity 0.3s;"
				 "}"
		 "</STYLE>"
		"</HEAD>"
		"<BODY>");
					 
}				 
void end()
{
	printf("</BODY> \n"
		   "  </HTML> \n");	   	
}		 
				 
