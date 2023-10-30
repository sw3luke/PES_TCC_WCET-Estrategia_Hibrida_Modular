#define UPPERLIMIT 20

typedef int matrix [UPPERLIMIT][UPPERLIMIT];

int Seed;
matrix ArrayA, ArrayB, ResultArray;

int main()
{
   InitSeed();
   Test(ArrayA, ArrayB, ResultArray);
   return 0;
}


void InitSeed(void)
/*
 * Initializes the seed used in the random number generator.
 */
{
  Seed = 0;
}


void Test(matrix A, matrix B, matrix Res)
/*
 * Runs a multiplication test on an array.
 */
{
   Initialize(A);
   Initialize(B);
   Multiply(A, B, Res);
}


void Initialize(matrix Array)
/*
 * Intializes the given array with random integers.
 */
{
   int OuterIndex, InnerIndex;

   for (OuterIndex = 0; OuterIndex < UPPERLIMIT; OuterIndex++)
      for (InnerIndex = 0; InnerIndex < UPPERLIMIT; InnerIndex++)
         Array[OuterIndex][InnerIndex] = RandomInteger();
}


int RandomInteger(void)
/*
 * Generates random integers between 0 and 8095
 */
{
   Seed = ((Seed * 133) + 81) % 8095;
   return (Seed);
}

void Multiply(matrix A, matrix B, matrix Res)
/*
 * Multiplies arrays A and B and stores the result in ResultArray.
 */
{
   register int Outer, Inner, Index;

   for (Outer = 0; Outer < UPPERLIMIT; Outer++)
      for (Inner = 0; Inner < UPPERLIMIT; Inner++)
      {
         Res [Outer][Inner] = 0;
         for (Index = 0; Index < UPPERLIMIT; Index++)
            Res[Outer][Inner]  +=
               A[Outer][Index] * B[Index][Inner];
       }
}
