#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_PEOPLE 6
#define MAX_TREASURES 8

#if !defined (MAX_INT)
#define MAX_INT 80000
#endif

int main (void) {

   FILE *infile, *outfile;
   unsigned long int NumTreasures, NumPeople;
   unsigned long int TreasureMatrix[MAX_PEOPLE][MAX_TREASURES];

   unsigned long int BestPersonForTreasure[MAX_TREASURES];
   unsigned long int BestTotalForPerson[MAX_PEOPLE];
   unsigned long int PossiblePersonForTreasure[MAX_TREASURES];
   unsigned long int PossibleTotalForPerson[MAX_PEOPLE];
   unsigned long int BestDifference;

   unsigned long int max,min;
   unsigned long int add,carry,stop;
   unsigned long int t,p,i,j;
   unsigned long int num_solutions;
   char buffer[100];
   int tttt=0;

   /* Open the input and output files */
   infile = stdin;
   outfile = stdout;

   /* Process the input sets */
   while (TRUE) {

      /* Get the "START" */
      fscanf(infile,"%s",&buffer);
      if (feof(infile)) break;
      
      /* Get the number of treasures */
      fscanf(infile,"%ld",&NumTreasures);

      /* Get the number of people */
      fscanf(infile,"%ld",&NumPeople);

      /* Get the treasure values */
      for (p=0; p<NumPeople; p++) {
         for (t=0; t<NumTreasures; t++) {
            fscanf(infile,"%ld",&TreasureMatrix[p][t]);
         }
      }

      /* Get the "END" */
      fscanf(infile,"%s",&buffer);

      /* Init the list of best matches */
      for (t=0; t < NumTreasures; t++) {
         BestPersonForTreasure[t]=0;
         PossiblePersonForTreasure[t]=0;
      }
      for (p=0; p < NumPeople; p++) {
         BestTotalForPerson[p]=0;
      }

      /* Find the optimum combination */
      BestDifference=MAX_INT;
      stop=FALSE;
      while (!stop) {
         carry=0;
         add=1;

         /* increment to the next possible combination */
         for(t=0; t<NumTreasures; t++) {
            PossiblePersonForTreasure[t]+=carry+add;
            add=carry=0;
            if (PossiblePersonForTreasure[t]==NumPeople) {
               if (t==(NumTreasures-1)) stop=TRUE;
               PossiblePersonForTreasure[t]=0;
               carry=1;
            }
         }

         /* Init list of sums */
         for (p=0; p<NumPeople; p++) {
            PossibleTotalForPerson[p]=0;
         }
            
         /* Create this combination */
         for (t=0; t<NumTreasures; t++) {
            PossibleTotalForPerson[PossiblePersonForTreasure[t]]+=
                    TreasureMatrix[PossiblePersonForTreasure[t]][t];
         }

         /* Test this combination */
         max=0,min=MAX_INT;
         for (p=0; p<NumPeople; p++) {
            if (PossibleTotalForPerson[p] > max) {
               max = PossibleTotalForPerson[p];
            }
            if (PossibleTotalForPerson[p] < min) {
               min = PossibleTotalForPerson[p];
            }
         }
         if ((max-min) < BestDifference) {
            num_solutions = 1;
            BestDifference = max-min;
            for (p=0; p<NumPeople; p++) {
               BestTotalForPerson[p]=PossibleTotalForPerson[p];
            }
            for (t=0; t<NumTreasures; t++) {
               BestPersonForTreasure[t]=PossiblePersonForTreasure[t];
            }
         }
	 else if ((max-min) == BestDifference) {
	    num_solutions++;
	 }
      } /* Tried all combinations */

      /* input doublecheck */
      if (num_solutions > 1) {
         fprintf(outfile,"Data set has %ld optimal solutions!\n",num_solutions);
      }
      if(tttt++)fprintf(outfile,"\n");
      /* Output the optimal solution */
      for (p=0; p<NumPeople; p++) {
         for (t=0; t<NumTreasures; t++) {
            if (BestPersonForTreasure[t]==p) {
               fprintf(outfile,"%ld ",t+1);
            }
         }
         fprintf(outfile,"%ld\n",BestTotalForPerson[p]);
      }
      

   } /* Processed all input sets */

   /* Clean up */
   fclose(infile);
   fclose(outfile);

   return 0;

}