#include<bits/stdc++.h>
using namespace std;

string tex2bin(string input){
	string hasil="";
	for(int i=0;i<input.size();i++){
		int temp=(int)input[i];
		while(temp>0){
			if(temp%2==1)hasil+='1';
			else hasil+='0';
			temp/=2;
		}
	}
	return hasil;
}

string bin2tex(string input){
	
}
string bin2hex(string input){
	
}
string hex2bin(string input){
	string hasil="";
	for(int i=0;i<input.size();i++){
		int temp
		if(input[i]=='A')temp=10;
		else if(input[i]=='B')temp=11;
		else if(input[i]=='C')temp=12;
		else if(input[i]=='D')temp=13;
		else if(input[i]=='E')temp=14;
		else if(input[i]=='F')temp=15;
		else temp=(int)input[i]-'0';		
		while(temp>0){
			if(temp%2==1)hasil+='1';
			else hasil+='0';
			temp/=2;
		}
	}
	return hasil;
}

int main(){
	
}
