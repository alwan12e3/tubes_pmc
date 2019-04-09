#include"lib.h"

void tampil_sche(jadwal_t jadwal_prak[][5]){
    int i,j,k;
    char hari_pratikum[][10] = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat"};
    printf ("|%91s|\n","---------------------------------------------------------------------------------------");
    printf ("|%31s|%15s|%15s|%15s|%15s|\n","Ruang Pratikum","LAB1","LAB2","LAB3","LSS");
    printf ("|%15s|%15s|%15s|%15s|%15s|%15s|\n", "Minggu","Hari","-----------","------------","----------","----------");
    printf ("|%15s|%15s|%15s|%15s|%15s|%15s|\n", "-----------","-----------","-----------","------------","----------","-----------");
    for (i = 0; i<12; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("|%15d|%15s|", i+3, hari_pratikum[j]);
            for(k=0;k<4;k++)
            {
                if (k != 0){
                    printf("|");
                }
                printf ("%6s-%8s",jadwal_prak[i][j].lab[k].prak, jadwal_prak[i][j].lab[k].rom);
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
    tampil_sche(jadwal);
    return 0;
}
