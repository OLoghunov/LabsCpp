#include "shannon_fano.h"

const size_t strCount = 3;

const string strings[strCount] = {
	"Keepin` you at an disadvantage, is an advantage I intend to keep", 
	"I don`t tip because society says I have to", 
	"Say 'what' again. Say 'what' again, I dare you, I double dare you, say what one more goddamn time!" 
};

int main()
{
	Map map;
	for (int i = 0; i < 3; i++) {
		string str = strings[i];
		map = encode(str);
		cout << "////Shannon-Fano algorithm////" << endl << endl << "String before encoding:" << endl << str << endl;
		double size1 = str.length();
		cout << "Its size is equal to " << size1 << " bytes" << endl << endl;
		Node* cur = map.getHead();
		while (cur != nullptr) {
			cout << "symbol " << cur->symbol << "  frequency " << cur->key << "  code ";
			BitNode* temp = cur->bitcode->getHead();
			while (temp != nullptr) {
				cout << temp->data;
				temp = temp->pNext;
			}
			cout << endl;
			cur = cur->pNext;
		}
		cout << endl;
		double size2 = 1;
		cout << "Encoded string:" << endl;
		Bitcode code;
		for (char& c : str) {
			cur = map.getHead();
			while (cur->symbol != c)
				cur = cur->pNext;
			BitNode* temp = cur->bitcode->getHead();
			int maxCode = 0;
			if (cur->bitcode->getSize() > maxCode) {
				maxCode = cur->bitcode->getSize();
				size2 = ceil((double(str.length()) * cur->bitcode->getSize()) / 8);
			}
			while (temp != nullptr) {
				code.push(temp->data);
				cout << temp->data;
				temp = temp->pNext;
			}
		}

		cout << endl << "Its size is equal to " << size2 << " bytes";
		cout << endl << endl << "Decoded string:";

		try {
			str = decode(code, map);
			cout << endl << str << endl << endl << "Compression ratio: " << size2 / size1 << endl << endl;
		}
		catch (exception ex) { cout << endl << ex.what() << endl; }
	}
}