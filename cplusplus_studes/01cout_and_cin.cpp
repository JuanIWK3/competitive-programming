#include <iostream>



using namespace std;

int main()
{
	int value;
	string value2, value3 = "";
	cout << "Hello, world!" << endl;
	cout << "Impression test \n";
	cout << "\tTab for this" << endl;
	
	cin >> value;
	cin.ignore(); // necessário para limpar o buffer e não bugar a entrada
	
	for(int i = 0; i < value; i++)
	{
		getline(cin, value2); // le entradas com espaços	
		cout << value2 << endl;	
	}
	
	// ler varias variaveis
	int a, b, c;
	cin >> a >> b >> c;
	cout << a << b << c << endl;

	// ler quantidade limitada	
	cin.ignore();
	char entradas[9];
	cin.getline(entradas, 3); // lerá e armazenará 2 strings,apenas
	cout << entradas;

	return 0;
}
