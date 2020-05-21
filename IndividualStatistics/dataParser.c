#include <stdio.h>
#include <string.h>

#define numGames 12
typedef struct playerStats{
    int SOGF;
    int MSF;
    int OF;
    int SOGA;
    int MSA;
    int OA;
    int shifts;
}playerStats;

int checkShift(int LastShift[], int number){
    for(int i = 0; i<5; i++){
        if(LastShift[i] == number){
            return 1;
        }
    }
    return 0;
}

int checkValid(int SOGF,int MSF, int OF, int SOGA,int MSA , int OA){
    if(SOGF > 8 || MSF > 8 || OF > 8 || SOGA > 8 || MSA > 8 || OA > 8){
        return 2;
    }
    return 0;
}

void scanSection(char link[],playerStats data[]){


    FILE* input_file = fopen(link, "r");
    int SOGF, MSF,SOGA, OF, MSA, OA, p1, p2, p3, p4, p5 = 0;
    if(input_file == NULL){
        printf("error");
    }
    int PlayersOn[200][5];
    for(int i = 0 ; i<200; i++){
        for(int j = 0; j<5; j++){
            PlayersOn[i][j] = 99;
        }
    }
    int line = 0;
    int per = 0;
    while( fscanf(input_file, "%d %d %d %d %d %d %d %d %d %d %d", &p1, &p2, &p3, &p4, &p5, &SOGF, &MSF, &OF, &SOGA , &MSA, &OA)==11 ){
        line++;
        PlayersOn[line][0] = p1;
        PlayersOn[line][1] = p2;
        PlayersOn[line][2] = p3;
        PlayersOn[line][3] = p4;
        PlayersOn[line][4] = p5;
        if(checkShift(PlayersOn[line-1], p1) != 1){
            data[p1].shifts++;
        }
        if(checkShift(PlayersOn[line-1], p2) != 1){
            data[p2].shifts++;
        }
        if(checkShift(PlayersOn[line-1], p3) != 1){
            data[p3].shifts++;
        }
        if(checkShift(PlayersOn[line-1], p4) != 1){
            data[p4].shifts++;
        }
        if(checkShift(PlayersOn[line-1], p5) != 1){
            data[p5].shifts++;
        }
        if(p1!=1&&p1!= 0) {
            if (p1 == p2 | p1 == p3 | p1 == p4 | p1 == p5 | p2 == p3 | p2 == p4 | p2 == p5 | p3 == p4 | p3 == p5 |
                p4 == p5) {
                printf("%d %s 1\n", line,link);
            }
        }
        if(checkValid(SOGF,MSF, OF,SOGA,MSA,OA) == 2){
            printf("%d %s 2\n", line,link);
        }
            data[99].SOGF += SOGF;
            data[99].MSF += MSF;
            data[99].OF += OF;
            data[99].SOGA += SOGA;
            data[99].OA += OA;
            data[99].MSA += MSA;



        data[p1].SOGF += SOGF;
        data[p1].MSF += MSF;
        data[p1].OF += OF;
        data[p1].SOGA += SOGA;
        data[p1].MSA += MSA;
        data[p1].OA += OA;

        data[p2].SOGF += SOGF;
        data[p2].MSF += MSF;
        data[p2].OF += OF;
        data[p2].SOGA += SOGA;
        data[p2].MSA += MSA;
        data[p2].OA += OA;

        data[p3].SOGF += SOGF;
        data[p3].MSF += MSF;
        data[p3].OF += OF;
        data[p3].SOGA += SOGA;
        data[p3].MSA += MSA;
        data[p3].OA += OA;

        data[p4].SOGF += SOGF;
        data[p4].MSF += MSF;
        data[p4].OF += OF;
        data[p4].SOGA += SOGA;
        data[p4].MSA += MSA;
        data[p4].OA += OA;

        data[p5].SOGF += SOGF;
        data[p5].MSF += MSF;
        data[p5].OF += OF;
        data[p5].SOGA += SOGA;
        data[p4].MSA += MSA;
        data[p5].OA += OA;
    }
    fclose(input_file);
}




int main() {
    playerStats data[numGames][100];

    for(int i = 0; i<numGames;i++){
        for(int j = 0; j<100;j++){
            data[i][j].MSF = 0;
            data[i][j].SOGF=0;
            data[i][j].OF=0;
            data[i][j].OA=0;
            data[i][j].MSA=0;
            data[i][j].SOGA=0;
            data[i][j].shifts=0;
        }
    }

    char* gamestxt[numGames] = {"data/Dec05ES.txt", "data/Dec07ES.txt","data/Jan02ES.txt","data/Jan08ES.txt","data/Jan10ES.txt","data/Jan22ES.txt","data/Feb02ES.txt","data/Feb05ES.txt","data/Feb07ES.txt","data/Feb09ES.txt","data/Feb12ES.txt","data/Feb14ES.txt"};
    char* games[numGames] = {"Dec05", "Dec07","Jan02","Jan08","Jan10","Jan22","Feb02","Feb05","Feb07","Feb09","Feb12","Feb14"};
    char* opponent[numGames] = {"VIC","KPI","VIC","CGK","CRS","GEN","NAN","SAN","SAN","KPI","PEN","PEN"};
    for(int i = 0; i<numGames;i++){
        scanSection(gamestxt[i],data[i]);
    }
    int players[20] = {3,5,6,7,8,11,12,14,15,16,17,18,19,21,22,23,27,71,88,91};

    int numshifts[numGames];
    memset(numshifts,0,20);
    for(int y = 0; y <numGames; y++){
        for(int i = 2; i < 98; i++){
            numshifts[y]+=data[y][i].shifts;
        }
    }

    FILE* output = fopen("output.R", "w");
    int k;
    int j= 0;
    for(k = 0, j = players[k]; k<20; j = players[++k]){
        fprintf(output,"\ncorsi%d <- c(",j);
        for(int i = 0; i<numGames; i++){
            if(data[i][j].MSF!=0||data[i][j].MSA!=0) {
                if(i!=numGames-1) {
                    fprintf(output, "%.2f,", ((((data[i][j].SOGF + data[i][j].MSF) * (1.0)) /
                                               (data[i][j].SOGF + data[i][j].MSF + data[i][j].SOGA + data[i][j].MSA)) *
                                              (100.0)));
                }else{
                    fprintf(output, "%.2f", ((((data[i][j].SOGF + data[i][j].MSF) * (1.0)) /
                                               (data[i][j].SOGF + data[i][j].MSF + data[i][j].SOGA + data[i][j].MSA)) *
                                              (100.0)));
                }
            }
        }
        fprintf(output,")\nteamcorsi%d <- c(",j );

        for(int i = 0;i<numGames;i++){
            if(data[i][j].MSF!=0||data[i][j].MSA!=0){
                if(i!=numGames-1) {
                    fprintf(output, "%.2f,", ((((data[i][99].SOGF + data[i][99].MSF) * (1.0)) /
                                               (data[i][99].SOGF + data[i][99].MSF + data[i][99].SOGA +
                                                data[i][99].MSA)) * (100.0)));
                }else{
                    fprintf(output, "%.2f", ((((data[i][99].SOGF + data[i][99].MSF) * (1.0)) /
                                               (data[i][99].SOGF + data[i][99].MSF + data[i][99].SOGA +
                                                data[i][99].MSA)) * (100.0)));
                }
            }
        }
        fprintf(output,")\nSOG%d <- c(",j);
        for(int i = 0;i<numGames;i++){
            if(data[i][j].MSF!=0||data[i][j].MSA!=0){
                if(i!=numGames-1) {
                    fprintf(output, "%.2f,",((((data[i][j].SOGF) * (1.0)) / (data[i][j].SOGF + data[i][j].SOGA)) * (100.0)));
                }else{
                    fprintf(output, "%.2f",((((data[i][j].SOGF) * (1.0)) / (data[i][j].SOGF + data[i][j].SOGA)) * (100.0)));
                }
            }
        }
        fprintf(output,")\nTeamSOG%d <- c(",j);
        for(int i = 0;i<numGames;i++){
            if(data[i][j].MSF!=0||data[i][j].MSA!=0){
                if(i != numGames-1) {
                    fprintf(output, "%.2f,",(((data[i][99].SOGF) * (1.0)) / (data[i][99].SOGF + data[i][99].SOGA)) * (100.0));
                }else{
                    fprintf(output, "%.2f",(((data[i][99].SOGF) * (1.0)) / (data[i][99].SOGF + data[i][99].SOGA)) * (100.0));
                }
            }
        }
        fprintf(output,")\nScoringOpps%d <- c(",j);
        for(int i = 0;i<numGames;i++){
            if(data[i][j].MSF!=0||data[i][j].MSA!=0){
                if(i != numGames-1) {
                    fprintf(output, "%.2f,", (((data[i][j].OF) * (1.0)) / (data[i][j].OF + data[i][j].OA)) * (100.0));
                }else{
                    fprintf(output, "%.2f", (((data[i][j].OF) * (1.0)) / (data[i][j].OF + data[i][j].OA)) * (100.0));
                }
            }
        }
        fprintf(output,")\nTeamScoringOpps%d <- c(",j);
        for(int i = 0;i<numGames;i++){
            if(data[i][j].MSF!=0||data[i][j].MSA!=0){
                if(i!=numGames-1) {
                    fprintf(output, "%.2f,",(((data[i][99].OF) * (1.0)) / (data[i][99].OF + data[i][99].OA)) * (100.0));
                }else{
                    fprintf(output, "%.2f",(((data[i][99].OF) * (1.0)) / (data[i][99].OF + data[i][99].OA)) * (100.0));
                }
            }
        }

        fprintf(output,")\nSOGFShift%d <- c(",j);
        for(int i = 0;i<numGames;i++){
            if(data[i][j].MSF!=0||data[i][j].MSA!=0){
                if(i!=numGames-1) {
                    fprintf(output, "%.2f,",((data[i][j].SOGF)*(1.0))/data[i][j].shifts);
                }else{
                    fprintf(output, "%.2f",((data[i][j].SOGF)*(1.0))/data[i][j].shifts);
                }
            }
        }

        fprintf(output,")\nSOGAShift%d <- c(",j);
        for(int i = 0;i<numGames;i++){
            if(data[i][j].MSF!=0||data[i][j].MSA!=0){
                if(i!=numGames-1) {
                    fprintf(output, "%.2f,",((data[i][j].SOGA)*(1.0))/data[i][j].shifts);
                }else{
                    fprintf(output, "%.2f",((data[i][j].SOGA)*(1.0))/data[i][j].shifts);
                }
            }
        }

        fprintf(output,")\nOFShift%d <- c(",j);
        for(int i = 0;i<numGames;i++){
            if(data[i][j].MSF!=0||data[i][j].MSA!=0){
                if(i!=numGames-1) {
                    fprintf(output, "%.2f,",((data[i][j].OF)*(1.0))/data[i][j].shifts);
                }else{
                    fprintf(output, "%.2f",((data[i][j].OF)*(1.0))/data[i][j].shifts);
                }
            }
        }
        fprintf(output,")\nOAShift%d <- c(",j);
        for(int i = 0;i<numGames;i++){
            if(data[i][j].MSF!=0||data[i][j].MSA!=0){
                if(i!=numGames-1) {
                    fprintf(output, "%.2f,",((data[i][j].OA)*(1.0))/data[i][j].shifts);
                }else{
                    fprintf(output, "%.2f",((data[i][j].OA)*(1.0))/data[i][j].shifts);
                }
            }
        }

        fprintf(output,")\nESShiftShare%d <- c(",j);
        for(int i = 0;i<numGames;i++){
            if(data[i][j].MSF!=0||data[i][j].MSA!=0){
                if(i!=numGames-1) {
                    fprintf(output, "%.2f,",((data[i][j].shifts)*(500.0))/numshifts[i]);
                }else{
                    fprintf(output, "%.2f",((data[i][j].shifts)*(500.0))/numshifts[i]);
                }
            }
        }

        fprintf(output,")\nGames%d <- c(",j);
        for(int i = 0;i<numGames;i++){
            if(data[i][j].MSF!=0||data[i][j].MSA!=0){
                if(i!=numGames-1) {
                    fprintf(output, "\"%s\",", games[i]);
                }else{
                    fprintf(output, "\"%s\"", games[i]);
                }
            }
        }

        fprintf(output,")\nOpponent%d <- c(",j);
        for(int i = 0;i<numGames;i++){
            if(data[i][j].MSF!=0||data[i][j].MSA!=0){
                if(i!=numGames-1) {
                    fprintf(output, "\"%s\",", opponent[i]);
                }else{
                    fprintf(output, "\"%s\"", opponent[i]);
                }
            }
        }
        fprintf(output,")\n");
        int averages[] = {0,0,0,0,0,0};
        for(int i = 0; i < numGames; i ++){
            averages[0] += (data[i][j].MSF+data[i][j].SOGF);
            averages[1] += (data[i][j].MSA+data[i][j].SOGA);
            averages[2] += data[i][j].SOGF;
            averages[3] += data[i][j].SOGA;
            averages[4] += data[i][j].OF;
            averages[5] += data[i][j].OA;
        }
        fprintf(output,"averages%d <- c(%f,%f,%f)\n",j,(averages[0]*(100.0)/(averages[1]+averages[0])),(averages[2]*(100.0)/(averages[3]+averages[2])),(averages[4]*(100.0)/(averages[5]+averages[4])));
    }

    fclose(output);



    for(int i = 0; i < numGames; i++){
        printf("%d %d %d %d\n", data[i][99].SOGF,data[i][99].SOGA,data[i][99].MSF,data[i][99].MSA);

    }
    return 0;





}
