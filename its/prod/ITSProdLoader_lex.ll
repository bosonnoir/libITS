/****************************************************************************/
/*								            */
/* This file is part of the PNDDD, Petri Net Data Decision Diagram  package.*/
/*     						                            */
/*     Copyright (C) 2004 Denis Poitrenaud and Yann Thierry-Mieg            */
/*     						                            */
/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or    */
/*     (at your option) any later version.                                  */
/*     This program is distributed in the hope that it will be useful,      */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of       */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        */
/*     GNU General Public License for more details.                         */
/*     						                            */
/*     You should have received a copy of the GNU General Public License    */
/*     along with this program; if not, write to the Free Software          */
/*Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA */
/*     						                            */
/****************************************************************************/
 


%{
/************* INCLUDES AND EXTERNALS *************************************/

#include <string>
#include "its/prod/ITSProdLoader_yacc.h"

%}
%option noyywrap
%option yylineno
%option prefix="ITSProd"
%%
"("			{ return('('); }
")"			{ return(')'); }
"{"			{ return('{'); }
"}"			{ return('}'); }
":"			{ return(':'); }
";"			{ return(';'); }
"<."[ ]*".>"		{ return(TOKEN);}
"<."			{ return('['); }
".>"			{ return(']'); }
"<"			{ return(UGLYPREFIX_INHIBITOR); }
"#trans"		{ return(TRANS);}
"#place"		{ return(PLACE);}
"#endtr"		{ return(ENDTR);}
"reset"		{ return(UGLYPREFIX_RESET);}
mk/[ ]*"("		{ return(MK);}
cp/[ ]*"("		{ return(CP);}
^in			{ return(UGLYPREFIX_IN);}
^out			{ return(UGLYPREFIX_OUT);}
[0-9]+		{ sscanf(yytext,"%d",&RdPMlval.i); return(ENTIER);}
[a-zA-Z_][a-zA-Z0-9_]*	{ RdPMlval.s=strdup(yytext); return(VARIABLE);}
[ \t\n\r]			{}
%%


