#include<stdio.h>
#include<stdlib.h>
intercala1 (int p, int q, int r, int v[]) 
{
   int *w;                                 //  1
   w =(int *) malloc ((r-p) * sizeof (int));      //  2
   int i = p, j = q;                       //  3
   int k = 0;                              //  4

   while (i < q && j < r) {                //  5
      if (v[i] <= v[j])  w[k++] = v[i++];  //  6
      else  w[k++] = v[j++];               //  7
   }                                       //  8
   while (i < q)  w[k++] = v[i++];         //  9
   while (j < r)  w[k++] = v[j++];         // 10
   for (i = p; i < r; ++i)  v[i] = w[i-p]; // 11
   free (w);                               // 12
}

void mergeSort (int v[], int p, int r)
{
   if (p < r-1) {                 // 1
      int q = (p + r)/2;          // 2
      mergeSort (v, p, q);        // 3
      mergeSort (v,q, r);        // 4
      intercala1 (p, q, r, v);     // 5
   }
}

int main()
{
	int i, v[10]={19,8,67,6,51,4,3,26,1,100};//v[10]={9,8,7,6,5,4,3,2,1,0};
	mergeSort(v, 0, 10);
	for(i=0;i<10;i++)
	   printf("\n%d", v[i]);
}

