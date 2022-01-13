#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define BUF_LEN 256

typedef struct bank
{
    char nama[20], contact[20];
    float tabungan;
    char waktu[64];
}bank;

void create(){ 
    struct bank b;
    char ph[30];
    FILE *fp;
    fp = fopen("nasabah.txt", "wb");
    printf("\nDate(dd/mm/yyyy): ");
    scanf("%s", b.waktu);    
    printf("\nEnter your name: ");
    scanf("%s", b.nama);
    printf("\nEnter you phone number: ");
    scanf("%s", b.contact);
    do {
        printf("\nEnter your amount for deposit: ");
        scanf("%f", &b.tabungan);
        if(b.tabungan < 100000) {
            printf("Value must be greater than Rp100.000");
        } else if (b.tabungan > 5000000) {
            printf("Value must be lower than Rp5000.000");
        } else{
            printf("\nType ok if done: ");
            scanf("%s", ph);
        }
        
    } while(strcmp(ph, "ok"));
    fwrite(&b, sizeof(bank),1,fp);
    fclose(fp);
}

void display(){
    struct bank b;
    FILE *fp;
    fp = fopen("nasabah.txt", "rb");
    while(fread(&b, sizeof(bank),1,fp)){
            printf("\nCreated At: %s", b.waktu);
            printf("\nName: %s", b.nama);
            printf("\nContact: %s", b.contact);
            printf("\nBalance: Rp.%.2f\n", b.tabungan);
        
    }
    fclose(fp);
}

void destroy(){
    char n[20];
    int found=0;
    struct bank b;
    FILE *fp, *fp1;
    fp = fopen("nasabah.txt", "rb");
    fp1 = fopen("temp.txt", "wb");

    printf("Enter your accont name for delete: ");
    scanf("%s", n);
    while (fread(&b, sizeof(bank),1,fp))
    {
        /* code */
        if  (strcmp(b.nama, n)==0){
            found = 1;
        } else {
            fwrite(&b, sizeof(bank),1,fp);
        }
    }
    fclose(fp);
    fclose(fp1);

    if (found) {
        fp1 = fopen("temp.txt", "r");
        fp = fopen("nasabah.txt", "w");

        while (fread(&b, sizeof(bank),1,fp1))
        {
            /* code */
            fwrite(&b, sizeof(bank),1,fp);
        }
        fclose(fp);
        fclose(fp1);
        
    } else {
        printf("\nYour account name is wrong!!\n");
    }
    
    
}

void tarik(){
    struct bank b;
    float total, wd;
    int benar=0;
    FILE *fp , *fp1;
    fp = fopen("nasabah.txt", "rb");
    
    fread(&b, sizeof(bank),1,fp);
    printf("\nYour Balance: %.2f", b.tabungan);
    fclose(fp);

    fp1 = fopen("temp.txt", "wb");
    printf("\nEnter amount for withdraw: ");
    scanf("%f", &wd);
    if(wd < 100000){
        printf("Value must be greater than Rp100.000");
    } else if (wd > 5000000) {
        printf("Value must be lower than Rp5000.000");
    } else {
        total = b.tabungan - wd;
        printf("\nYour Balance: %.2f", total);
        b.tabungan = total;
        fwrite(&b, sizeof(bank),1,fp1);
        benar = 1;
    }
    fclose(fp1);

    if(benar){
        fp1 = fopen("temp.txt", "rb");
        fp = fopen("nasabah.txt", "wb");

        while (fread(&b, sizeof(bank),1,fp1))
        {
            /* code */
            fwrite(&b, sizeof(bank),1,fp);
        }
        fclose(fp);
        fclose(fp1);
        
    }
    
}

void setor(){
    struct bank b;
    float total, wd;
    int benar=0;
    FILE *fp , *fp1;
    fp = fopen("nasabah.txt", "rb");
    
    fread(&b, sizeof(bank),1,fp);
    printf("\nYour Balance: %.2f", b.tabungan);
    fclose(fp);

    fp1 = fopen("temp.txt", "wb");
    printf("\nEnter amount for deposit: ");
    scanf("%f", &wd);
    if(wd < 100000){
        printf("Value must be greater than Rp100.000");
    } else if (wd > 5000000) {
        printf("Value must be lower than Rp5000.000");
    } else {
        total = b.tabungan + wd;
        printf("\nYour Balance: %.2f", total);
        b.tabungan = total;
        fwrite(&b, sizeof(bank),1,fp1);
        benar = 1;
    }
    fclose(fp1);

    if(benar){
        fp1 = fopen("temp.txt", "rb");
        fp = fopen("nasabah.txt", "wb");

        while (fread(&b, sizeof(bank),1,fp1))
        {
            /* code */
            fwrite(&b, sizeof(bank),1,fp);
        }
        fclose(fp);
        fclose(fp1);
        
    }
}

int main(){
    int ch;
    do{
        printf("\nBank Management System");
        printf("\n1. Create account");
        printf("\n2. Show account");
        printf("\n3. Withdraw");
        printf("\n4. Deposit");
        printf("\n5. Close account");
        printf("\n0. Exit");
        printf("\nEnter: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            create();
            break;
        
        case 2:
            display();
            break;
        
        case 3:
            tarik();
            break;

        case 4:
            setor();
            break;

        case 5:
            destroy();
            break;

        }


    }while (ch!=0);
    return 0;
}