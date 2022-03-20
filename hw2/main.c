#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 

typedef struct record {
    int lotto_no;
    int lotto_receipt;
    int emp_id;
    char lotto_date[64];
    char lotto_time[64];
} typerecord;

typedef struct emp_record_t {
    int emp_id;
    char emp_name[64];
    int emp_salary;
} emp_record_t;

int save_employee() {
    FILE* femp;
    emp_record_t record;
    femp = fopen ("operator_id.bin", "ab");
    printf("新增操作人員 ID (0~99):");
    scanf("%d", &record.emp_id);
    record.emp_id >= 100 ?  printf("新增失敗，請重試!\n"), exit(1) : 1; //後面的數字沒意義
    printf("新增操作人員 Name:");
    scanf("%s", record.emp_name);
    printf("新增操作人員 Salary:");
    scanf("%d", &record.emp_salary);
    fwrite(&record, sizeof(record), 1, femp);
    fclose(femp);
    exit(1);//結束程式
}

int save_idfile() {
    FILE* fid;
    fid = fopen("operatid_name.bin", "wb+");
    int id_num[1] = {0};
    int idbuffer = 0;
    printf("請輸入操作人員的ID:");
    scanf("%d", &idbuffer);
    fwrite(id_num, sizeof(int), 1, fid);
    id_num[0] = idbuffer;
    if(idbuffer == 0) {
        save_employee();
    }
    return idbuffer;
    fclose(fid);
}

int rand_num_mod70(int lotto_array) {
    lotto_array = rand() % 70;
    while(lotto_array == 0) { 
        lotto_array = rand() % 70;
    } 
    return lotto_array;
}
int rand_num_mod11(int lotto_array) {
    lotto_array = rand() % 11;
    while(lotto_array == 0) { 
        lotto_array = rand() % 11;
    } 
    return lotto_array;
}
int get_rad_num(int lotto_array[7]) {

    for(int j = 0; j < 7; j++) {
        if(j < 6){
            lotto_array[j] = rand_num_mod70(lotto_array[j]);
        } else if (j = 6) {
            lotto_array[6] = rand_num_mod11(lotto_array[6]);
        }
    }
    return lotto_array[7];
}
int array_swap(int lotto_array[7]) {
    int tmp = 0;
    for(int j = 0; j < 6 ;j++) {
        for(int arr_lotto = j; arr_lotto < 6; arr_lotto++) {
            if (lotto_array[j] > lotto_array[arr_lotto]) {
                tmp = lotto_array[j];
                lotto_array[j] = lotto_array[arr_lotto];
                lotto_array[arr_lotto] = tmp;
            }
        }
    }
    return lotto_array[7];
}
int array_rerandom(int lotto_array[7]) {
    for (int j = 0; j < 6; j++) {
        for(int z =0 ; z < 6; z++){
            while ((lotto_array[j] == lotto_array[z] && j != z) || 
                    lotto_array[j] == lotto_array[6]) {
                lotto_array[j] = rand_num_mod70(lotto_array[j]);
            }
        }
    }
    return lotto_array[7];
}
int print_array (int lotto_array[7], FILE*fp) {
    for(int j = 0 ; j < 7 ; j++) {
        fprintf(fp, "%.2d ", lotto_array[j]);
    }
    fprintf(fp, "\n");
}
int print_last(int num_row, FILE*fp, int id_numx) {
    for(int i = num_row+1; i < 6; i++) {
        fprintf(fp,"[%d]: " , i);
        for(int j = 0; j < 7; j++) {
            fprintf(fp, "-- ");
            j == 6 ? fprintf(fp,"\n") : 1;
        }
    }
    fprintf(fp, "======== Op.%.5d =========\n", id_numx);
    fprintf(fp, "======== csie@CGU =========\n");
}
void record (int sell_num, int id_numx, int row_num) {
    FILE* rec;
    time_t now = time(0);
    typerecord record;
    record.lotto_no = sell_num;
    record.lotto_receipt = ((sell_num*50)+(row_num * 50))*1.1;
    record.emp_id = id_numx;
    typerecord lotto_record_t;
    strftime(record.lotto_date, 100,"%Y%m%d-",localtime(&now));
    strftime(record.lotto_time, 100,"%H:%M:%S",localtime(&now));
    rec = fopen("records.bin","ab+");
    fwrite(&record, sizeof(record), 1, rec);
    fclose(rec);
}

int main() {
    FILE* fp;
    FILE* fr;
    int sell_num[1]= {1}, sell_numpluse[1]= {1};
    int id_numx;
    id_numx = save_idfile();
        if((fr = fopen("a.bin", "r")) == NULL) {
            fr = fopen("a.bin", "wb");
            fwrite(sell_num, sizeof(int), 1, fr);
        } else {
            fr = fopen("a.bin", "rb");
            fread(sell_num, sizeof(int), 1, fr);
            fseek(fr, 0, SEEK_SET);
            fclose(fr);
            fr = fopen("a.bin", "wb+");
            sell_numpluse[0] = sell_num[0] +1;
            fwrite(sell_numpluse, sizeof(int), 1, fr);
        }
    int n =  snprintf(NULL, 0, "lotto[%05d].txt",sell_numpluse[0]);
    char s1[n+1];
    snprintf(s1, sizeof(s1), "lotto[%05d].txt",sell_numpluse[0]);
    fp = fopen(s1, "w+"); 
    fclose(fr);
    int row_num;
    printf("請輸入要購買的組數:");
    scanf("%d",&row_num);
    time_t curtime;
    time(&curtime);
    fprintf(fp, "======== lotto649 =========\n");
    fprintf(fp, "=======+ No. %05d +=======\n= %.24s=\n",  sell_numpluse[0], ctime(&curtime));
    srand((unsigned) curtime);
    if (row_num <= 5) {
        for (int i = 1; i <= row_num; i++) {
            int lotto_array[8] = {0};
            get_rad_num(lotto_array);
            fprintf(fp, "[%d]: ", i);
            lotto_array[8] = array_rerandom(lotto_array);
            lotto_array[8] = array_swap(lotto_array);
            print_array(lotto_array, fp);
        }
    } else {
        for (int i = 1; i <= 5; i++) {
            int lotto_array[8] = {0};
            get_rad_num(lotto_array);
            fprintf(fp, "[%d]: ", i);
            lotto_array[8] = array_rerandom(lotto_array);
            lotto_array[8] = array_swap(lotto_array);
            print_array(lotto_array, fp);
        }
    }
    print_last(row_num, fp, id_numx);
    fclose(fp);
    record(sell_numpluse[0], id_numx, row_num);

    return 0;
}