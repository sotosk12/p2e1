
#include <stdio.h>
#include <string.h>

int n;
int func(char ar[n][10],char pin[10],int type){
    if (type=1)
        n=200;
    else
       n=40;
    int i=0;
    int pos=-1;
    while (i<n && pos==-1)
        if (strcmp(ar[i],pin)==0)
            pos=i;
        else
            i++;
    return pos;
}
int func1(char ar[n][10],char pin[10],int type){
    if (type=1)
        n=200;
    else
       n=40;
    int i=0;
    int pos=-1;
    while (i<n && pos==-1)
        if (strcmp(ar[i],"0")==0)
            pos=i;
        else
            i++;
    return pos;
}

int main()
{
    char car[200][10];
    char moto[40][10];
    for(int i=0;i<200;i++)
        strcpy(car[i],"0");
    for(int i=0;i<200;i++)
        strcpy(moto[i],"0");
        
    char pin[10];
    int type,found,pos;
    int sumCars=0;
    int sumMotos=0;

    printf("Δώσε πινακίδα:");
    scanf("%s",pin);
    while (strcmp(pin,"end")!=0){
        printf("Δώσε τύπο(1-αυτοκίνητο/2-μοτοσυκλέτα):");
        scanf("%i",&type);
        if (type==1){
            found=func(car,pin,type);
            if (found==-1){
                pos=func1(car,pin,type);
                if (pos==-1)  
                    printf("το πάρκινκ με τα οχήματα είναι γεμάτο");
                else
                    strcpy(car[pos],pin);
            }else{
                pos=func(car,pin,type);
                strcpy(car[pos],"0");
                sumCars+=10;
            }
        }
        else{
            found=func(moto,pin,type);
            if (found==-1){
                pos=func1(moto,pin,type);
                if (pos==-1)  
                    printf("το πάρκινκ με τις μοτοσυκλέτες είναι γεμάτο");
                else
                    strcpy(moto[pos],pin);
            }else{
                pos=func(moto,pin,type);
                strcpy(moto[pos],"0");
                sumMotos+=4;
            }
        }
           
        printf("Δώσε πινακίδα:");
        scanf("%s",pin);
    }
    int c=0;
    printf("Aριθμοί ελέυθερων θέσεων αυτοκινήτων\n");
    for (int i=0;i<200;i++)
        if (strcmp(car[i],"0")==0){
            printf("%i ",i+1);
            c++;
        }
        
    printf("\nΣύνολo ελέυθερων θέσεων αυτοκινήτων:%i\n",c);    
    
    c=0;
    printf("Aριθμοί ελέυθερων θέσεων μοτσυκλετών\n");
    for (int i=0;i<40;i++)
        if (strcmp(moto[i],"0")==0){
            printf("%i ",i+1);
            c++;
        }
    
    printf("\nΣύνολo ελέυθερων θέσεων αυτοκινήτων:%i\n",c); 
    
    printf("\n Συνολικά έσοδα:%i\n",sumCars+sumMotos);
    return 0;
}
