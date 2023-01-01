#include <iostream>
#include <fstream>
using namespace std;
const char *dictionary = "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM!@#$%^&*()_+{}?><~`№;:?\\\"',./[]|\n\t \0";
const char *something = "1234567890qwertyuiopasdfghjkl";
bool inDictionary(char c) {
    bool res = false;
    for (int i = 0; i < (int)string(dictionary).size(); i++) if (dictionary[i] == c) res = true;
    return res;
}
void exec(string code) {
    srand(time(NULL));
    if (something[rand() % 29] == 'p') { cout << "Some glitch appeared and interpreter broke!" << endl; exit(-1); }
    int arr[30000];
    int pointer = 0;
    string ln;
    int sizeInt = 0;
    int randStart = 0;
    char c = 0;
    int toUse = 0;
    for (int i = 0; i < 30001; i++) arr[i] = 0;
    for (int i = 0; i < (int)code.size(); i++) {
        int randMod = rand() % 92;
        if (i == 0) randMod = 0;
        int mod = code.size() + 67876 + code[i];
        srand(i + pointer + arr[pointer] + sizeInt + randStart + c + randMod + toUse + mod);
        if (!inDictionary(code[i])) { cout << "Wrong character '" << code[i] << "'!"  << endl; exit(-1); }
        int cmd = (code[i] + i + pointer + arr[pointer] + (rand() % 87673847)) % 94;
        if (cmd < 0) cmd = -cmd;
        switch (cmd) {
            case 0: arr[pointer]++; break;
            case 1: arr[pointer]--; break;
            case 2: arr[pointer] += 2; break;
            case 3: arr[pointer] -= 2; break;
            case 4: arr[pointer] += 3; break;
            case 5: arr[pointer] -= 3; break;
            case 6: pointer++; break;
            case 7: if(pointer > 0) pointer--; break;
            case 8: pointer += 2; break;
            case 9: if (pointer > 1) pointer -= 2; break;
            case 10: pointer += 3; break;
            case 11: if (pointer > 2) pointer -= 3; break;
            case 12: pointer = 0; break;
            case 13: arr[pointer] = 0; break;
            case 14: srand(time(NULL) + ( i * cmd)); arr[rand() % 30000] = 0; break;
            case 15: srand(time(NULL) + ( i * cmd)); arr[rand() % 30000] = pointer; break;
            case 16: srand(time(NULL) + ( i * cmd)); cout << (char)arr[rand() % 30000] << endl; break;
            case 17: srand(time(NULL) + ( i * cmd)); cout << (char)arr[rand() % 30000]; break;
            case 18: break;
            case 19: exit(-1);
            case 20: cin >> ln; sizeInt = (int)ln.size(); for (int n = 0; n < sizeInt; n++) arr[pointer+n] = ln[n]; break;
            case 21: cin >> ln; sizeInt = (int)ln.size(); srand(time(NULL) + ( i * cmd)); randStart = rand() % 30000; for (int n = 0; n < sizeInt; n++) arr[randStart+n] = ln[n]; break;
            case 22: cin >> ln; sizeInt = (int)ln.size(); for (int n = 0; n < sizeInt; n++) pointer *= ln[n]; break;
            case 27: cin >> ln; sizeInt = (int)ln.size(); for (int n = 0; n < sizeInt; n++) pointer -= ln[n]; if (pointer < 0) pointer = 0; break;
            case 28: cin >> ln; sizeInt = (int)ln.size(); for (int n = 0; n < sizeInt; n++) pointer += ln[n]; if (pointer < 0) pointer = 0; break;
            case 29: cin >> ln; sizeInt = (int)ln.size(); for (int n = 0; n < sizeInt; n++) { if (ln[n] == 0) break; pointer /= ln[n]; } break;
            case 23: cin >> ln; c = ln[0]; pointer -= c; if (pointer < 0) pointer = 0; break;
            case 24: cin >> ln; c = ln[0]; pointer += c; if (pointer < 0) pointer = 0; break;
            case 25: cin >> ln; c = ln[0]; if (c == 0) break; pointer /= c; break;
            case 26: cin >> ln; c = ln[0]; pointer *= c; break;
            case 30: arr[pointer] *= arr[pointer]; break;
            case 31: if (arr[pointer+1] == 0) break; arr[pointer] /= arr[pointer+1]; break;
            case 32: arr[pointer] *= arr[pointer+1]; break;
            case 33: arr[pointer] = 1; break;
            case 34: arr[pointer+2] = arr[pointer] + arr[pointer+1]; pointer += 2; break;
            case 35: arr[pointer+2] = arr[pointer] - arr[pointer+1]; pointer += 2; break;
            case 36: arr[pointer+2] = arr[pointer] * arr[pointer+1]; pointer += 2; break;
            case 37: if (arr[pointer+1] == 0) break; arr[pointer+2] = arr[pointer] / arr[pointer+1]; pointer += 2; break;
            case 38: if (arr[pointer+1] == 0) break; arr[pointer+2] = arr[pointer] % arr[pointer+1]; pointer += 2; break;
            case 39: arr[pointer+1] = arr[pointer] * arr[pointer]; pointer++; break;
            case 40: for (int n = 0; n < 30001; n++) arr[n] = 0; break;
            case 41: for (int n = 0; n < 30001; n++) arr[n] = pointer * 100; break;
            case 42: for (int n = 0; n < 30001; n++) { srand(time(NULL) + n * 100); arr[n] = rand() % 93881; } break;
            case 43: srand(time(NULL) + i); pointer = rand() % 89032; break;
            case 44: i--; break;
            case 45: i = 0; break;
            case 46: srand((((((rand() % 9294 + rand()) % 9444 + rand()) % 942 + rand()) % 615 + rand()) % 46 + rand()) % 10 + rand()); break;
            case 47: srand(0); break;
            case 48: srand(pointer); break;
            case 49: toUse = 0; for (int n = 0; n < 30001; n++) toUse += arr[n]; srand(toUse); break;
            case 50: toUse = 0; for (int n = 0; n < 30001; n++) toUse += arr[n]; srand(rand() % toUse); break;
            case 51: for (int n = 0; n < 30001; n++) if (arr[n] != 0) cout << (char)arr[n]; break;
            case 52: for (int n = 0; n < 30001; n++) if (arr[n] != 0) cout << (char)arr[n]; cout << endl; break;
            case 53: srand(time(NULL) + rand() + (rand() + (rand() % 9229))); if (rand() % 2 == 0) exit(-1); break;
            case 54: arr[pointer+1] = rand() % 9876567; break;
            case 55: if (pointer != 0) arr[pointer-1] = rand() % 9876482; break;
            case 56: if (pointer != 0) arr[pointer-1] = 0; break;
            case 57: arr[3000] = (rand() + rand() + rand() + rand() + rand() + rand() + rand() + rand() + rand()) % 98574829; break;
            case 58: arr[3000] = 0; break;
            case 59: arr[pointer] = code.size(); break;
            case 60: arr[pointer] += code.size(); break;
            case 61: if (code.size() == 0) break; arr[pointer] /= code.size(); break;
            case 62: arr[pointer] -= code.size(); break;
            case 63: arr[pointer] = code.size()*(arr[pointer]+1); break;
            case 64: cout << (char)arr[pointer]; break;
            case 65: cout << (char)pointer; break;
            case 66: cout << (char)pointer << endl; break;
            case 67: cout << pointer << endl; break;
            case 68: cout << pointer; break;
            case 69: cout << arr[pointer]; break;
            case 70: cout << arr[pointer] << endl; break;
            case 71: if (pointer == 0) break; srand(arr[pointer] + pointer); arr[pointer] = rand() % pointer+1; break;
            case 72: if (pointer == 0) break; srand(arr[pointer] + pointer); arr[rand() % pointer + 1] = rand() % pointer +1; break;
            case 73: if (pointer == 0) break; srand(arr[pointer] + pointer); cout << rand() << endl; break;
            case 74: if (pointer == 0) break; srand(arr[pointer] + pointer); cout << rand(); break;
            case 75: if (pointer == 0) break; srand(arr[pointer] + pointer); cout << rand() % pointer+1 << endl; break;
            case 76: if (pointer == 0) break; srand(arr[pointer] + pointer); cout << rand() % pointer+1; break;
            case 77: if (pointer == 0) break; srand(arr[pointer] + pointer); cout << (char)(rand() % pointer+1) << endl; break;
            case 78: if (pointer == 0) break; srand(arr[pointer] + pointer); cout << (char)(rand() % pointer+1); break;
            case 79: if (pointer == 0) break; srand(arr[pointer] + pointer); cout << rand() + pointer << endl; break;
            case 80: if (pointer == 0) break; srand(arr[pointer] + pointer); cout << rand() + pointer; break;
            case 81: if (pointer == 0) break; srand(arr[pointer] + pointer); cout << rand() % pointer+1 + pointer << endl; break;
            case 82: if (pointer == 0) break; srand(arr[pointer] + pointer); cout << rand() % pointer+1 + pointer; break;
            case 83: if (pointer == 0) break; srand(arr[pointer] + pointer); cout << (char)(rand() % pointer+1 + pointer) << endl; break;
            case 84: if (pointer == 0) break; srand(arr[pointer] + pointer); cout << (char)(rand() % pointer+1 + pointer); break;
            case 85: if (pointer == 0) break; srand(arr[pointer] + pointer); cout << rand() + arr[pointer] << endl; break;
            case 86: if (pointer == 0) break; srand(arr[pointer] + pointer); cout << rand() + arr[pointer]; break;
            case 87: if (pointer == 0) break; srand(arr[pointer] + pointer); cout << rand() % pointer+1 + arr[pointer] << endl; break;
            case 88: if (pointer == 0) break; srand(arr[pointer] + pointer); cout << rand() % pointer+1 + arr[pointer]; break;
            case 89: if (pointer == 0) break; srand(arr[pointer] + pointer); cout << (char)(rand() % pointer+1 + arr[pointer]) << endl; break;
            case 90: if (pointer == 0) break; srand(arr[pointer] + pointer); cout << (char)(rand() % pointer+1 + arr[pointer]); break;
            case 92: cout << 0 << endl; break;
            case 91: cout << 0; break;
            case 93: cout << (char)arr[pointer] << endl; break;
            default: cout << "Unable to proceed! Interpreter is too stupid!" << endl; exit(-1);
        }
    }
}
int main(int argc, char **argv) {
    string cmd = "help";
    if (argc > 1) cmd = argv[1];
    if (cmd == "help") {
        cout << "help            This message" << endl;
        cout << "version         Version" << endl;
        cout << "repl            Interactive Shell" << endl;
        cout << "<FILENAME>      Run code from file" << endl;
        cout << "build           Build code" << endl;
    } else if (cmd == "version") cout << "EsoLang 1.0.0" << endl;
    else if (cmd == "repl") {
        cout << "Use :exit to exit!" << endl;
        while (true) {
            string toExec;
            cout << "> ";
            cin >> toExec;
            if (toExec == ":exit") return 0;
            exec(toExec);
        }
    } else if (cmd == "build") {

    } else {
        ifstream f (cmd);
        string line;
        string buffer;
        if (f.good()) while (getline(f, line)) buffer += line;
        f.close();
        exec(buffer);
    }
}