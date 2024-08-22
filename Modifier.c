#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void content_type();
void recuperation_id(int tok);
void start();
void end();
void clean();
void copy(char *old,char *new);
void tableau();
void affichage(int tok);
int main()
{
	int tok=0;
	char *chaine;
	char *token;
	chaine=getenv("QUERY_STRING");
	token=strtok(chaine,"=");
	token=strtok(NULL,"=");
	tok=atoi(token);
	
	
	content_type();
	start();
	recuperation_id(tok);
	affichage(tok);
	end();
	
}
void content_type()
{
	printf("content-type: text/html\n\n");
}
void recuperation_id(int tok)
{
	//char *chaine;
	//char *token;
	int i=0;
	
	FILE *fichier=NULL;
	FILE * file=NULL;
	
	char line[256];
	fichier=fopen("/home/mit/fic.txt","r+");
	file=fopen("/home/mit/file.txt","a+");
	if(file == NULL)
    {
        printf("opening file ERROR \n");
    }
    else
    {
		/*token=strtok(chaine,"=");
		token=strtok(NULL,"=");
		tok=atoi(token);*/
		while(fgets(line,sizeof(line),fichier) != NULL)
		{
			i++;
			if(i != tok)
			{
				fprintf(file,"%s",line);
				
			}
			else
			{
				
				fprintf(file,"1\n");
			}
		 }
		 fclose(file);
		 fclose(fichier);
		
	}
	
}
void affichage(int tok)
{
	
	FILE *fichier=NULL;
	char line[256];
	char *nom=NULL;
	char *prenom=NULL;
	int i=0;
	fichier=fopen("/home/mit/fic.txt","r+");
	while(fgets(line,sizeof(line),fichier) != NULL)
	{
			i++;
			if(i == tok )
			{
				
				nom=strtok(line,";");
				prenom=strtok(NULL,";");
				break;
			}
			
	}
	printf("<DIV class=\"deco\" ><FORM ACTION=\"modify.cgi\" METHOD=\"GET\">\n\
			<B>Veuillez modifier le formulaire!</B>\
			 <BR><BR>\
			  <INPUT TYPE=\"TEXT\" VALUE=\"%s\" NAME=\"name\">\
			   <BR><BR>\
			     <INPUT  TYPE=\"TEXT\" VALUE=\"%s\" NAME=\"first\">\
			      <BR> <BR>\
			      <B>GENRE:</B><BR>\
			      <SELECT class=\"input\" NAME=\"genre\" >\
						<OPTION VALUE=\"M\">MASCULIN</OPTION>\
						<OPTION VALUE=\"F\">FEMININ</OPTION>\
						</SELECT><BR>\
			   <INPUT TYPE=\"SUBMIT\" VALUE=\"Modifier\" />\n\
			   </FORM></DIV>\n",nom,prenom);
	fclose(fichier);
}	
void start()
{
		printf("<HTML>\n"
				" <HEAD> "
				"    <TITLE> FORMULAIRE</TITLE>"
				"        <META charset=\"UTF-8\">"
				"<STYLE>"
				".select-menu {"
				"    padding: 5px; "
				"    border: 1px s5olid #007bff; "
					"border-radius: 5px; "
					"background-color: #BA2BE2;"
					"cursor: pointer; "
					"}"
				".color{"
				"  background-color:#008060;}"
				".deco{"
				"color:white;"
				"border: 1px solid #008080;"
				"border-radius:6px;"
				"background-color:#008080;"
				"padding:20px;"
				"width:500px;"
				"height:360px;"
				"position:relative;"
				"top:100px;"
				"left:420px;}"
				
				".body:{"
				"justify-content:center;"
				"align-items:center;}"
				
			   "input[type=\"text\"] {"
			   " width: 470px; "
			   " padding: 10px;"
			   "  margin: 10px 0;"
			   " border: 1px solid #ccc;"
			   " border-radius: 6px;"
		       " }"
			   "input[type=\"submit\"] {"
			   "   	width: 470px; /* Largeur fixe en pixels */"
			   " 	padding: 10px;"
			   "  	border: none;"
			   " 	border-radius: 4px;"
			   " 	background-color: #28a745;"
			   "	color: #fff;"
			   "font-size: 16px;"
			   " cursor: pointer;"
			   " text-align: center;"
			"   }"
        "input[type=\"submit\"]:hover {"
         "   background-color: #218838;"
       " }"
       " select {"
           " width: 470px; "
           " padding: 10px;"
           "margin: 10px 0;"
           " border: 1px solid #ccc;"
            "border-radius: 4px;"
      "  }"
				"</STYLE>"                           
					"</HEAD>"
					  "<BODY>");		
}
void end()
{
	printf("</BODY> \n"
		   "  </HTML> \n");
		   	
}
