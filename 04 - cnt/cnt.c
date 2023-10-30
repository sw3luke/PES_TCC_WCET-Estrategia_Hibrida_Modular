#define MAXSIZE 10

/* Typedefs */
typedef int matrix [MAXSIZE][MAXSIZE];

/* Forwards declarations */
int main(void);
int Test(matrix);
int Initialize(matrix);
int InitSeed(void);
void Sum(matrix);
int RandomInteger(void);

/* Globals */
int Seed;
matrix Array;
int Postotal, Negtotal, Poscnt, Negcnt;

/* The main function */
int main (void)
{
   InitSeed();
   Test(Array);
   return 1;
}


int Test(matrix Array)
{
   Initialize(Array);
   Sum(Array);

   return 0;
}


/* Intializes the given array with random integers. */
int Initialize(matrix Array)
{
   register int OuterIndex, InnerIndex;

   for (OuterIndex = 0; OuterIndex < MAXSIZE; OuterIndex++) /* 100 + 1 */
      for (InnerIndex = 0; InnerIndex < MAXSIZE; InnerIndex++) /* 100 + 1 */
         Array[OuterIndex][InnerIndex] = 100;

   return 0;
}


/* Initializes the seed used in the random number generator. */
int InitSeed (void)
{
   Seed = 0;
   return 0;
}

void Sum(matrix Array)
{
  register int Outer, Inner;

  int Ptotal = 0; /* changed these to locals in order to drive worst case */
  int Ntotal = 0;
  int Pcnt = 0;
  int Ncnt = 0;

  for (Outer = 0; Outer < MAXSIZE; Outer++) /* Maxsize = 100 */
    for (Inner = 0; Inner < MAXSIZE; Inner++)
      if (Array[Outer][Inner] >= 0) {
	  Ptotal += Array[Outer][Inner];
	  Pcnt++;
	}
	else {
	  Ntotal += Array[Outer][Inner];
	  Ncnt++;
	}

  Postotal = Ptotal;
  Poscnt = Pcnt;
  Negtotal = Ntotal;
  Negcnt = Ncnt;
}

/* Generates random integers between 0 and 8095 */
int RandomInteger(void)
{
   Seed = ((Seed * 133) + 81) % 8095;
   return Seed;
}




