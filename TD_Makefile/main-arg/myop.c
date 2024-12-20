#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[], char* arge[]) { 

  int aflag = 0;
  int bflag = 0;
  char *cvalue = NULL;
  int index;
  int c;
  int afficher = 0;

  opterr = 0;
  while ((c = getopt (argc, argv, "ac:p")) != -1)
    switch (c)
      {
      case 'a':
        aflag = 1;
        break;
      case 'b':
        bflag = 1;
        break;
      case 'c':
        cvalue = optarg;
        break;
      case 'p' :
	afficher = 1;
	break;
      case '?':
        if (optopt == 'c')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }
	int i;
  int res;
	char *e;
  if (afficher==1) {
    res = 1;
	for (i=2 ; i<argc; ++i) { 
    res*=strtol(argv[i],&e,10);
  }
   printf("produit : %d\n", res);
}
else {
    res = 0;
	for (i=1 ; i<argc; ++i) { 
    res+=strtol(argv[i],&e,10);
  }
   printf("somme : %d\n", res);
}


	return 0 ;
}
