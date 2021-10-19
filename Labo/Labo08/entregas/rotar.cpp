#include <iostream>
#include <string>

using namespace std;

string rotar(string s, int v){
	int size = s.size();
	string rotada;
	int indice;
	for (int i = 0; i < s.size(); i++)
	{
		indice = (size - (v % size) + i) % size;
		rotada.push_back(s[indice]);
	}
	return rotada;
}

int main()
{
    /* No hace falta modificar el main */
    // Leo la entrada
    string s;
    int j;
    cin >> s >> j;
    
    string res = rotar(s, j);
    cout << res;
    return 0;
}
