#include <iostream>

//sem usar o using
void f1e02a() {
	std::cout << "Nome: " << std::endl;
	char nome[50];
	std::cin >> nome;

	std::cout << "Idade: " << std::endl;
	int idade;
	std::cin >> idade;

	std::cout << nome << " tem " << idade << std::endl;
}

//normalmente feito no início do ficheiro
//using std::cout;
//using std::cin;
//using std::endl;
using namespace std;
void exemplo1() {
	cout << "Nome: " << endl;
	char nome[5];
	cin >> nome;

	cout << "Idade: " << endl;
	int idade;
	cin >> idade;

	cout << nome << " tem " << idade << endl;
}

void exemplo2() {
	string s1;
	cout << s1 << endl;
	string s2 = s1;
	cout << s2 << endl;
	string s3 = "Bom dia!!";
	cout << s3 << endl;
	string s4(10, 'c');
	cout << s4 << endl;
}

void f1e03a() {
	std::cout << "Nome: " << std::endl;
	string nome;
	std::cin >> nome;
	nome = "Genoveva";
	std::cout << nome;

	std::cout << "Idade: " << std::endl;
	int idade;
	std::cin >> idade;

	std::cout << nome << " tem " << idade << std::endl;
}

void exemplo3() {
	string s1, s2;
	cin >> s1 >> s2;
	if (s1 == s2)
		cout << " as strings sao iguais" << endl;
	else
		if (s1 < s2)	//comparação alfabética
			cout << s1 << " e mais pequena que " << s2 << endl;
		else
			cout << s2 << " e mais pequena que " << s1 << endl;
}

void exemplo4() {
	string palavra = "julieta";
	for (char letra : palavra)
		cout << letra << endl;
}

//deve ser feito no início do ficheiro
#include <string>
void exemplo5() {
	string frase;
	getline(cin, frase);
	for (char letra : frase)
		cout << letra << endl;
}
void exemplo6() {
	cout << "Nome: " << endl;
	string nome;
	getline(cin, nome);

	cout << "Idade: " << endl;
	int idade;
	cin >> idade;

	cout << nome << " tem " << idade << endl;
}


int main()
{
	exemplo6();
	//exemplo5();
	//exemplo4();
	//exemplo3();
	//f1e03a();
	//exemplo2();
	//exemplo1();
	//f1e02a();
	return 0;
}
