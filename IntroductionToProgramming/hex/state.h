void printstate(char **,int);
int checkwin(char **,int);
int tracepath(char **,int,int,char,int);
void b2blacks(char **,int);

typedef struct moves *Listptr;

Listptr addmv(Listptr,char,int,int);
void undo(Listptr *,char **);

struct moves{
 char p;
 int lpawn;
 int npawn;
 Listptr prevmv;
            };

