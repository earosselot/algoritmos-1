#include "ejercicios.h"


// Ejercicio 1
bool existePico(vector<int> v){
	int i = 0;
	bool res = false;
	while (i < v.size() - 1)
	{
		if (v[i] > v[i + 1] && v[i] > v[i - 1])
		{
			res = true;
		}
		i++;
	}
	return res;
}

// Ejercicio 2
int mcd(int m, int n){
	int a = m;
	int b = n;
	int resto = 1;
	while (b != 0)
	{
		resto = a % b;
		a = b;
		b = resto;
	}
	if (resto == 0)
	{
		return a;
	}
}

// Ejercicio 3
int indiceMinSubsec(vector<int> v, int l, int r){
	int i = r;
	int res = r;
	while (i >= l)
	{
		if (v[i] < v[res])
		{
			res = i;
		}
		i--;
	}
	return res;
}

// Ejercicio 4
void ordenar1(vector<int>& v){
	int indiceMinimo;
	for (int i = 0; i < v.size(); i++)
	{
		indiceMinimo = indiceMinSubsec(v, i, v.size() - 1);
		swap(v[i], v[indiceMinimo]);
	}
	return;
}

// Ejercicio 5
void ordenar2(vector<int>& v){
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			for (int k = 0; k < v.size(); k++)
			{
						}
		}
	}
	return;
}

// Ejercicio 6
tuple<int,int> division(int n, int d){
	return make_tuple(0,0);
}
