#include <vector>
#include <iostream>
// que es std ??
// comillas simples o dobles? en el video labo03-03 min 5 usa los dos.

using namespace std;

int main() {
  // vector<int> v;
  // v.push_back(1);
  // v.pop_back();
  // v.pop_back();
  // cout << "largo de v: " << v.size() << endl;
  // el largo se guarda en un lugar de memoria. cada vez q se llama a pop_back, se le resta 1.

  vector<vector<int>> mat(10, vector<int>(5, 5));
  cout << mat[2][2];


  return 0;
}
