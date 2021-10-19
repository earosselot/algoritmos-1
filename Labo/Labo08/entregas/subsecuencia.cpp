#include <iostream>
#include <string>

using namespace std;

bool subsecuencia(string s1, string s2) {
	int i = 0;
	int j = 0;
	while (i < s2.size() && j < s1.size()) 
	{
		if (s1[j] == s2[i]) {
			j = j + 1;
		}
		i = i + 1;
	}
	return j == s1.size();
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

