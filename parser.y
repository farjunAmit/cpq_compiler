%code{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #define STRLEN_FOR_CPL_1VAR 7
  #define STRLEN_FOR_CPL_2VAR 8
  #define STRLEN_FOR_CPL_3VAR 9
  #define STRLEN_FOR_LABELS 2
  extern int yylex (void);
  void yyerror (const char *s);

  /*define structs and enums*/

  /*new type - node: this linked list will save the code in it cpl form, each node is 1 command*/
  typedef struct LinkedList {
    char *quadCommand; 
    struct LinkedList* next;
  }* node;

  /*new type symboleTable: this LinkedList will be used as symboleTable for the variable define in the code*/
  typedef struct LinkedListForSymbole{
    enum typeForNumbers type;
    char * id;
    struct LinkedListForSymbole *next;
  }* symboleTable;

  /*end define struct and enums*/

  /*function signature*/
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
  /*globals node - head will save the first element in the cpl list and last will save the last command*/
  symboleTable startTable;
  symboleTable currentSymbole;
  symboleTable endTable;
  /*globals node - startTable will save the first element in the symboleTable list.
    last will save the last element in the symboleTable.
    currentSymbole will save the first symbole that his type has not been update */
  int errorCheck = 0;
  int label_counter = 0;
  int temp_result_counter = 0;
  /*end global variable*/
}

%code requires{
  void wirteCPLtoFile(char *targerFileName);/*this function signature is here for main to use*/

  enum typeForNumbers {INTTYPE, FLOATTYPE};/* enum to save numbers type*/
  enum operator{PLUS, MINUS, MUL, DIV};/*enums to save operator type*/
  enum comparisonOperator{EQUAL, NOTEQUAL, SMALL, BIG, SEQUAL, BEQUAL};/*enums to save comparison operator type*/

  /*new type - labels: label consist of number and the letter 'L'*/
  typedef struct labels {
    int number;
    char l;
  }* label;

  /*new type - tempResult: tempResult consist of the number of the temp and his name*/
  typedef struct tempResults{
    int number;
    char * name;
  }*tempResult;

  /*new type - booleanAttribute: this struct can save the information for boolean stmt*/
  typedef struct structForBoolean{
    label conditionLabel;
    tempResult result;
  }*booleanAttribute;

  /*new type - expressionAttribute: this struct can save the information for expression stmt*/
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
program         :   { /*Befor we start the parser phase - creat the cpl linked list and the symbole table*/
                      head = createNode();
                      last = head;
                      startTable = createSymboleTableNode();
                      endTable = startTable;}
                    declarations stmt_block 
                    { /*After the parser phase is over add the HALT commmand to the end of the cpl code*/
                      last -> quadCommand = (char *) malloc(sizeof(char)*strlen("\tHALT\n\0"));
                      strcpy(last -> quadCommand,"\tHALT\n");}
                ;

declarations    :   declarations declaration
                |   /*empty*/
                ;

declaration     :   { /*Save the location of the last element in the list for latter use*/
                      currentSymbole = endTable;}
                    idlist ':' type ';'
                    { /*After we've gone through all the elements of a certain type, update their type*/
                      updateType(currentSymbole, $4);}
                ;

type            :   INT {enum typeForNumbers i = INTTYPE; $$ = i;/*return type*/}
                |   FLOAT {enum typeForNumbers f = FLOATTYPE; $$ = f;/*return type*/}
                ;

idlist          :   idlist ',' ID 
                    { /*Check if this id already in use*/
                      if(searchInTable($3)!=NULL) yyerror("cant use same id twice");/*If it does, send error*/
                      endTable -> id = $3; /*If it doesnt, add him to the symbole table*/ 
                      moveEndTable();} /*Move the pointer to the end of the symbole table one space*/
                |   ID 
                    { /*Check if this id already in use*/
                      if(searchInTable($1)!=NULL) yyerror("cant use same id twice");/*If it does, send error*/
                      endTable -> id = $1;/*If it doesnt, add him to the symbole table*/ 
                      moveEndTable();/*Move the pointer to the end of the symbole table one space*/
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
                      char * expressionVariable;/*save the id/temp result from the exprassion*/
                      enum typeForNumbers type; /*save the type of the expression*/
                      if(temp==NULL) /*if this id doesnt defined before - send error*/
                        yyerror("not valid ID"); 
                      else /*else - start assignment*/
                        {
                          type = temp -> type;
                          if(type ==  INTTYPE && $3->type == FLOATTYPE) /*if you try to put assign float into int*/
                            yyerror("It is not possible to assign a float to an int"); /*send error*/
                          else{
                            expressionVariable = getExpType($3);/*get the right result from exprresion*/
                            if(type == FLOATTYPE){
                              if($3->type == INTTYPE)/*if id is float but exprassion is int - do cast to float*/
                                expressionVariable = tempForCasting(expressionVariable);/*create new temp for the casting action)*/
                              addRASN($1,expressionVariable); /*assign expression to id*/
                            } /*if ID is float, start float assinment*/
                            if(type == INTTYPE)
                              addIASN($1,expressionVariable); /*assign expression to id*/
                          }
                        }
                    }
                ;

input_stmt      :   INPUT '(' ID ')' ';'
                    { symboleTable temp = searchInTable($3); 
                      enum typeForNumbers type;
                      if(temp==NULL) /*if this id doesnt defined before - send error*/
                        yyerror("not valid ID");
                      else{
                        type = temp -> type;
                        if(type == FLOATTYPE) /*if id is float type use float input*/
                          addRINP($3); 
                        if(type == INTTYPE) /*if id is int type use int input*/
                          addIINP($3); 
                      }
                    }
                ;

output_stmt     :   OUTPUT '(' expression ')' ';'
                    { char * expressionVariable;
                      expressionVariable = getExpType($3); /*get exprresion type (id/num/tempResult)*/
                      if($3 -> type == FLOATTYPE) /*if id is float type use float output*/
                        addRPRT(expressionVariable);
                      if($3 -> type == INTTYPE)
                        addIPRT(expressionVariable);/*if id is float type use int output*/
                    }
                ;

if_stmt         :   IF create_label '(' boolexpr ')' {addJMPZ($4 -> conditionLabel, $4->result);}
                    stmt 
                     {addJUMP($2);
                      addLabel($4->conditionLabel);}
                    ELSE 
                    stmt
                     {addLabel($2);}
                     /*The If - Else structer: 
                       - creat_label - creat new label to latter use becouse we want to be able to print it latter
                       - print the boolean expression(happen in boolexpr)
                       - add jump - if the bool == ture keep running, else jump to the else stmt
                       - print the stmt (happen in stmt)
                       - add jump with the label we creat with "create_label" and then print the label for the else stmt
                       - print the else stmt(happen in the second stmt)
                       - print the label we creat with the "create_label" for the rest of the code.*/ 

                ;

while_stmt      :   WHILE create_label {addLabel($2);}'(' boolexpr ')' 
                      {addJMPZ($5 -> conditionLabel, $5->result);}
                    stmt
                    { addJUMP($2);
                      addLabel($5->conditionLabel);}
                    /*the While structer:
                      - creat_label - creat new label and print it, it will be the while label when we want to return to the while loop
                      - print the boolean expression(happen in boolexpr)
                      - add jump to the end using the label from the bool. this jump happne if the bool is false
                      - print the stmt(this happen in stmt)
                      - add jump to the start of the while loop using the label from "create_label" 
                      - add the label using the label from the bool, we jump to this label if bool = false.*/
                ;

stmt_block      :   '{' stmtlist '}';

stmtlist        :   stmtlist stmt
                |   /*empty*/
                ;

boolexpr        :   boolexpr OR boolterm
                    {
                      /*to execute "OR" we take the result from boolexpr and boolterm and add them together
                        if the result is bigger then 0 so at list 1 of them is true, else it false*/
                      addIADD($1->result,tempToString($1->result), tempToString($3->result));
                      addIGRT($1->result,tempToString($1->result),"0");
                      $$ = $1;
                    }
                |   boolterm {$$=$1;}

boolterm        :   boolterm AND boolfactor
                    {
                      /*to execute "AND" we take the result from boolterm and boolgactor and add them together
                      if the result is equal to 2 so both terms is true, else it false*/
                      addIADD($1->result,tempToString($1->result), tempToString($3->result));
                      addIEQL($1->result,tempToString($1->result),"2");
                      $$ = $1;
                    }
                |   boolfactor{$$=$1;}
                ;

boolfactor      :   NOT '(' boolexpr ')' 
                    { /*to execute "NOT" just compare the result to 0.
                        for example if boolexpr = 0 so the stmt (0==0) return 1, else return 0;*/
                      addIEQL($3->result,tempToString($3->result),"0");
                      $$=$3;
                    }
                |   expression RELOP expression
                    { $$=creatNewBool(); /*create new bool expresssion*/
                      char *expressionVariable1, *expressionVariable2;
                      int isFlaot = 0;
                      tempResult temp = newTemp();
                      tempResult tempForComplex;
                      expressionVariable1 = getExpType($1); /*get expression 1 type(id/number/result)*/
                      expressionVariable2 = getExpType($3); /*get expression 2 type(id/number/result)*/

                      /*if one expression is type int and the other one type float - cast the int to float
                        and set isFloat to true if even on of them is float*/
                      if($1->type == INTTYPE && $3 ->type == FLOATTYPE){
                        expressionVariable1 = tempForCasting(expressionVariable1);
                        isFlaot = 1;
                      }
                      if($3->type == INTTYPE && $1 -> type == FLOATTYPE){
                        expressionVariable2 = tempForCasting(expressionVariable2);
                        isFlaot = 1;
                      }
                      if($3->type == FLOATTYPE && $3->type == FLOATTYPE) isFlaot = 1;

                      /*add the command for floats*/
                      if(isFlaot){
                        if($2 == EQUAL) /*the == operator*/
                          addREQL(temp,expressionVariable1,expressionVariable2);
                        if($2 ==  NOTEQUAL) /*the != operator*/
                          addRNQL(temp,expressionVariable1,expressionVariable2);
                        if($2 == SMALL) /*the < operator*/
                          addRLSS(temp,expressionVariable1,expressionVariable2); 
                        if($2 == BIG) /*the > operator*/
                          addRGRT(temp,expressionVariable1,expressionVariable2);
                        if($2 ==  SEQUAL){ /*the <= operator*/
                          /*to execute <= we create a new temp the hold the add value of the 
                          small then...and equal to... if one of them is true the sum will be 1 else it will be 0*/ 
                          tempForComplex = newTemp();
                          addREQL(temp,expressionVariable1,expressionVariable2);
                          addRLSS(tempForComplex, expressionVariable1,expressionVariable2);
                          addIADD(temp,tempToString(tempForComplex), tempToString(temp));
                        }
                        if($2 == BEQUAL){/* the >= operator*/
                          /*to execute >= we create a new temp the hold the add value of the 
                          biger then...and equal to... if one of them is true the sum will be 1 else it will be 0*/ 
                          tempForComplex = newTemp();
                          addREQL(temp,expressionVariable1,expressionVariable2);
                          addRGRT(tempForComplex, expressionVariable1,expressionVariable2);
                          addIADD(temp,tempToString(tempForComplex), tempToString(temp));
                        }
                      }
                       /*add the command for int*/
                      else{
                        if($2 == EQUAL)/*the == operator*/
                          addIEQL(temp,expressionVariable1,expressionVariable2);
                        if($2 ==  NOTEQUAL)/*the != operator*/
                          addINQL(temp,expressionVariable1,expressionVariable2);
                        if($2 == SMALL)/*the < operator*/
                          addILSS(temp,expressionVariable1,expressionVariable2); 
                        if($2 == BIG)/*the > operator*/
                          addIGRT(temp,expressionVariable1,expressionVariable2); 
                        if($2 ==  SEQUAL){/*the <= operator*/
                          addIEQL(temp,expressionVariable1,expressionVariable2);
                          addILSS(tempForComplex, expressionVariable1,expressionVariable2);
                          addIADD(temp,tempToString(tempForComplex), tempToString(temp)); 
                        }
                        if($2 == BEQUAL){/* the >= operator*/
                          addIEQL(temp,expressionVariable1,expressionVariable2);
                          addIGRT(tempForComplex, expressionVariable1,expressionVariable2);
                          addIADD(temp,tempToString(tempForComplex), tempToString(temp));
                        }
                      }
                      $$->result=temp; /*return the temp that hold the reusld of the stmt*/
                    }
                ;

expression      :   expression ADDOP term
                    { char *termVariable, *expressionVariable;
                      enum typeForNumbers type = INTTYPE;
                      tempResult temp = newTemp();
                      expressionVariable = getExpType($1); /*get expression type for expression*/
                      termVariable = getExpType($3); /*get expression type for term*/

                      /*if one of them is float - check if the other one is int. if it does do casting 
                      befor continue. Anyway set type to float*/
                      if($1->type == FLOATTYPE || $3->type == FLOATTYPE){
                        if($1->type == INTTYPE) expressionVariable = tempForCasting(expressionVariable);/*get tem result after casting*/
                        if($3->type == INTTYPE) termVariable = tempForCasting(termVariable); /*get tem result after casting*/
                        type = FLOATTYPE;
                      }

                      if($2==PLUS){/*for + operator*/
                        if(type == FLOATTYPE)
                          addRADD(temp, expressionVariable, termVariable);
                        else
                          addIADD(temp, expressionVariable, termVariable);
                      } 

                      if($2==MINUS){/*for - operator*/
                        if(type == FLOATTYPE)
                          addRSUB(temp, expressionVariable, termVariable);
                        else
                          addISUB(temp, expressionVariable, termVariable);
                      }
                      $$ = $1;
                      $$->type = type;
                      $$->result = temp;
                    }
                |   term {$$=$1;}
                ;

term            :   term MULOP factor
                    { char *termVariable, *factorVariable;
                      enum typeForNumbers type = INTTYPE;
                      tempResult temp = newTemp();
                      termVariable = getExpType($1); /*get expression type for term*/
                      factorVariable = getExpType($3);/*get expression type for factor*/
                      /*if one of them is float - check if the other one is int. if it does do casting 
                      befor continue. Anyway set type to float*/
                      if($1->type == FLOATTYPE || $3->type == FLOATTYPE){
                          if($1->type == INTTYPE) termVariable = tempForCasting(termVariable);
                          if($3->type == INTTYPE) factorVariable = tempForCasting(termVariable);
                          type = FLOATTYPE;
                      }

                      if($2==MUL){/*for * operator*/
                        if(type == FLOATTYPE)
                          addRMLT(temp, termVariable, factorVariable);
                        else
                          addIMLT(temp, termVariable, factorVariable);
                      }

                      if($2==DIV){/*for / operator*/
                        if(type == FLOATTYPE)
                          addRDIV(temp, termVariable, factorVariable);
                        else
                          addIDIV(temp, termVariable, factorVariable);
                      }
                      $$ = $1;
                      $$ -> type = type; /*term get the final type of the stmt*/
                      $$->result = temp; /*term get the temp that hold the result*/
                    }
                |   factor {$$ = $1;}
                ;

factor          :   '(' expression ')' {$$ = $2;}
                |   CAST '(' expression ')'
                    { extern int yylineno;
                      char *expressionVariable = getExpType($3); /*get expression type for expression*/
                      tempResult temp = newTemp();

                      if($1 == INTTYPE){
                        /*safe check - check if you try to cast variable to the same type - if you do
                        send warning but keep the program running*/
                        if($3 -> type == INTTYPE){
                          printf("WARNING: in line: %d TRY TO CAST INT TO INT\n", yylineno);
                          addIASN(tempToString(temp),expressionVariable);/*if they same type, just do assignment*/
                        }
                        else
                          addRTOI(temp,expressionVariable); /*if they not the same type do casting*/
                      }
                      if($1 == FLOATTYPE){
                        /*safe check - check if you try to cast variable to the same type - if you do
                        send warning but keep the program running*/
                        if($3 -> type == FLOATTYPE){
                          printf("WARNING: in line:%d TRY TO CAST FLAOT TO FLAOT\n", yylineno);
                          addRASN(tempToString(temp),expressionVariable);/*if they same type, just do assignment*/
                        }
                        else
                          addITOR(temp,expressionVariable); /*if they not the same type do casting*/
                      }
                      $$ = $3;
                      $$ -> result = temp;
                      $$ ->type = $1; 
                    }
                |   ID  {$$ = creatNewExpression();
                        $$->variable = $1;/*get the id*/
                        symboleTable temp = searchInTable($1); 
                        if(temp==NULL)/*if this id doesnt define befor - send error*/
                          yyerror("not valid ID");
                        else /*else, get the id type*/
                          $$->type = temp->type;}
                |   NUM {$$=creatNewExpression(); 
                    $$->type = (isFloat($1)) ? FLOATTYPE : INTTYPE; /*get the number type*/
                    $$->variable = $1;}
                ;

create_label    :   /*empty*/ { $$ = newLabel(); /*creat new label*/}
                ;
%%
/*this targer get name of file and create new file with the same name.
then this funcation wirte the file all the quad code that the gloabal variable "head" hold*/
void wirteCPLtoFile(char *targetFileName){
  FILE *qudFile;
  if(!errorCheck){/*if there is no error in the cpl code start printing to file*/
    qudFile = fopen(targetFileName,"w"); 
    while(head != NULL){/*as long as there is more command to print keep printing*/
      fprintf(qudFile,"%s", head->quadCommand);
      head = head -> next;}
    fprintf(qudFile,"Amit Farjun");
  }
  fprintf(stderr,"Amit Farjun\n");
}

/*constructive function - return new node object*/
node createNode(){
  node temp; 
  temp = (node)malloc(sizeof(struct LinkedList));
  temp->next = NULL;
  return temp;
}

/*constructive function - return new symbole table object*/
symboleTable createSymboleTableNode(){
  symboleTable temp;
  temp = (symboleTable)malloc(sizeof(struct LinkedListForSymbole));
  temp -> id =NULL;
  temp -> next = NULL;
  return temp;
}

/*constructive function - return new expression object*/
expressionAttribute creatNewExpression(){
  expressionAttribute temp;
  temp = (expressionAttribute)malloc(sizeof(struct structForExpression));
  temp -> variable = NULL;
  temp -> result = NULL;
}

/*constructive function - return new booleand object*/
booleanAttribute creatNewBool(){
  booleanAttribute temp;
  temp = (booleanAttribute)malloc(sizeof(struct structForBoolean));
  temp -> conditionLabel = newLabel();
  temp -> result = NULL;
}

/*this function get a start point on a symbole table and a type. the function
update all the symboles from the start point till the end with the givin type*/
void updateType(symboleTable startPoint, enum typeForNumbers idType){
  symboleTable temp = startPoint;
  while(temp != endTable){
    temp -> type = idType;
    temp = temp-> next;
  }
}

/*this fucntion get an id and return pointer to the node that hold that id. if this id doesnt exist 
it return NULL*/
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

/*this function the symbole table is the form: id: tpye\n*/
void printSymboleTable(){
  symboleTable temp = startTable;
  while(temp -> id != NULL){
    printf("%s:",temp -> id );
    if(temp -> type == FLOATTYPE) printf(" float\n");
    else printf(" int\n");
    temp = temp -> next;
  }
}

/*this function return a string that hold the value of the expression.
the this exprassion hold id/number it return this. if this expression hold temp result it 
first cast the temp resutl to string and then return it*/
char * getExpType(expressionAttribute expr){
  char * expressionVariable;
  if(expr->result == NULL)
    expressionVariable = expr->variable;
  else
    expressionVariable = tempToString(expr->result);
  return expressionVariable;
}

/*this function create new node and move the global vavariable "last" to this node*/
void moveLast(){
  last -> next = createNode();
  last = last -> next;
}

/*this function create new node and move the global vavariable "endTable" to this node*/
void moveEndTable(){
  endTable -> next = createSymboleTableNode();
  endTable = endTable -> next;
}

/*constructive function - return new label object*/
label newLabel(){
  label temp;
  temp = (label)malloc(sizeof(struct labels));
  temp -> number = ++label_counter; /*each label has a number, this make sure there are no 2 labels with the same number*/
  temp -> l = 'L';
  return temp;
}

/*constructive function - return new temp object*/
tempResult newTemp(){
  tempResult temp;
  temp = (tempResult)malloc(sizeof(struct tempResults));
  temp -> number = ++temp_result_counter; /*each temp has a number, this make sure there are no 2 temps with the same number*/
  temp -> name = "t";
  while(searchInTable(tempToString(temp))!=NULL) temp -> number = ++temp_result_counter;
  return temp;
}

/*this function get pointer to string and return new pointer with new temp result 
the new temp result hold the value of the orignal string after casting to INT value
this function should be use only for inner casting and not cpl casting*/
char *tempForCasting(char *id){
  tempResult tr = newTemp();
  addITOR(tr, id);
  return tempToString(tr);
}

/*this function get a temp result and return a sting that hold the same temp*/
char * tempToString(tempResult tr){
  char * temp;
  temp = (char *)malloc(sizeof(char)*(digitsInNum(tr->number)+strlen(tr->name)+1));
  sprintf(temp,"%s%d",tr->name,tr->number);
  return temp;
}

/*this function get a number and return the number of digits this number has*/
int digitsInNum(int num){
  int counter = 1;
  while(num > 10){
    counter++;
    num = num / 10;
  }
  return counter;
}

/*this function get a string that represent a number and reurn 1 if this number is float type
else return 0*/
int isFloat(char *number){
  char * currentNum = number;
  for(char * currentNum = number; *currentNum != '\0'; currentNum++)
    if(*currentNum == '.')
      return 1;
  return 0;
}

/*cpl command function - all this function add a quad command to the list. */
/*add jump command to the list - get label as an argument*/
void addJUMP(label L){
  int labelDigits = digitsInNum(L->number);
  last -> quadCommand=(char *)malloc(sizeof(char)*(labelDigits+STRLEN_FOR_CPL_1VAR+2));
  sprintf(last->quadCommand,"\tJUMP %c%d\n", L->l, L->number);
  moveLast();
}
/*add RPTR/IPRT to the list, get char * as an argument*/
void addRPRT(char * id){
  last -> quadCommand=(char *)malloc(sizeof(char)*(strlen(id) + STRLEN_FOR_CPL_1VAR + 1));
  sprintf(last->quadCommand,"\tRPRT %s\n",id);
  moveLast();
}
void addIPRT(char * id){
  last -> quadCommand=(char *)malloc(sizeof(char)*(strlen(id) + STRLEN_FOR_CPL_1VAR + 1));
  sprintf(last->quadCommand,"\tIPRT %s\n",id);
  moveLast();
}
/*add RINP/IINP to the list, get char * as an argument*/
void addRINP(char * id){
  last -> quadCommand=(char *)malloc(sizeof(char)*(strlen(id) + STRLEN_FOR_CPL_1VAR + 1));
  sprintf(last->quadCommand,"\tRINP %s\n",id);
  moveLast();
}
void addIINP(char * id){
  last -> quadCommand=(char *)malloc(sizeof(char)*(strlen(id) + STRLEN_FOR_CPL_1VAR + 1));
  sprintf(last->quadCommand,"\tIINP %s\n",id);
  moveLast();
}

/*add JMPZ to the list, get label and tempResilt as an arguments*/
void addJMPZ(label L, tempResult r1){
  int labelDigits = digitsInNum(L->number);
  int tempDigits = digitsInNum(r1 -> number);
  last -> quadCommand=(char *)malloc(sizeof(char)*(labelDigits + tempDigits + strlen(r1->name) + STRLEN_FOR_CPL_2VAR + 2));
  sprintf(last->quadCommand,"\tJMPZ %c%d %s%d\n", L->l, L->number, r1->name, r1->number);
  moveLast();
}
/*add RASN/IASN to the list, get char * and char * as an arguments*/
void addRASN(char * id ,char * var){
  last -> quadCommand=(char *)malloc(sizeof(char)*(strlen(id)+strlen(var)+STRLEN_FOR_CPL_2VAR+1));
  sprintf(last->quadCommand,"\tRASN %s %s\n", id, var);
  moveLast();
}
void addIASN(char * id ,char * var){
  last -> quadCommand=(char *)malloc(sizeof(char)*(strlen(id)+strlen(var)+ STRLEN_FOR_CPL_2VAR +1 ));
  sprintf(last->quadCommand,"\tIASN %s %s\n", id, var);
  moveLast();
}

/*add ITOR/RTOI to the list, get tempResult and char * as an arguments*/
void addITOR(tempResult rt, char *id){
  int tempDigits = digitsInNum(rt -> number);
  last -> quadCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(id)+STRLEN_FOR_CPL_2VAR + 1));
  sprintf(last->quadCommand,"\tITOR %s%d %s\n", rt->name, rt->number, id);
  moveLast();
}
void addRTOI(tempResult rt, char *id){
  int tempDigits = digitsInNum(rt -> number);
  last -> quadCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(id)+STRLEN_FOR_CPL_2VAR + 1));
  sprintf(last->quadCommand,"\tRTOI %s%d %s\n", rt->name, rt->number, id);
  moveLast();
}
/*add RADD/IADD to the list, get tempResulrs, char * and char * as an arguments*/
void addRADD(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> quadCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->quadCommand,"\tRADD %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}
void addIADD(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> quadCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->quadCommand,"\tIADD %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}
/*add RSUB/ISUB to the list, get tempResulrs, char * and char * as an arguments*/
void addRSUB(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> quadCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->quadCommand,"\tRSUB %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}
void addISUB(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> quadCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->quadCommand,"\tISUB %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}
/*add RMLT/IMLT to the list, get tempResulrs, char * and char * as an arguments*/
void addRMLT(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> quadCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->quadCommand,"\tRMLT %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}
void addIMLT(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> quadCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->quadCommand,"\tIMLT %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}
/*add RDIV/IDIV to the list, get tempResulrs, char * and char * as an arguments*/
void addRDIV(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> quadCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->quadCommand,"\tRDIV %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}
void addIDIV(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> quadCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->quadCommand,"\tIDIV %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}
/*add REQL/IEQL to the list, get tempResulrs, char * and char * as an arguments*/
void addREQL(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> quadCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->quadCommand,"\tREQL %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}
void addIEQL(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> quadCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->quadCommand,"\tIEQL %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}
/*add RNQL/INQL to the list, get tempResulrs, char * and char * as an arguments*/
void addRNQL(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> quadCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->quadCommand,"\tRNQL %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}
void addINQL(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> quadCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->quadCommand,"\tINQL %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}
/*add RLSS/ILSS to the list, get tempResulrs, char * and char * as an arguments*/
void addRLSS(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> quadCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->quadCommand,"\tRLSS %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}
void addILSS(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> quadCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->quadCommand,"\tILSS %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}
/*add RGRT/IGRT to the list, get tempResulrs, char * and char * as an arguments*/
void addRGRT(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> quadCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->quadCommand,"\tRGRT %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}
void addIGRT(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> quadCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->quadCommand,"\tIGRT %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}
/*this function add label to the list, get label as an atgument*/
void addLabel(label L)
{
  int labelDigits = digitsInNum(L->number);
  last->quadCommand = (char *)malloc(sizeof(char)*(labelDigits+STRLEN_FOR_LABELS+2));
  sprintf(last->quadCommand,"%c%d:\n",L->l, L->number);
  moveLast();
}
/*end of quad commaned function*/

/*this function print error msm to the stderr. if even 1 error msm has been print the quad file wont be created*/
void yyerror (const char *s)
{
  extern int yylineno;
  errorCheck = 1;
  fprintf (stderr, "error in line %d: %s\n", yylineno,s);
}