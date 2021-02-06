#include<stdio.h>
#include<string.h>

int main()
{
	int i,j;
	char A[10][50],temp[50];
	int as[10][50];
	
	//ingresa
	printf("Ingrese 10 palabras:\n");
	for(i=0;i<10;++i)
	{
        scanf("%s[^\n]",A[i]);
    }
    //limpia
    for(i=0;i<10;i++)
    {
    	for(j=0;j<50;j++)
    	{
    		A[i][j]=0;
    		as[i][j]=0;	
			temp[j]=0;	
		}

	}
	//ascii
    for(i=0;i<10;i++)
  		for(j=0;j<50;j++)
    	{
    		as[i][j]=(int)A[i][j];
		}

	
	
	//ordena
    for(i=0;i<10;i++)
        for(j=0;j<50;j++)
        {
            if(as[i][j]>as[i+1][j])
            {
                strcpy(temp, A[i]);
                strcpy(A[i], A[j]);
                strcpy(A[j], temp);
            }
        }

    printf("\nPalabras ordenadas: \n");
    for(i=0;i<10;++i)
    {
        puts(A[i]);
    }

    return 0;
}
