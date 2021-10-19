#include <iostream>
#include <string>

using namespace std;

bool subsecuencia(string s, string t) {
    // Completar aca
}

int main()
{
    /* No hace falta modificar el main */
    // Leo la entrada
    string s, t;
    cin >> s >> t;
    
    bool res = subsecuencia(s, t);
    cout << (res ? "true" : "false");
    return 0;
}

