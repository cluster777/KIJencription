#include<bits/stdc++.h>
using namespace std;
int main(){
	//create table
	int lokasi[25];
	char temp[5][5];
	for(int i=0;i<25;i++)lokasi[i]=i;
	string key;
	cin>>key;
	//tidak berulang
	int i;
	for(i=0;i<key.size();i++){
		temp[i/5][i%5]=key[i];
	}
	char huruf='A';
	while(i<25){
		while(chk(huruf)){//sudah ada
		huruf++;
		}
		temp[i/5][i%5]=huruf;
		huruf++;
		i++;
	}
	for(i=0;i<25;i++){
		lokasi[temp[i/5][i%5]-'A']=i;
	}
	//udh jadi key
	char chr[2],tmp;
	int counter=0;
	string hasil;
	while(1){
		while(cin>>tmp && counter<2){
			if(tmp>='A'&& tmp<='Z'){
				chr[counter]=tmp;
				counter++;
			}
			else if(tmp>='a'&& tmp<='z'){
				chr[counter]=tmp-32;
				counter++;
			}
		}
		if(counter==0)break;
		if(counter==1)chr[1]='X';
		counter=0;
		//encrypt
		int pos[2],hsl[2];
		pos[0]=lokasi[chr[0]-'A'];
		pos[1]=lokasi[chr[1]-'A'];
		if(pos[0]/5==pos[1]/5){//kesamping
			hsl[0]=pos[0]-pos[0]%5+(pos[0]+1)%5;
			hsl[1]=pos[1]-pos[1]%5+(pos[1]+1)%5;
		}
		else if(pos[0]%5==pos[1]%5){//kebawah
			hsl[0]=pos[0]+5%25;
			hsl[1]=pos[1]+5%25;
		}
		else{//tukeran
			hsl[0]=pos[1]%5+pos[0]-pos[0]%5
			hsl[1]=pos[0]%5+pos[1]-pos[1]%5
		}
		hasil+=hsl[0];
		hasil+=hsl[1];
	}
}
