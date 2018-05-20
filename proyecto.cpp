#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>

using namespace std;

class sopaLetra{
	private:
		int numFil;
		int numCol;
	public:
		sopaLetra(int numFil, int numCol);
		vector<vector<char> > generarMtz(vector<string> textos);
		char generadorLetraA();
		vector<string> randPal(vector<string> textos);
		string devuelvePal(string palabra);
		vector<string> repetidas(vector<string> textos);
};
  			/*CONSTRUCTOR*/

sopaLetra::sopaLetra(int _numFil, int _numCol){
	numFil = _numFil;
	numCol = _numCol;
}

vector<vector<char> > sopaLetra::generarMtz(vector<string> textos){
	vector<vector<char> > mtz;
	for(int i = 0; i < numFil; i++){
		mtz.push_back(vector<char>());
		for(int j = 0; j < numCol; j++){
			mtz[i].push_back(textos[i][j]); //falta organizarlo de acuerdo a los sentidos
		}
	}

	for(int i = 0; i < numFil; i++){
		cout << endl;
		for(int j = 0; j < numCol; j++){
			if(mtz[i][j] == NULL)
				mtz[i][j] = rand()%'A'+'Z';
			cout << "|"<<mtz[i][j] << "|"<<' ';
		}
	}
	cout << endl;
	return mtz;
}

vector<string> sopaLetra::randPal(vector<string> textos){
	vector<string> aux = textos;
	vector<string> temp;
	vector<int> tempo;
	int tam = textos.size();
	for(int i = 1; i <= tam; i++){
		tempo.push_back(i);
	}
		for(int i = 0; i < tam; i++){
			int al = rand() % tam;

			if(al == tempo[i]){
				cout << "hi";
				tempo.erase(tempo.begin() + i-1);
				temp.push_back(aux[al]);
				aux.erase(aux.begin() + (al-1));
			}
			/*if(al == 0 && tempo[i] == 0){
				tempo.erase(tempo.begin());
				aux.erase(aux.begin());
			}*/	
		}
	for(int i = 0; i < aux.size(); i++){
		cout << aux[i]<<endl;
	}

	return temp;	
}


string sopaLetra::devuelvePal(string palabra){
	int cant = palabra.size();
	string nuevo;
	for(int i = 0; i < cant; i++){
		nuevo.push_back(palabra[i]);
	}
	return nuevo;
}
vector<string> sopaLetra::repetidas(std::vector<string> textos){
	string word;
	for (int j = 0; j < textos.size(); j++){
		word = textos[j];
		for (int i = 1; i < textos.size(); i++){
			if(word == textos[i])
				textos.erase(textos.begin() + i);	
		}
	}	
	return textos;
}


int main(){ 
	ifstream archivo;
	string text;
	vector<string> textos;
	archivo.open("Frutas.txt", ios::in);
	if(archivo.fail()){
		cout<< "No se encontro"<< endl;
		exit(1);
	}
	while(!archivo.eof()){
		getline(archivo,text);
		string hola;
		for(int i = 0; i < text.size(); i++){
			if(text[i] != ' '){
				hola.push_back(text[i]);
			}
			else{
				hola.push_back(text[i+=1]);
			}
		}
	
		textos.push_back(hola);
		
	}

		/*for(int i = 0; i < textos.size(); i++){
			cout << textos[i] << endl;
		}*/
	archivo.close();
	sopaLetra soup(25,16);

	//vector<vector<char> > mtz = //
	soup.generarMtz(soup.repetidas(textos));
	

	vector<string> palabras = soup.randPal(soup.repetidas(textos));
	/*for(int i = 0; i < palabras.size(); i++){
		cout << palabras[i] << endl;
	}*/
	//hola.randPal(palabras);
	return 0;
}
