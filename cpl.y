%code{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #define STRLEN_FOR_CPL_1VAR 7
  #define STRLEN_FOR_CPL_2VAR 8
  #define STRLEN_FOR_CPL_3VAR 9
  #define STRLEN_FOR_LABELS 2
  #define GET_FILE_NAME_LENGTH(filename) strlen(filename) + 5
  extern int yylex (void);
  void yyerror (const char *s);

  /*define structs and enums*/

  typedef struct LinkedList {
    char *cplCommand; 
    struct LinkedList* next;
  }* node;

  typedef struct LinkedListForSymbole{
    enum typeForNumbers type;
    char * id;
    struct LinkedListForSymbole *next;
  }* symboleTable;

  /*end define struct and enums*/

  /*function signature*/
  void wirteCPLtoFile(FILE *targerFile);
  int digitsInNum(int num);
  int isFloat(char * number);
  node createNode();
  symboleTable createSymboleTableNode();
  expressionAttribute creatNewExpression();
  booleanAttribute creatNewBool();
  void updateType(symboleTable startPoint, enum typeForNumbers idType);
  symboleTable searchInTable(char * id);
  void printSymboleTable();
  char * getExpType(expressionAttribute expr);
  void moveLast();
  void moveEndTable();
  label newLabel();
  void addLabel(label L);
  tempResult newTemp();
  char * tempForCasting(char *id);
  char * tempToString(tempResult tr);
  /*end function signature*/

  /*start cpl function signature*/
  void addJUMP(label L);
  void addRPRT(char * id);
  void addIPRT(char * id);
  void addRINP(char * id);
  void addIINP(char * id);
  void addJMPZ(label L, tempResult r1);
  void addRTOI(tempResult rt, char *id);
  void addITOR(tempResult rt, char *id);
  void addRASN(char * id ,char * var);
  void addIASN(char * id ,char * var);
  void addRADD(tempResult rt, char * var1, char *var2);
  void addIADD(tempResult rt, char * var1, char *var2);
  void addRSUB(tempResult rt, char * var1, char *var2);
  void addISUB(tempResult rt, char * var1, char *var2);
  void addRMLT(tempResult rt, char * var1, char *var2);
  void addRDIV(tempResult rt, char * var1, char *var2);
  void addIMLT(tempResult rt, char * var1, char *var2);
  void addIDIV(tempResult rt, char * var1, char *var2);
  void addREQL(tempResult rt, char * var1, char *var2);
  void addIEQL(tempResult rt, char * var1, char *var2);
  void addRNQL(tempResult rt, char * var1, char *var2);
  void addINQL(tempResult rt, char * var1, char *var2);
  void addRLSS(tempResult rt, char * var1, char *var2);
  void addILSS(tempResult rt, char * var1, char *var2);
  void addRGRT(tempResult rt, char * var1, char *var2);
  void addIGRT(tempResult rt, char * var1, char *var2);
  /*end cpl function signature*/

  /*global variable*/
  node head;
  node last;
  symboleTable startTable;
  symboleTable currentSymbole;
  symboleTable endTable;
  int errorCheck = 0;
  int label_counter = 0;
  int temp_result_counter = 0;
  /*end global variable*/
}

%code requires{
    enum typeForNumbers {INTTYPE, FLOATTYPE};
    enum operator{PLUS, MINUS, MUL, DIV};
    enum comparisonOperator{EQUAL, NOTEQUAL, SMALL, BIG, SEQUAL, BEQUAL};

    typedef struct labels {
    int number;
    char l;
    }* label;

    typedef struct tempResults{
      int number;
      char * name;
    }*tempResult;

    /*אני צריך להוסיף מבנה לכל משתנה גזירה */
    typedef struct structForBoolean{
      label conditionLabel;
      tempResult result;
    }*booleanAttribute;

    typedef struct structForExpression{
      char *variable;
      enum typeForNumbers type;
      tempResult result;
    }*expressionAttribute;
}

%union {
    booleanAttribute boolAtt; 
    expressionAttribute expAtt;
    tempResult result;
    char *variable;
    label lval;
    enum typeForNumbers tval;
    enum operator modifierOpp;
    enum comparisonOperator compraisonOpp;

}

%token CASE
%token DEFAULT
%token ELSE
%token <tval> FLOAT
%token IF
%token INPUT
%token <tva> INT 
%token OUTPUT
%token WHILE
%token <compraisonOpp>RELOP
%token <modifierOpp>ADDOP
%token <modifierOpp> MULOP
%token OR
%token AND
%token NOT
%token <tval> CAST
%token <variable> ID
%token <variable> NUM
%nterm <lval> create_label
%nterm <boolAtt>  boolexpr boolterm boolfactor
%nterm <expAtt> factor term expression
%nterm <tval> type
/*%define parse.error verbose*/

%%
program         :   declarations stmt_block 
                    { last -> cplCommand = (char *) malloc(sizeof(char)*strlen("\tHALT\n\0"));
                      strcpy(last -> cplCommand,"\tHALT\n");}
                ;

declarations    :   declarations declaration
                |   /*empty*/
                ;

declaration     :   {currentSymbole = endTable;}
                    idlist ':' type ';'
                    {updateType(currentSymbole, $4);}
                ;

type            :   INT {enum typeForNumbers i = INTTYPE; $$ = i;}
                |   FLOAT {enum typeForNumbers f = FLOATTYPE; $$ = f;}
                ;

idlist          :   idlist ',' ID 
                    { if(searchInTable($3)!=NULL) yyerror("cant use same id twice");
                      endTable -> id = $3; 
                      moveEndTable();}
                |   ID 
                    { if(searchInTable($1)!=NULL) yyerror("cant use same id twice");
                        endTable -> id = $1;
                        moveEndTable();
                    }     
                ;

stmt            :   assignment_stmt
                |   input_stmt
                |   output_stmt
                |   if_stmt
                |   while_stmt
                |   stmt_block
                ;

assignment_stmt :   ID '=' expression ';'
                    { symboleTable temp = searchInTable($1); 
                      char * expressionVariable;
                      enum typeForNumbers type; 
                      if(temp==NULL)
                        yyerror("not valid ID");
                      else 
                        {
                          type = temp -> type;
                          if(type ==  INTTYPE && $3->type == FLOATTYPE)
                            yyerror("It is not possible to assign a float to an int");
                          else{
                            expressionVariable = getExpType($3);
                            if(type == FLOATTYPE)
                              addRASN($1,expressionVariable);
                            if(type == INTTYPE)
                              addIASN($1,expressionVariable);
                          }

                        }
                    }
                ;

input_stmt      :   INPUT '(' ID ')' ';'
                    { symboleTable temp = searchInTable($3); 
                      enum typeForNumbers type;
                      if(temp==NULL)
                        yyerror("not valid ID");
                      else{
                        type = temp -> type;
                        if(type == FLOATTYPE)
                          addRINP($3);
                        if(type == INTTYPE)
                          addIINP($3); 
                      }
                    }
                ;

output_stmt     :   OUTPUT '(' expression ')' ';'
                    { char * expressionVariable;
                      expressionVariable = getExpType($3);
                      if($3 -> type == FLOATTYPE)
                        addRPRT(expressionVariable);
                      if($3 -> type == INTTYPE)
                        addIPRT(expressionVariable);
                    }
                ;

if_stmt         :   IF create_label '(' boolexpr ')' {addJMPZ($4 -> conditionLabel, $4->result);}
                    stmt 
                     {addJUMP($2);
                      addLabel($4->conditionLabel);}
                    ELSE 
                    stmt
                     {addLabel($2);}
                ;

while_stmt      :   WHILE create_label {addLabel($2);}'(' boolexpr ')' 
                      {addJMPZ($5 -> conditionLabel, $5->result);}
                    stmt
                    { addJUMP($2);
                      addLabel($5->conditionLabel);}
                ;

stmt_block      :   '{' stmtlist '}';

stmtlist        :   stmtlist stmt
                |   /*empty*/
                ;

boolexpr        :   boolexpr OR boolterm
                    {
                      addIADD($1->result,tempToString($1->result), tempToString($3->result));
                      addIGRT($1->result,tempToString($1->result),"0");
                      $$ = $1;
                    }
                |   boolterm {$$=$1;}

boolterm        :   boolterm AND boolfactor
                    {
                      addIADD($1->result,tempToString($1->result), tempToString($3->result));
                      addIEQL($1->result,tempToString($1->result),"2");
                      $$ = $1;
                    }
                |   boolfactor{$$=$1;}
                ;

boolfactor      :   NOT '(' boolexpr ')'
                    { addIEQL($3->result,tempToString($3->result),"0");
                      $$=$3;
                    }
                |   expression RELOP expression
                    { $$=creatNewBool();
                      char *expressionVariable1, *expressionVariable2;
                      int isFlaot = 0;
                      tempResult temp = newTemp();
                      tempResult tempForComplex;
                      expressionVariable1 = getExpType($1);
                      expressionVariable2 = getExpType($3);

                      if($1->type == INTTYPE && $3 ->type == FLOATTYPE){
                        expressionVariable1 = tempForCasting(expressionVariable1);
                        isFlaot = 1;
                      }
                      if($3->type == INTTYPE && $1 -> type == FLOATTYPE){
                        expressionVariable2 = tempForCasting(expressionVariable2);
                        isFlaot = 1;
                      }
                      if($3->type == FLOATTYPE && $3->type == FLOATTYPE) isFlaot = 1;

                      if(isFlaot){
                        if($2 == EQUAL)
                          addREQL(temp,expressionVariable1,expressionVariable2);
                        if($2 ==  NOTEQUAL)
                          addRNQL(temp,expressionVariable1,expressionVariable2);
                        if($2 == SMALL)
                          addRLSS(temp,expressionVariable1,expressionVariable2); 
                        if($2 == BIG)
                          addRGRT(temp,expressionVariable1,expressionVariable2); 
                        if($2 ==  SEQUAL){
                          tempForComplex = newTemp();
                          addREQL(temp,expressionVariable1,expressionVariable2);
                          addRLSS(tempForComplex, expressionVariable1,expressionVariable2);
                          addIADD(temp,tempToString(tempForComplex), tempToString(temp));
                        }
                        if($2 == BEQUAL){
                          tempForComplex = newTemp();
                          addREQL(temp,expressionVariable1,expressionVariable2);
                          addRGRT(tempForComplex, expressionVariable1,expressionVariable2);
                          addIADD(temp,tempToString(tempForComplex), tempToString(temp));
                        }
                      }
                      else{
                        if($2 == EQUAL)
                          addIEQL(temp,expressionVariable1,expressionVariable2);
                        if($2 ==  NOTEQUAL)
                          addINQL(temp,expressionVariable1,expressionVariable2);
                        if($2 == SMALL)
                          addILSS(temp,expressionVariable1,expressionVariable2); 
                        if($2 == BIG)
                          addIGRT(temp,expressionVariable1,expressionVariable2); 
                        if($2 ==  SEQUAL){
                          addIEQL(temp,expressionVariable1,expressionVariable2);
                          addILSS(tempForComplex, expressionVariable1,expressionVariable2);
                          addIADD(temp,tempToString(tempForComplex), tempToString(temp)); 
                        }
                        if($2 == BEQUAL){
                          addIEQL(temp,expressionVariable1,expressionVariable2);
                          addIGRT(tempForComplex, expressionVariable1,expressionVariable2);
                          addIADD(temp,tempToString(tempForComplex), tempToString(temp));
                        }
                      }
                      $$->result=temp;
                    }
                ;

expression      :   expression ADDOP term
                    { char *termVariable, *expressionVariable;
                      tempResult temp = newTemp();
                      expressionVariable = getExpType($1);
                      termVariable = getExpType($3);

                      if($2==PLUS){
                        if($1->type == FLOATTYPE || $3->type == FLOATTYPE){
                          if($1->type == INTTYPE) expressionVariable = tempForCasting(expressionVariable);
                          if($3->type == INTTYPE) termVariable = tempForCasting(termVariable);
                          addRADD(temp, expressionVariable, termVariable);
                          $$->type = FLOATTYPE;
                        }
                        else{
                          addIADD(temp, expressionVariable, termVariable);
                          $$->type = INTTYPE;
                        } 
                      }

                      if($2==MINUS){
                        if($1->type == FLOATTYPE || $3->type == FLOATTYPE){
                          if($1->type == INTTYPE) expressionVariable = tempForCasting(expressionVariable);
                          if($3->type == INTTYPE) termVariable = tempForCasting(termVariable);
                          addRSUB(temp, expressionVariable, termVariable);
                          $$->type = FLOATTYPE;
                        }
                        else{
                          addISUB(temp, expressionVariable, termVariable);
                          $$->type = INTTYPE;
                        } 
                      }
                      $$ = $1;
                      $$->result = temp;
                    }
                |   term {$$=$1;}
                ;

term            :   term MULOP factor
                    { char *termVariable, *factorVariable;
                      tempResult temp = newTemp();
                      termVariable = getExpType($1);
                      factorVariable = getExpType($3);

                      if($2==MUL){
                        if($1->type == FLOATTYPE || $3->type == FLOATTYPE){
                          if($1->type == INTTYPE) termVariable = tempForCasting(termVariable);
                          if($3->type == INTTYPE) factorVariable = tempForCasting(termVariable);
                          addRMLT(temp, termVariable, factorVariable);
                          $$->type = FLOATTYPE;
                        }
                        else{
                          addIMLT(temp, termVariable, factorVariable);
                          $$->type = INTTYPE;
                        } 
                      }

                      if($2==DIV){
                        if($1->type == FLOATTYPE || $3->type == FLOATTYPE){
                          if($1->type == INTTYPE) termVariable = tempForCasting(termVariable);
                          if($3->type == INTTYPE) factorVariable = tempForCasting(factorVariable);
                          addRDIV(temp, termVariable, factorVariable);
                          $$->type = FLOATTYPE;
                        }
                        else{
                          addIDIV(temp, termVariable, factorVariable);
                          $$->type = INTTYPE;
                        } 
                      }
                      $$ = $1;
                      $$->result = temp;
                    }
                |   factor {$$ = $1;}
                ;

factor          :   '(' expression ')' {$$ = $2;}
                |   CAST '(' expression ')'
                    { extern int yylineno;
                      char *expressionVariable = getExpType($3);
                      tempResult temp = newTemp();
                      if($1 == INTTYPE){
                        if($3 -> type == INTTYPE){
                          printf("WARNING: in line: %d TRY TO CAST INT TO INT\n", yylineno);
                          addIASN(tempToString(temp),expressionVariable);
                        }
                        else
                          addITOR(temp,expressionVariable);
                      }
                      if($1 == FLOATTYPE){
                        if($3 -> type == FLOATTYPE){
                          printf("WARNING: in line:%d TRY TO CAST FLAOT TO FLAOT\n", yylineno);
                          addRASN(tempToString(temp),expressionVariable);
                        }
                        else
                          addRTOI(temp,expressionVariable);
                      }
                      $$ = $3;
                      $$ -> result = temp;
                      $$ ->type = $1; 
                    }
                |   ID  {$$ = creatNewExpression();
                        $$->variable = $1;
                        $$ -> result = NULL;
                        symboleTable temp = searchInTable($1); 
                        if(temp==NULL)
                          yyerror("not valid ID");
                        else 
                          $$->type = temp->type;}
                |   NUM {$$=creatNewExpression(); $$->type = (isFloat($1)) ? FLOATTYPE : INTTYPE; $$->variable = $1;}
                ;

create_label    :   /*empty*/ { $$ = newLabel();}
                ;
%%
int main (int argc, char **argv)
{
  extern FILE *yyin; /* defined by flex */
  FILE *qudFile;
  char *sourceFileName;
  char *fileType;
  char targetFileName[GET_FILE_NAME_LENGTH(argv[1])];
  head = createNode();
  last = head;
  startTable = createSymboleTableNode();
  endTable = startTable;
  if (argc != 2) {
     fprintf (stderr, "Usage: %s <input-file-name>\n", argv[0]);
	 return 1;
  }
  yyin = fopen (argv [1], "r");
  if (yyin == NULL) {
       fprintf (stderr, "failed to open %s\n", argv[1]);
	   return 2;
  }

  sourceFileName = strtok(argv[1],".");
  fileType = strtok(NULL,"");
  if(strcmp(fileType,"ou")){
    fprintf(stderr,"failed to open %s.%s, file name have to end with ou\n", argv[1],fileType);
    return 3;
  } 

  yyparse ();
/*print the list*/
  if(!errorCheck){
    strcpy(targetFileName,sourceFileName);
    strcpy(targetFileName+strlen(sourceFileName),".qud");
    qudFile = fopen(targetFileName,"w");
    wirteCPLtoFile(qudFile);
  }

  fprintf(qudFile,"Amit Farjun");
  fprintf(stderr,"Amit Farjun\n");
  fclose (yyin);
  return 0;
}

void wirteCPLtoFile(FILE *targerFile){
  while(head != NULL){
    fprintf(targerFile,"%s", head->cplCommand);
    head = head -> next;}
  }

node createNode(){
  node temp; 
  temp = (node)malloc(sizeof(struct LinkedList));
  temp->next = NULL;
  return temp;
}

symboleTable createSymboleTableNode(){
  symboleTable temp;
  temp = (symboleTable)malloc(sizeof(struct LinkedListForSymbole));
  temp -> id =NULL;
  temp -> next = NULL;
  return temp;
}
expressionAttribute creatNewExpression(){
  expressionAttribute temp;
  temp = (expressionAttribute)malloc(sizeof(struct structForExpression));
  temp -> variable = NULL;
  temp -> result = NULL;
}

booleanAttribute creatNewBool(){
  booleanAttribute temp;
  temp = (booleanAttribute)malloc(sizeof(struct structForBoolean));
  temp -> conditionLabel = newLabel();
  temp -> result = NULL;
}

void updateType(symboleTable startPoint, enum typeForNumbers idType){
  symboleTable temp = startPoint;
  while(temp != endTable){
    temp -> type = idType;
    temp = temp-> next;
  }
}

symboleTable searchInTable(char * id){
  symboleTable temp = startTable;
  while(temp -> id != NULL){
    if(!strcmp(id, temp -> id))
      return temp;
    else
      temp = temp -> next;
  }
  return NULL;
}

void printSymboleTable(){
  symboleTable temp = startTable;
  while(temp -> id != NULL){
    printf("%s",temp -> id );
    if(temp -> type == FLOATTYPE) printf(" float\n");
    else printf(" int\n");
    temp = temp -> next;
  }
}

char * getExpType(expressionAttribute expr){
  char * expressionVariable;
  if(expr->result == NULL)
    expressionVariable = expr->variable;
  else
    expressionVariable = tempToString(expr->result);
  return expressionVariable;
}

void moveLast(){
  last -> next = createNode();
  last = last -> next;
}

void moveEndTable(){
  endTable -> next = createSymboleTableNode();
  endTable = endTable -> next;
}

label newLabel(){
  label temp;
  temp = (label)malloc(sizeof(struct labels));
  temp -> number = ++label_counter;
  temp -> l = 'L';
  return temp;
}

tempResult newTemp(){
  tempResult temp;
  temp = (tempResult)malloc(sizeof(struct tempResults));
  temp -> number = ++temp_result_counter;
  temp -> name = "t";
  while(searchInTable(tempToString(temp))!=NULL) temp -> number = ++temp_result_counter;
  return temp;
}
char *tempForCasting(char *id){
  tempResult tr = newTemp();
  addITOR(tr, id);
  return tempToString(tr);
}

char * tempToString(tempResult tr){
  char * temp;
  temp = (char *)malloc(sizeof(char)*(digitsInNum(tr->number)+strlen(tr->name)+1));
  sprintf(temp,"%s%d",tr->name,tr->number);
  return temp;
}

int digitsInNum(int num){
  int counter = 1;
  while(num > 10){
    counter++;
    num = num / 10;
  }
  return counter;
}

int isFloat(char *number){
  char * currentNum = number;
  for(char * currentNum = number; *currentNum != '\0'; currentNum++)
    if(*currentNum == '.')
      return 1;
  return 0;
}

/*cpl command function*/
void addJUMP(label L){
  int labelDigits = digitsInNum(L->number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(labelDigits+STRLEN_FOR_CPL_1VAR+2));
  sprintf(last->cplCommand,"\tJUMP %c%d\n", L->l, L->number);
  moveLast();
}

void addRPRT(char * id){
  last -> cplCommand=(char *)malloc(sizeof(char)*(strlen(id) + STRLEN_FOR_CPL_1VAR + 1));
  sprintf(last->cplCommand,"\tRPRT %s\n",id);
  moveLast();
}

void addIPRT(char * id){
  last -> cplCommand=(char *)malloc(sizeof(char)*(strlen(id) + STRLEN_FOR_CPL_1VAR + 1));
  sprintf(last->cplCommand,"\tIPRT %s\n",id);
  moveLast();
}

void addRINP(char * id){
  last -> cplCommand=(char *)malloc(sizeof(char)*(strlen(id) + STRLEN_FOR_CPL_1VAR + 1));
  sprintf(last->cplCommand,"\tRINP %s\n",id);
  moveLast();
}

void addIINP(char * id){
  last -> cplCommand=(char *)malloc(sizeof(char)*(strlen(id) + STRLEN_FOR_CPL_1VAR + 1));
  sprintf(last->cplCommand,"\tIINP %s\n",id);
  moveLast();
}

void addJMPZ(label L, tempResult r1){
  int labelDigits = digitsInNum(L->number);
  int tempDigits = digitsInNum(r1 -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(labelDigits + tempDigits + strlen(r1->name) + STRLEN_FOR_CPL_2VAR + 2));
  sprintf(last->cplCommand,"\tJMPZ %c%d %s%d\n", L->l, L->number, r1->name, r1->number);
  moveLast();
}

void addRASN(char * id ,char * var){
  last -> cplCommand=(char *)malloc(sizeof(char)*(strlen(id)+strlen(var)+STRLEN_FOR_CPL_2VAR+1));
  sprintf(last->cplCommand,"\tRASN %s %s\n", id, var);
  moveLast();
}

void addIASN(char * id ,char * var){
  last -> cplCommand=(char *)malloc(sizeof(char)*(strlen(id)+strlen(var)+ STRLEN_FOR_CPL_2VAR +1 ));
  sprintf(last->cplCommand,"\tIASN %s %s\n", id, var);
  moveLast();
}

void addITOR(tempResult rt, char *id){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(id)+STRLEN_FOR_CPL_2VAR + 1));
  sprintf(last->cplCommand,"\tITOR %s%d %s\n", rt->name, rt->number, id);
  moveLast();
}

void addRTOI(tempResult rt, char *id){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(id)+STRLEN_FOR_CPL_2VAR + 1));
  sprintf(last->cplCommand,"\tRTOI %s%d %s\n", rt->name, rt->number, id);
  moveLast();
}

void addRADD(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tRADD %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addIADD(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tIADD %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}
void addRSUB(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tRSUB %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addISUB(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tISUB %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addRMLT(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tRMLT %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addRDIV(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tRDIV %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addIMLT(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tIMLT %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}
void addIDIV(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tIDIV %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addREQL(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tREQL %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addIEQL(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tIEQL %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addRNQL(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tRNQL %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addINQL(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tINQL %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addRLSS(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tRLSS %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addILSS(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tILSS %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addRGRT(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tRGRT %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addIGRT(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tIGRT %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addLabel(label L)
{
  int labelDigits = digitsInNum(L->number);
  last->cplCommand = (char *)malloc(sizeof(char)*(labelDigits+STRLEN_FOR_LABELS+2));
  sprintf(last->cplCommand,"%c%d:\n",L->l, L->number);
  moveLast();
}

void yyerror (const char *s)
{
  extern int yylineno;
  errorCheck = 1;
  fprintf (stderr, "error in line %d: %s\n", yylineno,s);
}