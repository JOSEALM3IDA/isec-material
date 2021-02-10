#include <iostream>
#include <sstream>

using namespace std;

class MSG {
    char letra;
    int num;

    static int contador;

    public:

    MSG(char c = 'x'): letra(c), num(contador++) {
        cout << "Construtor " << letra << " " << num << endl;
    }

    //MSG(const MSG& ref):letra(ref.letra), num(contador++) {
    //    cout << "CPC " << letra << " " << num << endl;
    //};

    MSG(const MSG& ref) = delete;

    ~MSG() {
        cout << "Destrutor " << letra << " " << num << endl;
    }

    string getAsString() const {
        ostringstream os;

        os << "Num: " << num << " Letra: " << letra << endl;

        return os.str();
    }

};

int MSG::contador = 1;

void ex7f2() {
    MSG a;
    MSG b('r');
    //MSG c = a;

    //MSG tab[2] = {'w', 'z'};

    //cout << a.getAsString() << endl;
    //cout << b.getAsString() << endl;
}











int main() {
    ex7f2();

    return 0;
}