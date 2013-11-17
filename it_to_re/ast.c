/*
   Copyright (C) 2013 Vincenzo Lo Cicero

   Author: Vincenzo Lo Cicero.
   e-mail: vincenzo.locicero@libero.it
       
   This file is part of retoit.

   retoit is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   retoit is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with retoit.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "ast.h"

#define SIZEOF_NODETYPE ((char *)&p->u.con - (char *)p)

nodeType *con(int t1, Valore value)
{
    nodeType *p = NULL;
    size_t nodeSize;

    nodeSize = SIZEOF_NODETYPE + sizeof(conNodeType);
    if ((p = malloc(nodeSize)) == NULL)
    {
		fprintf(stderr, "Errore 'ast con': memoria insufficiente.\n");
		return NULL;
	}

    p->type = typeCon;
	p->type1 = t1;
	p->u.con.value = value;

    return p;
}

nodeType *opr(int oper, int nops, ...)
{
    va_list ap;
    nodeType *p = NULL;
    size_t nodeSize;
    int i;

    nodeSize = SIZEOF_NODETYPE + sizeof(oprNodeType) + (nops - 1) * sizeof(nodeType*);
    if ((p = malloc(nodeSize)) == NULL)
	{
		printf("Errore 'ast opr': memoria insufficiente.\n");
		return NULL;
	}

    p->type = typeOpr;
    p->u.opr.oper = oper;
    p->u.opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->u.opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
}

void freeNode(nodeType *p)
{
    int i;

    if (!p)
		return;
		
	if (p->type == typeCon)
		if ( p->type1 == AST_STRING || p->type1 == AST_HEX
			|| p->type1 == AST_UNICODE || p->type1 == AST_UNICODE_SCRIPT || p->type1 == AST_UNICODE_SCRIPT_NEG
			|| p->type1 == AST_UNICODE_BLOCK || p->type1 == AST_UNICODE_BLOCK_NEG
			)
			free(p->u.con.value.strVal);

    if (p->type == typeOpr)
	{
        for (i = 0; i < p->u.opr.nops; i++)
            freeNode(p->u.opr.op[i]);
    }

    free (p);
}


void initTranslateParams(TranslateParams *pParams)
{
	int i;
	
	pParams->bInSet = 0;
		
	for (i = 0; i < SIZE_ARRAY_GROUPS; i++)
		pParams->arrayGroups[i] = NULL;
	pParams->countGroups = 0;
	
	pParams->pHT_UnicodeBlocks = NULL;
}
