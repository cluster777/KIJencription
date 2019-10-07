#include<bits/stdc++.h>
using namespace std;

char temp[5][5];

bool chk(char huruf){
	for(int i=0;i<25;i++){
		if(temp=='\0')return false;
		if(temp[i]==huruf)return true;	
	}
}


int main(){
	//create table
	int lokasi[26];
	
	for(int i=0;i<25;i++)temp[i/5][i%5]='\0';
	string key;
	cout<<"inputkan key dalam capslock dan jangan ada huruf berulang>>";
	
	while(cin>>key){
		//jika tidak berulang
		bool arr[26],benar=false,salah=false;
		for(int i=0;i<key.size();i++){
			if(key[i]>='A'&& key[i]<='Z')
				if(arr[key[i]-'A']==false)arr[key[i]-'A']=true;
				else salah=true;
			else salah=true;//jika input tidak dikenal
			if(salah) break;
			if(i==key.size()-1)benar=true;
		}
		if(benar)break;
		cout<<"inputkan key dalam capslock dan jangan ada huruf berulang>>";
	}
	
	//tidak berulang
	int i;
	for(i=0;i<key.size();i++){
		temp[i/5][i%5]=key[i];
	}
	char huruf='A';
	while(i<26){
		while(chk(huruf)){//sudah ada
		huruf++;
		}
		temp[i/5][i%5]=huruf;
		huruf++;
		i++;
	}
	for(i=0;i<26;i++){
		lokasi[temp[i/5][i%5]-'A']=i;
	}
	//udh jadi key
	char chr[2],tmp;
	int counter=0;
	string hasil;
	while(1){
		if(tmp!='0'){
			counter=1;
			chr[0]=tmp;
		}
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
		tmp='0';
		if(counter==0)break;
		if(counter==1)chr[1]='X';
		if(chr[0]=='J')chr[0]='I';
		if(chr[1]=='J')chr[1]='I';
		if(counter==2 && chr[0]==chr[1]){
			tmp=chr[1];
			chr[1]='X';
		}
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
			hsl[0]=pos[1]%5+pos[0]-pos[0]%5;
			hsl[1]=pos[0]%5+pos[1]-pos[1]%5;
		}
		hasil+=hsl[0];
		hasil+=hsl[1];
	}
}
