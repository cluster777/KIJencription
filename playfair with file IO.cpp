#include<bits/stdc++.h>
#define ENCRIPT 1
#define DECRIPT 0

using namespace std;

char temp[5][5];
int lokJ;
bool chk(char huruf){
	
	if(huruf=='J')return true;
	for(int i=0;i<25;i++){
		if(temp[i/5][i%5]=='\0')return false;
		if(temp[i/5][i%5]==huruf)return true;	
	}
}


int main(){
	//create table
	int lokasi[25];
	bool stat;
	ifstream infile;
	ofstream outfile;
	infile.open("input.txt");
	outfile.open("output.txt");
	cout<<"inputkan metode yang digunakan (encript 1 decript 0)>>";
	cin>>stat;
	for(int i=0;i<25;i++)temp[i/5][i%5]='\0';
	string key;
	cout<<"inputkan key dalam capslock dan jangan ada huruf berulang (juga I/J)>>";
	
	while(cin>>key){
		//jika tidak berulang
		bool arr[26],benar=false,salah=false;
		for(int i=0;i<key.size();i++){
			if(key[i]>='A'&& key[i]<='Z')
				if(key[i]=='J')arr['I'-'A']=true;
				else if(arr[key[i]-'A']==false && key[i]!='J')arr[key[i]-'A']=true; 
				else salah=true;
			else salah=true;//jika input tidak dikenal
			if(salah) break;
			if(i==key.size()-1)benar=true;
		}
		if(benar)break;
		cout<<"inputkan key dalam capslock dan jangan ada huruf berulang (juga I/J)>>";
	}
	
	//tidak berulang
	int i;
	for(i=0;i<key.size();i++){
		temp[i/5][i%5]=key[i];
		
	}
	char huruf='A';
	while(i<25){
		while(chk(huruf)){//sudah ada
		if(huruf=='J')lokJ=i;
		huruf++;
		}
		temp[i/5][i%5]=huruf;
		huruf++;
		i++;
	}
	for(i=0;i<25;i++){
		cout<<temp[i/5][i%5];
		if(i%5==4)cout<<endl;
	}
	for(i=0;i<25;i++){
		if(temp[i/5][i%5]<'J')
			lokasi[temp[i/5][i%5]-'A']=i;
		else
			lokasi[temp[i/5][i%5]-'A'-1]=i;
	}
	/*for(i=0;i<25;i++){
		cout<<lokasi[i]<<" ";
		if(i%5==4)cout<<endl;
	}*/
	//udh jadi key
	char chr[2],tmp='0';
	int counter=0;
	string hasil;

	while(1){
		//ambil string sebanyak 2
		if(tmp!='0'){
			counter=1;
			chr[0]=tmp;
		}
		while(infile>>tmp){
			if(tmp>='A'&& tmp<='Z'){
				chr[counter]=tmp;
				counter++;
			}
			else if(tmp>='a'&& tmp<='z'){
				chr[counter]=tmp-32;
				counter++;
			}
			if(counter>=2)break;
		}
		//case utk setiap kejadiam
		tmp='0';
		//jika tidak ada input lagi EOF
		if(counter==0)break;
		//jika input hanya 1
		if(counter==1)chr[1]='X';
		//jika ketemu j atau J
		if(chr[0]=='J')chr[0]='I';
		if(chr[1]=='J')chr[1]='I';
		//jika hurufnya sama
		if(counter==2 && chr[0]==chr[1]){
			tmp=chr[1];
			chr[1]='X';
		}
		if(chr[0]>'J')chr[0]--;
		if(chr[1]>'J')chr[1]--;
		
		counter=0;
		//encrypt
		int pos[2],hsl[2];
		
		pos[0]=lokasi[chr[0]-'A'];
		pos[1]=lokasi[chr[1]-'A'];
		
		//cout<<pos[0]<<" "<<pos[1]<<endl;
		if(pos[0]/5==pos[1]/5 && stat==ENCRIPT){//kekanan
			hsl[0]=pos[0]-pos[0]%5+(pos[0]+1)%5;
			hsl[1]=pos[1]-pos[1]%5+(pos[1]+1)%5;
		}
		else if(pos[0]/5==pos[1]/5 && stat==DECRIPT){//kekiri
			hsl[0]=pos[0]-pos[0]%5+(pos[0]-1+5)%5;
			hsl[1]=pos[1]-pos[1]%5+(pos[1]-1+5)%5;
		}
		else if(pos[0]%5==pos[1]%5 && stat==ENCRIPT){//kebawah
			hsl[0]=pos[0]+5%25;
			hsl[1]=pos[1]+5%25;
		}
		else if(pos[0]%5==pos[1]%5 && stat==DECRIPT){//keatas
			hsl[0]=pos[0]-5+25%25;
			hsl[1]=pos[1]-5+25%25;
		}
		else{//tukeran
			hsl[0]=pos[1]%5+pos[0]-pos[0]%5;
			hsl[1]=pos[0]%5+pos[1]-pos[1]%5;
		}
		outfile<<temp[hsl[0]/5][hsl[0]%5];
		outfile<<temp[hsl[1]/5][hsl[1]%5];
	}
	outfile.close();
}
