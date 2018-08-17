#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int Conv_Num(string valor){   
	int n = atoi(valor.c_str()); 
    return n; 
}
bool esNumero(string valor){
	if(Conv_Num(valor)==0){
		return true;
	}
	else{
		int aux = atoi(valor.c_str());
		if(aux==0){
			return false;
		}
		else{
			return true;
		}
	}
}
void Mostrar(int matriz[][9]){
	cout<<"Matriz"<<endl;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<matriz[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(int argc, char* argv[]){
	int matriz[9][9];
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			matriz[i][j]=0;

	string argumento=argv[1];
	string pos_i;
	string pos_j;
	string num;
	if (argumento.substr(0,1)=="[")
	{
		while(argumento!="")
		{
			pos_i=argumento.substr(1,1);
			pos_j=argumento.substr(3,1);
			num=argumento.substr(5,1);
			if(esNumero(pos_i) && esNumero(pos_j) && esNumero(num))
			{
				if(Conv_Num(pos_i)>=0 && Conv_Num(pos_i)<9)
				{
					if(Conv_Num(pos_j)>=0 && Conv_Num(pos_j)<9)
					{
						if(Conv_Num(num)>=1 && Conv_Num(num)<=9)
						{
							if (matriz[Conv_Num(pos_j)][Conv_Num(pos_i)]==0)
							{
								matriz[Conv_Num(pos_j)][Conv_Num(pos_i)]=Conv_Num(num);
							}
							else
							{
								cout<<"Dato ya ingresado en la posicion ("<<pos_i<<","<<pos_j<<")"<<endl;
							}
						}
						else
						{
							cout<<"Error de formato"<<endl;
						}
					}
					else
					{
						cout<<"Error de formato"<<endl;
					}
				}
				else
				{
					cout<<"Error de formato"<<endl;
				}
			}
			else
			{
				cout<<"Error de formato"<<endl;
			}
			argumento=argumento.substr(7);
		}
		cout<<endl;
		Mostrar(matriz);
	}
	else
	{
		cout<<"Error de formato"<<endl;
	}
}
