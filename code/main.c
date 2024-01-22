#include "flex.h"
#include "syntax_tree.h"
#include "parser.tab.h"
#include "syntax_check_update.h"
#include "ir.h"
#include "obj.h"

int main(int argc, char * argv[])
{
  init_hash();
  FILE * fp, * fo, * fi;
  char str[1024];
  if(argc>2){
    sprintf(str, "%s.ir", argv[2]);
    fp=fopen(argv[1],"r");
    fo=fopen(argv[2],"w");
    fi=fopen(str,"w");
    if(fp==NULL)return 1;
  }
  else return -1;
  //fo=stdout;
  yyout=fi;
  yyrestart(fp);
  yyparse();
  genIrcode(get_root(), fi);
  fclose(fp);
  fclose(fi);
  fi=fopen(str,"r");
  objtrans(fi, fo);
  fclose(fi);
  //remove(str);
  fclose(fo);
  return 0;
}