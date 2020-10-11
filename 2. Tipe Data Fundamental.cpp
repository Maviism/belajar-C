#include <iostream>
#include <limits>

using namespace std;

int main(){
	
	cout<<"==Tipe data fundamental=="<<endl;
	
	
	int i;
	int a; //4 Bytes
	long b; //4 Bytes
	short c; //2 Bytes
	double d; //8 Bytes
	float e; //4 Bytes
	char f; //1 Byte
	string nilai = " Bytes";
	string maks = " Nilai maksimum";
	
	for (i = 0; i<6;){
	cout<<"1. Int \n2. Long \n3. Short \n4. Double \n5. Float \n6. Char \n7. Selesai \n";
	cout<<"Masukan Angka : ";
	cin >> i ;
	
	if (i == 1){
		cout<<sizeof(a);
		cout<<nilai<< endl;
		cout<< numeric_limits<int>::max();
		cout<< maks<<endl;
	} else if(i == 2){
		cout<<sizeof(b);
		cout<<nilai<< endl;
		cout<< numeric_limits<long>::max();
		cout<< maks<<endl;
	} else if(i == 3){
		cout<<sizeof(c);
		cout<<nilai<< endl;
		cout<< numeric_limits<short>::max();
		cout<< maks<<endl;
	} else if(i == 4){
		cout<<sizeof(d);
		cout<<nilai<< endl;
		cout<< numeric_limits<double>::max();
		cout<< maks<<endl;
	} else if(i == 5){
		cout<<sizeof(e);
		cout<<nilai<< endl;
		cout<< numeric_limits<float>::max();
		cout<< maks<<endl;
	} else if(i == 6){
		cout<<sizeof(f);
		cout<<" Byte"<< endl;
	} else{
		cout<<"Masukan angka : "<<endl;
	}
	

	//cout<<" Byte"<< endl;
	
}
	cin.get();
	
	
	return 0;
}
