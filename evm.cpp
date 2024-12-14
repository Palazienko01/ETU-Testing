#include <iostream>
#include <cstring>
#include <limits>

using namespace std;


string floatToBinaryString(float f) {
    unsigned int intRepres;
    memcpy(&intRepres, &f, sizeof(f));

    string binaryString = "";
    for (int i = 31; i >= 0; i--) {
        binaryString += (intRepres & (1 << i)) ? '1' : '0';
    }
    return binaryString;
}

string shortIntToBinaryString(short int value) {
    string binaryString = "";
    for (int i = 15; i >= 0; i--) {
        binaryString += (value & (1 << i)) ? '1' : '0';
    }
    return binaryString;
}

short int binaryStringToShortInt(const string& binaryStr) {
    short int result = 0;
    for (size_t i = 0; i < binaryStr.size(); ++i) {
        if (binaryStr[i] == '1') {
            result |= (1 << (binaryStr.size() - 1 - i));
        }
    }
    return result;
}

float binaryStringToFloat(const string& binaryStr) {
    unsigned int intRepres = 0;
    for (size_t i = 0; i < binaryStr.size(); ++i) {
        if (binaryStr[i] == '1') {
            intRepres |= (1 << (binaryStr.size() - 1 - i));
        }
    }
    float f;
    memcpy(&f, &intRepres, sizeof(f));  
    return f;
}

void invertingIntNum(string aboba) {
    int n;
    bool flag_end = false;
    cout << "Enter kol-vo numberov: ";

    do{
        cin >> n;
        cout << '\n';
        if (n < 15 && n > 0 && !cin.fail()){
            flag_end = true;
        }else{
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Invalid input. Please enter a valid number" << endl;
        }
    } while (!flag_end);
    flag_end = false;
    cout << "\n";

    int abobius[n];
    cout << "Enter numer of razryady you dont want to change: ";

    for (int i = 0; i < n; i++) {
    do{
        cin >> abobius[i];
        if (!cin.fail() && abobius[i] =< 15 && abobius[i] >= 0){
            flag_end = true;
        }else{
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Invalid input. Please enter a valid numer." << endl;
        }
    } while (!flag_end) ;
        flag_end = false;
        abobius[i] = 15 - abobius[i];
        cout << ' ';
    }
    flag_end = false;
    cout << '\n';

    for (int i = 0; i <= 16; i++) {
        int flag = 0;
        for (int j = 0; j < n; j++) {
            if (i == abobius[j]) {
                flag = 1;
            }
        }
        if (flag == 0) {
            aboba[i] = (aboba[i] == '0') ? '1' : '0';
        }
    }

    cout << "Result: " << aboba << endl;

    short int result = binaryStringToShortInt(aboba);
    cout << "Inverted short int result: " << result << endl;
}

void invertingFloatNum(string aboba) {
    int n;
    bool flag_end = false;
    cout << "Enter kol-vo numberov: ";

    do{
        cin >> n;
        cout << '\n';
        if (n < 31 && n > 0 && !cin.fail()){
            flag_end = true;
        }else{
        cin.clear(); 
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); 
        cout << "Invalid input. Please enter a valid number" << endl;
        }
    } while (!flag_end) ;
    flag_end = false;
    cout << "\n";

    int abobius[n];
    cout << "Enter numer of razryady you dont want to change: ";

    for (int i = 0; i < n; i++) {
    do{
        cin >> abobius[i];
        if (!cin.fail() && abobius[i] <= 31 && abobius[i] >= 0){
            flag_end = true;
        }else{
        cin.clear(); 
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); 
        cout << "Invalid input. Please enter a valid numer." << endl;
        }
    } while (!flag_end) ;
        flag_end = false;
        abobius[i] = 31 - abobius[i];
        cout << ' ';
    }

    cout << '\n';

    for (int i = 0; i <= 32; i++) {
        int flag = 0;
        for (int j = 0; j < n; j++) {
            if (i == abobius[j]) {
                flag = 1;
            }
        }
        if (flag == 0) {
            aboba[i] = (aboba[i] == '0') ? '1' : '0';
        }
    }

    cout << "Result: " << aboba << endl;

    float result = binaryStringToFloat(aboba);
    cout << "Inverted float result: " << result << endl;
}

int main() {
    float num_f;
    short int num_sf;
    string res;
    bool end_of_life = false;
    do {
        cout << "Enter the number: ";
        while (!(cin >> num_f)) {
        cout << "only numbers gnida!!!!! ";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
        if ((num_f > 32767 || num_f != (int)(num_f)) || (num_f < -32768 || num_f != (int)(num_f))) {
            cout << "Since numer out of range short int or num is not decimal, working with float" << endl;
            res = floatToBinaryString(num_f);
            end_of_life = true;
            cout << "Result(binary): " << res << endl;
            invertingFloatNum(res);
        } else {
            cout << "Working with short int" << endl;
            num_sf = static_cast<short int>(num_f); 
            res = shortIntToBinaryString(num_sf);
            end_of_life = true;
            cout << "Result(binary): " << res << endl;
            invertingIntNum(res);
        }
    } while (end_of_life == false);

    return 0;
}
