#include<iostream>
#include<string>
#include<time.h>
#include<cstdlib>

using namespace std;

string Bin(int value)
{
    string result;
    
    while ( value != 0 ){
    	if (value % 2 == 0 ) result = "0" + result;
		else result = "1" + result;
 	value /= 2;
	}
	
    return result;
}

int Dec(string value)
{
    int result;
	int pow = 1;
	
    for ( int i = value.length() - 1; i >= 0; --i, pow <<= 1 ) {
        result += ( value[i] - '0' ) * pow;
    }

    return result;
}
 
string XOR( string value1, string value2 )
{
	string result;
	int length = value1.size();
 
	for( int i = 0; i < length; i++ ){
		if(value1[i] == value2[i]) result+="0";
  		else result+="1";
  	}
  	
 return result;
}
 
 
 
int main()
{
	string passwordBin;
	string key1;
	string key2;
 
	int modulo;
	int password;
 
	cout << "Liczba do zaszyfrowania: ";
	cin  >> password;
	passwordBin = Bin(password); 
	int c = passwordBin.size();

	for (int i=0;i<c;i++)
	{  
		modulo = rand() % 2;    
		string tmp;
		sprintf( ( char* ) tmp.c_str(), "%d", modulo );
		key1 = tmp.c_str() + key1;
	}	

	key2 = XOR( passwordBin, key1 );
	
	cout <<endl<<endl;
	
	cout <<"Password: " << passwordBin << endl;
	cout <<"   Key 1: "    << key1        << endl;
	cout <<"   Key 2: "    << key2        << endl;
	
	cout <<endl<<endl;
	
	string decryption = XOR( key1, key2 );
	cout<<"Decryption password : " << Dec( decryption )<<endl<<endl;

 
return 0;
}
