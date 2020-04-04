#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Player
{
public:
	string nama;

	/* Constructor */
	Player(const char* nama)
	{
		Player::nama = nama;
		cout << "Player " << Player::nama << "Dibuat" << endl;
	}

	/* Destructor */
	~Player()
	{
		cout << "Player " << Player::nama << "Dihapus" << endl;
	}

};

void membuatPlayerStack()
{
	Player stackPlayer = Player("Stack ");
}

void membuatPlayerHeap()
{
	Player* heapPlayer = new Player("Heap ");
	delete heapPlayer;
}

void membuatPlayerStackPointer(Player *&playerPointer)
{
	Player stackPlayer = Player("Stack ");
	playerPointer = &stackPlayer;
}

void membuatPlayerHeapPointer(Player*& playerPointer)
{
	Player* heapPlayer = new Player("Heap ");
	playerPointer = heapPlayer;
	//delete heapPlayer;
}

Player createStackPlayer()
{
	Player stackPlayer = Player("Stack diCreate!");
	return stackPlayer;
}

Player* createHeapPlayer()
{
	Player* heapPlayer = new Player("Heap ");
	return heapPlayer;
}

int main()
{
	membuatPlayerStack();
	membuatPlayerHeap();

	/* Simulasi Memory Leak */
	cout << "\nMemory Leak" << endl;

	Player* playerPointer1;
	membuatPlayerStackPointer(playerPointer1);
	//cout << (*playerPointer1).nama << endl; /* Tidak Terjadi Apa-Apa */

	Player* playerPointer2;
	membuatPlayerHeapPointer(playerPointer2);
	cout << playerPointer2->nama << endl; /* Leak Memory */

	playerPointer2->nama = "Testing Saja";
	delete playerPointer2;
	//cout << playerPointer2->nama << endl; /* Leak Memory*/

	cout << "\nReturn Object" << endl;
	Player playerReturnStack = createStackPlayer();
	cout << playerReturnStack.nama << endl;

	Player* playerReturnHeap = createHeapPlayer();
	cout << playerReturnHeap->nama << endl;

	_getch();
	return 0;
}