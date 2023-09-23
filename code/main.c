#include "flex.h"
#include "syntax_tree.h"

int main(int argc, char * argv[])
{
  FILE * fp, * fo;
  if(argc>1){
    fp=fopen(argv[1],"r");
    if(fp==NULL)return 1;
  }
  fo=fopen("testout.out", "w");
  yyout=fo;
  yyrestart(fp);
  yyparse();
  printf("\n");
  print_tree(get_root(),0,fo);
  //del_tree(get_root());
  fclose(fo);
  fclose(fp);
  return 0;
}