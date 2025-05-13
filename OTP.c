#include <stdio.h>


int main()
{
    char mess[100]; 
    printf("Frase: ");
    scanf(" %s",mess);
   
    int binario[] = {128,64,32,16,8,4,2,1};

    for (int i = 0; mess[i] != '\0'; i++) 
    {
        int number = mess[i];

            for(int j = 0; j < 8; j++)
            {
                if(number >= binario[j])
                {
                    number -= binario[j];
                    printf("1");
                }
                else
                {
                    printf("0");
                }
                
            }
            printf(" ");
                    
    }

    return 0;
}