#include<iostream>
#include<string>

using namespace std;

void szyfrCezara (string &txt, int key, int szyfruj)
{
	if (szyfruj == 1) key*=-1;
	
	if (key>=0)
	{
		for(int i=0;i<=txt.length();i++){
			if(txt[i]>=65 && txt[i]<=90-key%26) txt[i]=int(txt[i])+key%26; 
			else if(txt[i]>=91-key%26 && txt[i]<=90) txt[i]=int(txt[i])-26+key%26;
			else if(txt[i]>=97 && txt[i]<=122-key%26) txt[i]=int(txt[i])+key%26; 
			else if(txt[i]>=123-key%26 && txt[i]<=122) txt[i]=int(txt[i])-26+key%26; 
			else if(txt[i]>=48 && txt[i]<=57-key%10) txt[i]=int(txt[i])+key%10; 
			else if(txt[i]>=58-key%10 && txt[i]<=57) txt[i]=int(txt[i])-10+key%10; 
		}
	} else{
		for(int i=0;i<=txt.length();i++){
			if(txt[i]>=65-key%26 && txt[i]<=90) txt[i]=int(txt[i])+key%26; 
			else if(txt[i]>=65 && txt[i]<=65-key%26) txt[i]=int(txt[i])+26+key%26;
			else if(txt[i]>=97-key%26 && txt[i]<=122) txt[i]=int(txt[i])+key%26; 
			else if(txt[i]>=97 && txt[i]<=97-key%26) txt[i]=int(txt[i])+26+key%26;
			else if(txt[i]>=48-key%10 && txt[i]<=57) txt[i]=int(txt[i])+key%10; 
			else if(txt[i]>=48 && txt[i]<=48-key%10) txt[i]=int(txt[i])+10+key%10;
		}

	}	
}

int main()
{
	string txt; 
	int key;
	
	cout<<"Podaj zdanie: ";
	getline(cin,txt);
	cout<<"Podaj klucz: ";
	cin>>key;
	szyfrCezara(txt,key,0);
	
	cout<<"Zdanie po szyfrowaniu: "<<txt<<endl;
	szyfrCezara(txt,key,1);
	 cout<<"Zdanie po deszyfrowaniu: "<<txt<<endl;
	return 0;
}
