#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define k 5
int input(int m[][k])
{int i, j, positions[]={0, 1, 3};
srand(time(NULL));
int mas[k][k];
   for (i=0; i<k; i++)
    {for (j=0; j<k; j++)
    {if (i==j)
     mas[i][j]=0;
     else if (i==0)
      mas[i][j]=j;
      else if  (j==0)
      mas[i][j]=i;

      }

       }
       for(i=1; i<k; i++)
        {for (j=i+1; j<k; j++)
         {m[i][j]=positions[rand()%3];

         switch(m[i][j])
         {
          case(0): m[j][i]=3;
                   break;
          case(1): m[j][i]=1;
                   break;
          default: m[j][i]=0;
                   break;
          }
          }
}
for (i=0; i<k; i++)
    {for (j=0; j<k; j++)
   { printf("%d\t", mas[i][j]);}
    printf("\n");
}
}
void main()
{int i, j;
int mas[k][k];
input(mas);
}



