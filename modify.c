#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void content_type();
void modifier_fichier();
void start();
void end();
void modification();
void tableau();

int main()
{
	
	content_type();
	start();
	modifier_fichier();
	tableau();
	end();
	
	
}
void content_type()
{
	printf("content-type: text/html\n\n");
}
void modifier_fichier()
{
	char *chaine;
	char *token;
	char line[256];
	chaine=getenv("QUERY_STRING");
	FILE *fichier=NULL;
	FILE *file=NULL;
	int i;
	int j;
	int z=0;
	fichier=fopen("/home/mit/fic.txt","w+");
	file=fopen("/home/mit/file.txt","r+");
	if(fichier == NULL || file == NULL)
    {
        printf("opening file ERROR \n");
    }
    else
    {
		token=strtok(chaine,"=&");
		token=strtok(NULL,"=&");
		char *name=token;
		token=strtok(NULL,"=&");
		token=strtok(NULL,"=&");
		char *first=token;
		token=strtok(NULL,"=&");
		token=strtok(NULL,"=&");
		char *genre=token;
		for(i=0 ; name[i] ;i++)
		{
			if(name[i] == '+')
			name[i]=' ';
		}
		for(j=0 ; first[j] ;j++)
		{
			if(first[j] == '+')
			first[j]=' ';
		}
		int k=0;
		while(name[k] != '\0')
		{
			name[k]=toupper(name[k]);
			k++;
		}
		if(first[0] != '\0')
		{
			first[0]=toupper(first[0]);
			
		}
		/*while(fgets(line,sizeof(line),file) != NULL)
		{
			if(strstr(line,"1")  != NULL)   
			{
				fprintf(fichier,"%s;%s;%s\n",name,first,genre);
			}
			else
			{
				fprintf(fichier,"%s",line);
						
			}
		}*/
		while(fgets(line,sizeof(line),file) != NULL)
		{
			
			if(strstr(line,name) != NULL && strstr(line,first) != NULL && strstr(line,genre) != NULL)
			{
				z=1;
			}
		}
		rewind(file);
		if(z == 1)		
		{
				printf("<div class=\"container\">\n");
				printf("<h1>Vous êtes déjà inscrit</h1>\n");
				printf("<p>Veuillez verifier la liste.</p>\n");
				printf("<DIV class=\"stick\"><img src=\"averti.png\" alt=\"Forbidden Icon\"></DIV>\n");
				printf("<a href=\"fic.html\" class=\"button\">Voir la liste d'inscription</a>\n");
				printf("</div>\n");
				while(fgets(line,sizeof(line),file) != NULL)
				{
					if(strstr(line,"1")  == NULL)
				           fprintf(fichier,"%s",line);
				}
		}
		else
		{
			while(fgets(line,sizeof(line),file) != NULL)
			{
				
					if(strstr(line,"1")  != NULL)   
					{
						fprintf(fichier,"%s;%s;%s\n",name,first,genre);
					}
					else
					{
						fprintf(fichier,"%s",line);
								
					}
			}
		
				
		}
		
		if(chaine && z != 1)
		{
			modification();
		}
		fclose(file);
		fclose(fichier);
		remove("/home/mit/file.txt");
	}
}
void tableau()
{
	FILE *fichier=NULL;
	FILE *file_txt;
	char line[256];
	char *token;
	
    fichier=fopen("fic.html","w+");                                                       //efa créer mialoha avec permission 777 
    file_txt=fopen("/home/mit/fic.txt","r");
   
    if(fichier == NULL || file_txt == NULL)
    {
        printf("opening file ERROR \n");
    }
    else
    {
		fprintf(fichier,"<HTML>\n"
				"   <HEAD>\n"
				"		<TITLE> Fichier d'inscription</TITLE>\n");
				
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
					"            <TABLE border=\"1\" bgcolor=\"white\" >\n");
				
				int id=0;
	   fprintf(fichier,"<TR>\n <TD><FONT color=#6A5ACD>NOM</FONT></TD>\n<TD><FONT color=#6A5ACD>PRENOM</FONT></TD>\n<TD><FONT color=#6A5ACD>GENRE</FONT></TD>\n</TR>");

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
				fprintf(fichier,"\n <TD><A href=\"modifier.cgi?id=%d\" >Modifier</A><TD>",id);
				fprintf(fichier,"\n <TD><A href=\"delete.cgi?id=%d\" >Supprimer</A><TD>",id);
				
		}
		fprintf(fichier," </TABLE>\n"
				" </BODY>\n"
				"</HTML>\n");
		fclose(fichier);			      
	}	
}
void modification()
{
		printf("<div class=\"container\">\n");
		printf("<h1>Modification terminée avec succés</h1>\n");
		printf("<DIV class=\"stick\"><img src=\"succes.png\" alt=\"image  Icon\"></DIV>\n");
		printf("<a href=\"fic.html\" class=\"button\">Voir la liste d'inscription</a>\n");
		printf("</div>\n");
	
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
		printf("}\n"
			   ".stick img"
			   "{"
						
						"width: 60px; "
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
