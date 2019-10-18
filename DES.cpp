#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <limits.h>
using namespace std;

int hexStringToInt(string hex)
{
    int decimal, place;
    int val, len;

    decimal = 0;
    place = 1;

    // Find the length of total number of hex digit
    len = hex.length()-1;

    //Iterate over each hex digit
    for(int i=0; hex[i]!='\0'; i++)
    {

        // Find the decimal representation of hex[i]
        if(hex[i]>='0' && hex[i]<='9')
        {
            val = hex[i] - 48;
        }
        else if(hex[i]>='a' && hex[i]<='f')
        {
            val = hex[i] - 97 + 10;
        }
        else if(hex[i]>='A' && hex[i]<='F')
        {
            val = hex[i] - 65 + 10;
        }

        decimal += val * pow(16, len);
        len--;
    }

    return decimal;
}
int binStringToInt(string binaryString) {
	int value = 0;
	int indexCounter = 0;
	for(int i = binaryString.length()-1; i >= 0; i--)
	{

      if(binaryString [i] == '1')
		{
        value += pow(2, indexCounter);
    	}
    indexCounter++;
	}
	return value;
}
string tex2bin(string input){
	string hasil="";
	for(int i=0;i<input.size();i++){
		int temp=(int)input[i];
		for(int j=0;j<8;j++){
			if(temp%2==1)hasil+='1';
			else hasil+='0';
			temp/=2;
		}
	}
	return hasil;
}
string bin2tex(string input){
	string hasil="";
	string pegang="";
	for(int i=input.size()-1;i>=0;i--){
		if(pegang.size()<8){
			pegang=input[i]+pegang;
			if(pegang.size()<8)continue;
		}
		int hitung=pegang[0]-'0'+(pegang[1]-'0')*2+(pegang[2]-'0')*4+(pegang[3]-'0')*8+(pegang[4]-'0')*16+(pegang[5]-'0')*32+(pegang[6]-'0')*64+(pegang[7]-'0')*128;
		hasil=(char)hitung+hasil;
		pegang.clear();
	}
	return hasil;
}

int main()
{
    char hexkey[64], binkey[64];
    int decimalkey;
    printf("Input Key (Hexadecimal): ");
    gets(hexkey);
    decimalkey = hexStringToInt(hexkey);
    itoa(decimalkey, binkey, 2);
    char pkey[56] = "0000000000000000000000000000000000000000000000000000000";
    pkey[0] = binkey[56]; pkey[1] = binkey[48]; pkey[2] = binkey[40]; pkey[3] = binkey[32]; pkey[4] = binkey[24]; pkey[5] = binkey[16]; pkey[6] = binkey[8];
    pkey[7] = binkey[0]; pkey[8] = binkey[57]; pkey[9] = binkey[49]; pkey[10] = binkey[41]; pkey[11] = binkey[33]; pkey[12] = binkey[25]; pkey[13] = binkey[17];
    pkey[14] = binkey[9]; pkey[15] = binkey[1]; pkey[16] = binkey[58]; pkey[17] = binkey[50]; pkey[18] = binkey[42]; pkey[19] = binkey[34]; pkey[20] = binkey[26];
    pkey[21] = binkey[18]; pkey[22] = binkey[10]; pkey[23] = binkey[2]; pkey[24] = binkey[59]; pkey[25] = binkey[51]; pkey[26] = binkey[43]; pkey[27] = binkey[35];
    pkey[28] = binkey[62]; pkey[29] = binkey[54]; pkey[30] = binkey[46]; pkey[31] = binkey[38]; pkey[32] = binkey[30]; pkey[33] = binkey[22]; pkey[34] = binkey[14];
    pkey[35] = binkey[6]; pkey[36] = binkey[61]; pkey[37] = binkey[53]; pkey[38] = binkey[45]; pkey[39] = binkey[37]; pkey[40] = binkey[29]; pkey[41] = binkey[21];
    pkey[42] = binkey[13]; pkey[43] = binkey[5]; pkey[44] = binkey[60]; pkey[45] = binkey[52]; pkey[46] = binkey[44]; pkey[47] = binkey[36]; pkey[48] = binkey[28];
    pkey[49] = binkey[20]; pkey[50] = binkey[12]; pkey[51] = binkey[4]; pkey[52] = binkey[27]; pkey[53] = binkey[19]; pkey[54] = binkey[11]; pkey[55] = binkey[3];
    char c[17][28], d[17][28];
    for(int i = 0; i < 28; i++){
        c[0][i] = pkey[i];
        d[0][i] = pkey[i+28];
    }
    int shift[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
    for(int i = 0; i < 16; i++){
        for(int j = shift[i]; j > 0; j--){
            for(int k = 0; k < 28 ; k++){
                c[i+1][k] = c[i][(k+1)%28];
            }
        }
    }
    char k[16][48];
    for(int i = 0; i < 16; i++){
        k[i][0] = c[i][13]; k[i][1] = c[i][16]; k[i][2] = c[i][10]; k[i][3] = c[i][23]; k[i][4] = c[i][0]; k[i][5] = c[i][4];
        k[i][6] = c[i][2]; k[i][7] = c[i][27]; k[i][8] = c[i][14]; k[i][9] = c[i][5]; k[i][10] = c[i][20]; k[i][11] = c[i][9];
        k[i][12] = c[i][22]; k[i][13] = c[i][18]; k[i][14] = c[i][11]; k[i][15] = c[i][3]; k[i][16] = c[i][25]; k[i][17] = c[i][7];
        k[i][18] = c[i][15]; k[i][19] = c[i][6]; k[i][20] = c[i][26]; k[i][21] = c[i][19]; k[i][22] = c[i][12]; k[i][23] = c[i][1];
        k[i][24] = d[i][12]; k[i][25] = d[i][23]; k[i][26] = d[i][2]; k[i][27] = d[i][8]; k[i][28] = d[i][18]; k[i][29] = d[i][26];
        k[i][30] = d[i][1]; k[i][31] = d[i][11]; k[i][32] = d[i][22]; k[i][33] = d[i][16]; k[i][34] = d[i][4]; k[i][35] = d[i][19];
        k[i][36] = d[i][15]; k[i][37] = d[i][20]; k[i][38] = d[i][10]; k[i][39] = d[i][27]; k[i][40] = d[i][5]; k[i][41] = d[i][24];
        k[i][42] = d[i][17]; k[i][43] = d[i][13]; k[i][44] = d[i][21]; k[i][45] = d[i][7]; k[i][46] = d[i][0]; k[i][47] = d[i][3];
    }
    char plaintext[10000000], ciphertext[10000000];
    printf("Input Plaintext: ");
    gets(plaintext);
    sprintf(plaintext, "%s", tex2bin(plaintext));
    int ptlen = strlen(plaintext);
    if(ptlen % 64 != 0){
        strcat(plaintext, "0");
    }
    int iter = ceil(ptlen / 64);
    for(int i = 0; i < iter; i++){
        char m[64];
        m[0] = plaintext[i*64];
        for(int j = 1; j < 64; j++){
            char temp[1] = {plaintext[i*64+j]};
            strcat(m, temp);
        }
        char ip[64]="00000000000000000000000000000000000000000000000000000000";
        ip[0] = m[57]; ip[1] = m[49]; ip[2] = m[41]; ip[3] = m[33]; ip[4] = m[25]; ip[5] = m[17]; ip[6] = m[9]; ip[7] = m[1];
        ip[8] = m[59]; ip[9] = m[51]; ip[10] = m[43]; ip[11] = m[35]; ip[12] = m[27]; ip[13] = m[19]; ip[14] = m[11]; ip[15] = m[3];
        ip[16] = m[61]; ip[17] = m[53]; ip[18] = m[45]; ip[19] = m[37]; ip[20] = m[29]; ip[21] = m[21]; ip[22] = m[13]; ip[23] = m[5];
        ip[24] = m[63]; ip[25] = m[55]; ip[26] = m[47]; ip[27] = m[39]; ip[28] = m[31]; ip[29] = m[23]; ip[30] = m[15]; ip[31] = m[7];
        ip[32] = m[56]; ip[33] = m[48]; ip[34] = m[40]; ip[35] = m[32]; ip[36] = m[24]; ip[37] = m[16]; ip[38] = m[8]; ip[39] = m[0];
        ip[40] = m[58]; ip[41] = m[50]; ip[42] = m[42]; ip[43] = m[34]; ip[44] = m[26]; ip[45] = m[18]; ip[46] = m[10]; ip[47] = m[2];
        ip[48] = m[60]; ip[49] = m[52]; ip[50] = m[44]; ip[51] = m[36]; ip[52] = m[28]; ip[53] = m[20]; ip[54] = m[12]; ip[55] = m[4];
        ip[56] = m[62]; ip[57] = m[54]; ip[58] = m[46]; ip[59] = m[38]; ip[60] = m[30]; ip[61] = m[22]; ip[62] = m[14]; ip[63] = m[6];
        char l[17][32], r[17][32];
        for(int j = 0; j < 32; j++){
            l[0][j] = pkey[j];
            r[0][j] = pkey[j+32];
        }
        for(int j = 1; j <= 16; j++){
            sprintf(l[j], "%s", r[j-1]);
            int ltemp = binStringToInt(l[j-1]);
            int key = binStringToInt(k[j]);
            int rtemp = binStringToInt(r[j-1]);
            unsigned long long func = (key * rtemp + 1000) / key + key;
            while(func > UINT_MAX){
                func /= 32;
            }
            itoa(ltemp^func,r[j],2);
        }
        char reverseip[64] = "00000000000000000000000000000000000000000000000000000000";
        reverseip[0] = r[16][7]; reverseip[1] = l[16][7]; reverseip[2] = r[16][15]; reverseip[3] = l[16][15]; reverseip[4] = r[16][23]; reverseip[5] = l[16][23]; reverseip[6] = r[16][31]; reverseip[7] = l[16][31];
        reverseip[8] = r[16][6]; reverseip[9] = l[16][6]; reverseip[10] = r[16][14]; reverseip[11] = l[16][14]; reverseip[12] = r[16][22]; reverseip[13] = l[16][22]; reverseip[14] = r[16][30]; reverseip[15] = l[16][30];
        reverseip[16] = r[16][5]; reverseip[17] = l[16][5]; reverseip[18] = r[16][13]; reverseip[19] = l[16][13]; reverseip[20] = r[16][21]; reverseip[21] = l[16][21]; reverseip[22] = r[16][29]; reverseip[23] = l[16][29];
        reverseip[24] = r[16][4]; reverseip[25] = l[16][4]; reverseip[26] = r[16][12]; reverseip[27] = l[16][12]; reverseip[28] = r[16][20]; reverseip[29] = l[16][20]; reverseip[30] = r[16][28]; reverseip[31] = l[16][28];
        reverseip[32] = r[16][3]; reverseip[33] = l[16][3]; reverseip[34] = r[16][11]; reverseip[35] = l[16][11]; reverseip[36] = r[16][19]; reverseip[37] = l[16][19]; reverseip[38] = r[16][27]; reverseip[39] = l[16][27];
        reverseip[40] = r[16][2]; reverseip[41] = l[16][2]; reverseip[42] = r[16][10]; reverseip[43] = l[16][10]; reverseip[44] = r[16][18]; reverseip[45] = l[16][18]; reverseip[46] = r[16][26]; reverseip[47] = l[16][26];
        reverseip[48] = r[16][1]; reverseip[49] = l[16][1]; reverseip[50] = r[16][9]; reverseip[51] = l[16][9]; reverseip[52] = r[16][17]; reverseip[53] = l[16][17]; reverseip[54] = r[16][25]; reverseip[55] = l[16][25];
        reverseip[56] = r[16][0]; reverseip[57] = l[16][0]; reverseip[58] = r[16][8]; reverseip[59] = l[16][8]; reverseip[60] = r[16][16]; reverseip[61] = l[16][16]; reverseip[62] = r[16][24]; reverseip[63] = l[16][24];
        if(i == 0) sprintf(ciphertext, "%s", reverseip);
        else strcat(ciphertext, reverseip);
    }
    sprintf(ciphertext, "%s", bin2tex(ciphertext));
    printf("Ciphertext: %s", ciphertext);
    return 0;
}
