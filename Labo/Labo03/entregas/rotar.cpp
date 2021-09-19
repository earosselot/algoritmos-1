#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> rotar(vector<int> v, int k){
	// Dado un vector v y un entero k, rotar k posiciones los elementos de v.
	// [1,2,3,4,5,6] rotado 2, deberia dar [3,4,5,6,1,2].
	vector<int> res(v.size());
	int size = v.size();

  // normalizo k, para que este en el rango [0, v.size()]
  if (size < k) {
    cout << "rotacion mas grande que size" << endl;
    k = k % size;
  }
  if (k < 0) {
    cout << "rotacion negativa" << endl;
    k = abs(abs(k % size) - size);
  }
	
	// algoritmo que rota si k esta en el rango [0, v.size()]
	for (int i = 0; i < size; i++) {
	  if (i-k < 0) {
	    res[i-k+size] = v[i]; 
	  } else {
	    res[i-k] = v[i];
	  }
	}
	
	return res;
}

int main() {
    /* No hace falta modificar el main */
    // Leo las entradas
    int n; //Longitud del vector a rotar
    cin >> n;
    int i = 0;
    int x;
    vector<int> v;// En v leo el vector
    while (i<n){
        cin >> x;
        v.push_back(x);
        i++;
    }
    
    int k; // La cantidad que tengo que rotar la guardo en k
    cin >> k;
    
    // Hago la rotacion
    vector<int> res = rotar(v,k);
    i = 0;
    
    // Imprimo el vector resultado
    while (i < res.size()){
        cout << res[i] << " ";
        i++;
    }

    return 0;
}
