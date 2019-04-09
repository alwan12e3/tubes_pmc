#include"lib.h"

void tampil_as(jadwal_t jadwal_prak[][5]){
    int i,j,k;
    char hari_pratikum[10][5] = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat"};
    printf ("|---------------------------------------------------------------------------------------|\n");
    printf ("|%30s|%15s|%15s|%15s|%15s|\n","Ruang Pratikum","LAB1","LAB2","LAB3","LSS");
    printf ("|%15s|%15s|%15s|%15s|%15s|\n", "Minggu","Hari","-----------","------------","----------")
    printf ("|%15s|%15s|%15s|%15s|%15s|\n", "-----------","-----------","-----------","------------","----------")
     for (i = 0; i<12; i++)
    {
        for (j = 0; j < 5; j++)
    {
        printf("|%15d|%15s|", i+1, hari_pratikum[i]);
        for(k=0;k<4;k++)
        {
            if (jadwal_prak[i][j].lab[k].assist_count==2){
            printf ("|%6s,%8s",jadwal_prak[i][j].lab[k].assist[0], jadwal_prak[i][j].lab[k].assist[1]);
        }
            else if (jadwal_prak[i][j].lab[k].assist_count==1)
            {
                printf ("|%15s",jadwal_prak[i][j].lab[k].assist[0]);
            }
        else
        {
             printf ("|%15s","");
        }
        }
        printf("|\n");
        }
    }
}

int main(){
    prak_t p[3]={0};
    strcpy(p[2].id, "EB2200");
    strcpy(p[0].id, "EL2205");
    strcpy(p[1].id, "EL2208");
    jadwal_t jadwal[12][5]={0};
    char s[255];
    input_sch(jadwal, p);
    tampil_as(jadwal);
    return 0;
}

