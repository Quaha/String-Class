#include "stdafx.h"
#include "String.h"

using namespace std;

void debug();

int main() {
    
    setlocale(LC_ALL, "RUS");

    debug();

}

void debug() {

    cout << "Конструкторы класса:\n";
    String S1;
    cout << S1.size() << " " << S1 << '\n';

    String S2(5);
    cout << S2.size() << " " << S2 << '\n';

    String S3(5, 'b');
    cout << S3.size() << " " << S3 << '\n';

    String S4(5, "abc");
    cout << S4.size() << " " << S4 << '\n';

    String S5("abcd");
    cout << S5.size() << " " << S5 << '\n';

    String S6(S4);
    cout << S6.size() << " " << S6 << '\n';
    cout << '\n';



    cout << "Операторы:\n";
    String S = S5;
    cout << S.size() << " " << S << '\n';

    S = "fffff";
    cout << S.size() << " " << S << '\n';

    char A[] = "dddd";
    S = A;
    cout << S.size() << " " << S << '\n';

    char* B = new char[5 + 1];
    for (int i = 0; i < 5; i++) {
        B[i] = i + 'g';
    }
    B[5] = '\0';

    S = B;
    cout << S.size() << " " << S << '\n';

    S += "abcd";
    cout << S.size() << " " << S << '\n';
    cout << S + "bbb" << '\n';
    cout << S.size() << " " << S << '\n';

    cout << S[0] << " " << S[-1] << '\n';
    S[0] = 'l';
    S[-1] = 'l';
    cout << S.size() << " " << S << '\n';

    S.reverse();
    cout << S.size() << " " << S << '\n';

    S1 = "abc";
    S2 = "abc";
    cout << (S1 >= S2) << "\n";

    S3 = "abcdef";
    cout << S3.substr(3, 2) << "\n";

    S4 = "abc";
    S4 *= 3;
    cout << S4 << "\n";

    S5 = "abcd";
    cout <<  S5 * 2 << '\n';
    
    cout << S5.insert(3, "HHH") << "\n";

    //String Sh;
    //cin >> Sh;

    //cout << Sh << '\n';

    S6 = "aaaaa";
    cout << S6.find("aa", 2, 2) << "\n";
}
