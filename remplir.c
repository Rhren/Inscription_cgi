#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void content_type();
void start();
void end();
void remplir();
void file(char *nom,char *prenom,char *genre);
void condition(char *nom);
void tableau();
void terminated();
int main()
{
	content_type();
	start();
	remplir();
	end();
	
}	
void content_type()
{
	printf("content-type: text/html\n\n");
}
void remplir()
{
	printf("<DIV class=\"deco\" ><FORM ACTION=\"condi.cgi\" METHOD=\"GET\">\n\
			<B>Prêt pour une Nouvelle Année Scolaire ? Inscrivez-Vous !</B>\
			 <BR><BR>\
			  <INPUT TYPE=\"TEXT\" placeholder=\"Entrer votre nom\" NAME=\"name\">\
			   <BR><BR>\
			     <INPUT  TYPE=\"TEXT\" placeholder=\"Entrer votre prenom\" NAME=\"first\">\
			      <BR> <BR>\
			      <B><DIV class=\"stick\"><img src=\"genre.png\" ></DIV>GENRE:</B><BR>\
			      <SELECT class=\"input\" NAME=\"genre\" >\
						<OPTION VALUE=\"M\">MASCULIN</OPTION>\
						<OPTION VALUE=\"F\">FEMININ</OPTION>\
						</SELECT><BR>\
			   <INPUT TYPE=\"SUBMIT\" VALUE=\"S'inscrir\" />\n\
			   </FORM></DIV>\n");
			   
		
}
void start()
{
		printf("<HTML> \n"
				 " <HEAD> "
				"    <TITLE> FORMULAIRE</TITLE>"
				"        <META charset=\"UTF-8\">"
				 "<STYLE>"
				".select-menu {"
				"    padding: 5px; "
				"    border: 1px s5olid #007bff; "
				"    border-radius: 5px; "
			    "	 background-color: #BA2BE2;"
				"	 cursor: pointer; "
				"}"
				".color{"
				"  background-color:#008060;}"
				".deco{"
				"	color:white;"
				"	border: 1px solid #008080;"
				"	border-radius:6px;"
				"	background-color:#008080;"
				"	padding:20px;"
				"	width:500px;"
				"	height:360px;"
				"	position:relative;"
				"	top:100px;"
				"	left:420px;"
				"}"
				".body:{"
				"	justify-content:center;"
				"	align-items:center;"
				"}"
				"input[type=\"text\"] {"
            	"	width: 470px; "
				"	padding: 10px;"
				"   margin: 10px 0;"
				"   border: 1px solid #ccc;"
				"   border-radius: 6px;"
				"}"
			    "input[type=\"submit\"] {"
			    "	width: 470px; "
			    "	padding: 10px;"
				"   border: none;"
				"   border-radius: 4px;"
				" 	background-color: #28a745;"
				"	color: #fff;"
				"	font-size: 16px;"
				"   cursor: pointer;"
				" 	text-align: center;"
				"}"
				"input[type=\"submit\"]:hover {"
				"   background-color:#218838;"
				" }"
			    "select {"
				" 	width: 470px; "
				" 	padding: 10px;"
				"	margin: 10px 0;"
				" 	border: 1px solid #ccc;"
				"	border-radius: 4px;"
				"}"
				".stick img"
				"{"
				" 	width: 30px; "
				"	height: auto;"
				"	transition: opacity 0.3s;"
				"}"
				".stick img:hover "
				"{"
				"	opacity: 0.7; /* Effet de survol pour les icônes */"
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






