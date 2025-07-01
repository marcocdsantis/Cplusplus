#include <iostream>
#define verde "\033[32m";
#define vermelho "\033[31m";
#define corPadrao "\033[m"
using namespace std;

//declaração das funções
bool avaliacao(int valor);
int cruzPontoUnico(int valor, int valor2);
int cruzAritmetico(int valor, int valor2);
int mutacSimples(int valor);
int mutacDupla(int valor);

int main() {
	system("chcp 1252 > nul");
	unsigned short mochila; //criacao da mochila
	unsigned short sol1, sol2, sol3, sol4, sol5, sol6; //solucoes iniciais
	unsigned short resultCruzPontoUnico, resultCruzAritmetico, resultMutacSimples,resultMutacDupla;
	cout << "Entre com 6 soluções iniciais: (de 0 a 65535):" << endl;
	cin >> sol1 >> sol2 >> sol3 >> sol4 >> sol5 >> sol6;
	resultCruzPontoUnico = cruzPontoUnico(sol1, sol2);//chamada das funções
	resultCruzAritmetico = cruzAritmetico(sol3, sol4);
	resultMutacSimples = mutacSimples(sol5);
	resultMutacDupla = mutacDupla(sol6);
	cout << endl;
	mochila = avaliacao(sol1);
	mochila = avaliacao(sol2);
	mochila = avaliacao(sol3);
	mochila = avaliacao(sol4);
	mochila = avaliacao(sol5);
	mochila = avaliacao(sol6);
	cout << "------------------------------------------";
	mochila = avaliacao(resultCruzPontoUnico);
	mochila = avaliacao(resultCruzAritmetico);
	mochila = avaliacao(resultMutacSimples);
	mochila = avaliacao(resultMutacDupla);
}

//definicao das funções
bool avaliacao(int num) {//exibe valor e peso da solução
	cout << endl;
	unsigned short mask = 1;
	int peso = 0, valor = 0;
	for (int i = 15; i >= 0; i--) {
		if (num & mask) {
			switch (i) {
			case 0:
				peso += 12;
				valor += 4;
				break;
			case 1:
				peso += 3;
				valor += 4;
				break;
			case 2:
				peso += 5;
				valor += 8;
				break;
			case 3:
				peso += 4;
				valor += 10;
				break;
			case 4:
				peso += 9;
				valor += 15;
				break;
			case 5:
				peso += 1;
				valor += 3;
				break;
			case 6:
				peso += 2;
				valor += 1;
				break;
			case 7:
				peso += 3;
				valor += 1;
				break;
			case 8:
				peso += 4;
				valor += 2;
				break;
			case 9:
				peso += 1;
				valor += 10;
				break;
			case 10:
				peso += 2;
				valor += 20;
				break;
			case 11:
				peso += 4;
				valor += 15;
				break;
			case 12:
				peso += 5;
				valor += 10;
				break;
			case 13:
				peso += 2;
				valor += 3;
				break;
			case 14:
				peso += 4;
				valor += 4;
				break;
			case 15:
				peso += 1;
				valor += 12;
				break;
			default:
				break;
			}
		}
		mask = mask << 1;
	}
	cout << num << " - R$" << valor << " - " << peso << "Kg - ";
	if (peso > 20){//se extrapolar o peso da mochila
		cout << vermelho; cout << "X" << corPadrao << endl;
		return 0;//false
	}
	else{
		cout << verde; cout << "OK" << corPadrao << endl;
		return 1;//true
	}
}

int cruzPontoUnico(int valor, int valor2){
	unsigned short maskEsq = 65280, maskDir = 255, resultEsq, resultDir;
	resultEsq = maskEsq & valor;//comparação com os 8 bits da esquerda
	resultDir = maskDir & valor2;//comparacao com os 8 bits da direita
	return resultEsq + resultDir;
}

int cruzAritmetico(int valor, int valor2){
	unsigned short result;
	result = valor & valor2;
	return result;
}


int mutacSimples(int valor){
	unsigned short result, mask = ~(1 << 9);
	if (valor & ~mask) //verdadeiro se a pos 9 de valor for = 1
		result = valor & mask;//inverte se for 1
	else 
		result = valor | ~mask;//inverte se for 0
	return result;
}

int mutacDupla(int valor){

	unsigned short result, mask = (1 << 12); //0001000000000000
	if (valor & mask) //verdadeiro se a pos 12 de valor for = 1
		result = valor & ~mask;//inverte se for 1
	else
		result = valor | mask;//inverte se for 0*/

	mask = (1 << 3); //0000000000001000
	if (result & mask) //verdadeiro se a pos 3 de result for = 1
		result = result & ~mask;//inverte se for 1
	else
		result = result | mask;//inverte se for 0*/

	return result;
}
