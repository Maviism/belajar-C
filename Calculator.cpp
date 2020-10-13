#include <iostream>
using namespace std;

int main(){
	
	
	char user;
	int a;
	int b;
	int hasil;
	
	
	cout<<"====Calculator Sederhana===="<<endl;
	
	cout<<"1. + \n2. - \n3. x \n4. / \n5. % (modulo) \npilih operasi  : ";
	cin>>user;
	cout<<"Masukan Angka  : ";
	cin>>a;
	cout<<"Masukan Angka2 :";
	cin>>b;
	
	
	if (user == '+'){
		hasil = a + b;
	} else if(user == '-'){
		hasil = a - b;
	} else if(user == 'x'){
		hasil = a * b;
	} else if(user == '/'){
		hasil = a / b;
	} else if(user == '%'){
		hasil = a % b;
	} else {
		cout<<"Error : Try Again"<<endl;
	} 
	
	cout<<"Hasil : "<<hasil;
	
	
	
	
	
	return 0;
}
