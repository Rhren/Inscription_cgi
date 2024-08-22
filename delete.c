#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void terminated();
void content_type();
void read_file();
void start_file();
void start();
void end();
void html();
void delete();
int main()
{
	content_type();
	start();
	terminated();
	read_file();
	end();

	return 0;
}
void content_type()
{
	printf("content-type: text/html\n\n");
}
void start()
{
		printf("<HTML> \n"
				" <HEAD> "
				"    <TITLE> CONDITION </TITLE>"
				"        <META charset=\"UTF-8\">"
				" <STYLE>"
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
			   "   width: 60px; "
			   "   height: auto;"
			   "   transition: opacity 0.3s;"
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
void terminated()
{
		printf("<div class=\"container\">\n");
		printf("<h1>Votre suppression de la liste a été effectuée avec succès</h1>\n");
		printf("<DIV class=\"stick\"><img src=\"succes.png\" alt=\"image  Icon\"></DIV>\n");
		printf("<a href=\"fic.html\" class=\"button\">Voir la liste d'inscription</a>\n");
		printf("</div>\n");
}
void read_file()
{
	char *chaine;
	chaine=getenv("QUERY_STRING");
	FILE *fichier=NULL;
	FILE *file=NULL;
	FILE *fic=NULL;
	char *token;
	char i=1;
	char j=0;
	int tok;
	char line[256];
	fichier=fopen("/home/mit/fic.txt","r+");
	fic=fopen("/home/mit/fic","a+");
	file=fopen("fic.html","w+");
	if(fichier == NULL || fic == NULL || file == NULL)
    {
        printf("opening file ERROR \n");
    }
    else
    {
		token=strtok(chaine,"=");
		token=strtok(NULL,"=");
		tok=atoi(token);
		while(fgets(line,sizeof(line),fichier) != NULL)
		{
			j++;
			if(j != tok)
			fprintf(fic,"%s",line);
			
		}
		rewind(fic);
		fclose(fichier);
		fichier=fopen("/home/mit/fic.txt","w+");
		while(fgets(line,sizeof(line),fic) != NULL)
		{
			fprintf(fichier,"%s",line);
		}
		rewind(fichier);
		fprintf(file,"<HTML> \n"
				" <HEAD> "
				"    <TITLE> LISTE</TITLE>"
				"        <META charset=\"UTF-8\">");
		fprintf(file,"<STYLE>"
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
			
		fprintf(file,"<TR>\n <TD><FONT color=#6A5ACD>NOM</FONT></TD>\n<TD><FONT color=#6A5ACD>PRENOM</FONT></TD>\n<TD><FONT color=#6A5ACD>GENRE</FONT></TD>\n</TR>");

		while(fgets(line,sizeof(line),fichier) != NULL)
		{
			char *name=strtok(line,";");
			char *first=strtok(NULL,";");
			char *genre=strtok(NULL,";");
			
				fprintf(fic,"%s;%s;%s",name,first,genre);
				fprintf(file,"<TR> \n<TD>%s</TD> <TD>%s</TD> <TD>%s</TD> <TD><A href=\"modifier.cgi?id=%d\">Modifier</A></TD> <TD><A href=\"delete.cgi?id=%d\">Supprimer\n</A></TD> \n",name,first,genre,i,i);
		
			i++;
		}
		
	fprintf(file,"</TABLE></BODY></HTML>");
	fclose(fichier);
	fclose(file);
	fclose(fic);
	remove("/home/mit/fic");
	
	}
	
}
void start_file()
{
	FILE *file=NULL;
	file=fopen("fic.html","w+");
	if(file == NULL)
    {
        printf("Opening file ERROR \n");
    }
    else
    {
		fprintf(file,"<HTML>\n"
				" <HEAD> "
				"    <TITLE> LISTE</TITLE>"
				"        <META charset=\"UTF-8\">"
				"</HEAD><BODY><TABLE border=\"1\" >\n");
	}
	fclose(file);
}



