#include"lib.h"

void ruller_checker(FILE *fp, jadwal_t jadwal_prak[][5]){
	char line[100];
	char *pch;
	lab_t dummy = {0};
	int a,i,j,k,l ;
	int minggu[20];int day[20];
	if(fp == NULL){
		printf("Cannot open file \n");
		return;
	} else {
		i = 0;
		while(fgets(line, sizeof(line), fp) != NULL){
			pch = strtok(line," ");
            minggu[i] = atoi(pch)-3;
			pch = strtok (NULL," \n");
			day[i]=str2enum_hari(pch);

            printf ("Minggu %d Hari %d\n", minggu[i], day[i]);
			i++;
	    }

        //Eval
        int gugur=0;
        int mines = 0;
        for (int a=0; a<i;a++){
            for (j=0; j<4; j++){
                //printf("Count pada week %d day = %d  lab %s adalah %d\n", minggu[a], day[a],jadwal_prak[minggu[a]][day[a]].lab[j].id,jadwal_prak[minggu[a]][day[a]].lab[j].count );
                if (jadwal_prak[minggu[a]][day[a]].lab[j].count == 1){
                    jadwal_prak[minggu[a]][day[a]].lab[j]=dummy;
                    gugur= 1;
                    
                  //  printf("GAGAL\n");

                }
            }
            if (gugur){     
                mines++;
                gugur = 0;
            }
        }


        printf("%d/%d rule checked", i-mines, i);

    }
}

int main(){
    prak_t p[3]={0};
    strcpy(p[2].id, "EB2200");
    strcpy(p[0].id, "EL2205");
    strcpy(p[1].id, "EL2208");
    jadwal_t j[12][5]={0};
    //lab_t dummy={0};

    input_sch(j, p);
    FILE *f;
     
    f = fopen("file.txt","r");
    ruller_checker(f,j);
    fclose(f);

    return 0;
}