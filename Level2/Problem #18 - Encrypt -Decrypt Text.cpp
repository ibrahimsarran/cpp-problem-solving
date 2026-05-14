// Problem #18/2 - Encrypt / Decrypt Text
#include <iostream>
#include <string>
using namespace std;

string readText()
{
    string text;

    cout << "Enter a text: ";
    getline(cin, text);

    return text;

}
string encryptText(string text,short encryptionKey)
{
    for (int i = 0; i < text.length(); i++)
    {
        text[i] = char((int)text[i] + encryptionKey);
    }

    return text;
}

string decryptText(string text,short encryptionKey)
{
    for (int i = 0; i < text.length(); i++)
    {
        text[i] = char((int)text[i] - encryptionKey);
    }

    return text;


}

void printResults(string text, string encrypted, string decrypted)
{
    cout << "\nText Before Encryption: " << text << endl;
    cout << "\nText After Encryption:  " << encrypted << endl;
    cout << "\nText After Decryption:  " << decrypted << endl;
}


int main()
{
    const short encryptionKey = 5;
    string text = readText();
    string textAfterEncryption = encryptText(text, encryptionKey);
    string textAfterDecryption = decryptText(textAfterEncryption, encryptionKey);

    printResults(text, textAfterEncryption, textAfterDecryption);

    return 0;

}