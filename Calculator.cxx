#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char to_upper(char);
void main()
{
    int a,b,c,n;

    do
    {
        printf("\n\n\n 1. Addition \n 2. Substraction \n 3. Multiplication \n 4. Division \n 5. Exit \n");
        printf("\n Enter Your Choice : ");
        scanf("%d",&n);
        switch(n)
        {
            case 1 : printf("\n Enter First No. : ");                     scanf("%d",&a);
                     printf(" Enter Second No. : ");
                     scanf("%d",&b);
                     c=a+b;
                     printf("\n The Answer is : %d",c);
                     break;

            case 2 : printf("\n Enter First No. : ");                     scanf("%d",&a);
                     printf(" Enter Second No. : ");
                     scanf("%d",&b);
                     c=a-b;
                     printf("\n The Answer is : %d",c);
                     break;

            case 3 : printf("\n Enter First No. : ");                     scanf("%d",&a);
                     printf(" Enter Second No. : ");
                     scanf("%d",&b);
                     c=a*b;
                     printf("\n The Answer is : %d",c);
                     break;

            case 4 : printf("\n Enter First No. : ");                     scanf("%d",&a);
                     printf(" Enter Second No. : ");
                     scanf("%d",&b);
                     c=a/b;
                     printf("\n The Answer is : %d",c);
                     break;

            case 5 : exit(1);
            default : printf("Invalid Input");
        }
        printf("\n\n Want to Contunue ?(Y/N) : ");
        getch();
    } while (to_upper(getchar()) != 'N');
}

char to_upper(char ch)
{
    if(ch>='a' && ch<='z')
	{
          ch=ch+('A'-'a');
	  return(ch);
	}
	else
	  return(ch);
}