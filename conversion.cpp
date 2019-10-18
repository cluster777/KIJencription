#include<bits/stdc++.h>
using namespace std;

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
string bin2hex(string input){
	string hasil="";
	string pegang="";
	for(int i=input.size()-1;i>=0;i--){
		if(pegang.size()<4){
			pegang=input[i]+pegang;
			if(pegang.size()<4)continue;
		}
		int hitung=pegang[0]-'0'+(pegang[1]-'0')*2+(pegang[2]-'0')*4+(pegang[3]-'0')*8;
		if(hitung==10)hasil='A'+hasil;
		else if(hitung==11)hasil='B'+hasil;
		else if(hitung==12)hasil='C'+hasil;
		else if(hitung==13)hasil='D'+hasil;
		else if(hitung==14)hasil='E'+hasil;
		else if(hitung==15)hasil='F'+hasil;
		else hasil=(char)(hitung+'0')+hasil;
		pegang.clear();
	}
	return hasil;
}
string hex2bin(string input){
	string hasil="";
	for(int i=0;i<input.size();i++){
		int temp;
		if(input[i]=='A')temp=10;
		else if(input[i]=='B')temp=11;
		else if(input[i]=='C')temp=12;
		else if(input[i]=='D')temp=13;
		else if(input[i]=='E')temp=14;
		else if(input[i]=='F')temp=15;
		else temp=(int)input[i]-'0';		
		for(int j=0;j<4;j++){
			if(temp%2==1)hasil+='1';
			else hasil+='0';
			temp/=2;
		}
	}
	return hasil;
}

int main(){
	
}
