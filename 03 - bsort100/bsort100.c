#define FALSE 0
#define TRUE 1
#define NUMELEMS 100
#define MAXDIM   (NUMELEMS+1)

int             Array[MAXDIM];
void            BubbleSort(int Array[]);
void            Initialize(int Array[]);

int 
main(void)
{
	Initialize(Array);
	BubbleSort(Array);
	return 0;
}

void Initialize(int Array[])
/*
 * Initializes given array with randomly generated integers.
 */
{
   int  Index, fact;

fact = -1;
for (Index = 1; Index <= NUMELEMS; Index ++) {
    Array[Index] = Index * fact/* * KNOWN_VALUE*/;
  }
}

void 
BubbleSort(int Array[])
/*
 * Sorts an array of integers of size NUMELEMS in ascending order.
 */
{
	int             Sorted = FALSE;
	int             Temp, Index, i;

	for (i = 1;
	     i <= NUMELEMS - 1;	/* apsim_loop 1 0 */
	     i++) {
		Sorted = TRUE;
		for (Index = 1;
		     Index <= NUMELEMS - 1;	/* apsim_loop 10 1 */
		     Index++) {
			if (Index > NUMELEMS - i)
				break;
			if (Array[Index] > Array[Index + 1]) {
				Temp = Array[Index];
				Array[Index] = Array[Index + 1];
				Array[Index + 1] = Temp;
				Sorted = FALSE;
			}
		}

		if (Sorted)
			break;
	}
}
