//<----- License Notice Start ----->
//Repository => https://github.com/KadirBerat/DataStructuresAndAlgorithms-ButunlemeSinavi.git
//This program is licensed under the Apache License 2.0.
//Learn more about repository licenses. => https://docs.github.com/en/github/creating-cloning-and-archiving-repositories/licensing-a-repository#disclaimer
//License File => https://github.com/KadirBerat/DataStructuresAndAlgorithms-ButunlemeSinavi/blob/main/LICENSE
//Copyright 2021 Kadir Berat Güventürk
//<-- !!! Do not remove. !!! -->
//<----- License Notice End ----->

#include <iostream> //iostream kütüphanesini ekledik.
#include <conio.h> //getch() fonksiyonunu kullanmak için conio.h kütüphanesini ekledik.
using namespace std; //namespace tanimladik.

struct Node //Node adinda struct olusturduk.
{
	int data; //Node icerisinde data adinda degisken tanimladik. (Node icerisinde verileri tutucak olan degisken) 
	Node* next; //Node'nin next'ini tanimladik. (next kismina eklenen Node, eklendigi Node'den sonraki Node oluyor.)
};

struct List //List adinda struct olusturduk.
{
	Node* head; //Node türünde head degiskenini tanimladik.
	Node* last; //Node türünde last degiskenini tanimladik.
	List() { head = NULL; last = NULL; } //head ve last degerlerini NULL olarak atadik.

	void add(Node* e) //Yeni Node ekleyen fonksiyon
	{
		if (head == NULL) //head null'mu kontrolu.
			head = e; //head'i e'ye esitledik.
		else
			last->next = e; //last'in next'ini e'ye esitledik.
		last = e; //last'i e'ye esitledik.

		cout << e->data << " Listeye eklendi." << endl; //Ekrana mesaj yazdirdik.
	}
};

struct stack { //stack adinda struct olusturduk.
	int size; //intager turunde size degiskenini olusturduk.
	int* elements; //integer turunde elements degiskenini olusturduk.
	int top; //integer turunde top degiskenini olusturduk.
};

int stackSize; //stack'in boyutunu sakliycak degisken.

stack* createStack(int size) { //Yeni stack olusturan fonksiyon.
	stack* e = new stack; //yeni stack olusturduk.
	e->size = size; //stack'in size degiskenine atama yaptik.
	e->top = -1; //stack'in top degiskenine atama yaptik.
	e->elements = new int[size]; //stackin elements degikenine yeni bir dizi olusturduk.
	cout << "stack olusturuldu." << endl; //Ekrana mesaj yazdirdik.
	stackSize = size; //stackSize degiskenine atama yaptik.
	return e; //stack'i geriye döndürdük.
}

bool isStackFull(stack& e) { //stack tamamen dolumu kontrolunu yapan fonksiyon.
	if (e.top == e.size - 1) //stack tamamen dolumu kontrolu.
		return true; //tamamen doluysa geriye true donduruyoruz.
	else
		return false; //tamamen dolu degilse geriye false donduruyoruz.
}

bool isStackEmpty(stack& e) { //stack bosmu kontrolunu yapan fonksiyon.
	if (e.top == -1) //stack bosmu kontrolu.
		return true; //bossa geriye true degerini donduruyoruz.
	else
		return false; //bos degilse geriye false degerini donduruyoruz.
}

bool push(stack& e, int data) { //stack'e  veri ekleyen fonksiyon.
	if (isStackFull(e) == false) //stack tamamen dolumu kontrolu.
	{
		cout << data << " stack'e eklendi." << endl; //ekrana mesaj yazdiriyoruz.
		e.elements[++e.top] = data; //stack'e veri ekliyoruz.
		return true; //geriye true degerini donduruyoruz.
	}
	else
	{
		cout << "stack'e eklenemedi, stack tamamen dolu!" << endl; //ekrana mesaj yazdiriyoruz.
		return false; //geriye false degerini donduruyoruz.
	}
}

bool pop(stack& s, List& li) { //stack'den veri cikaran fonksiyon.
	if (isStackEmpty(s) == false) //stack bosmu kontrolu.
	{
		int val = s.elements[s.top]; //Silinecek verininin degerini degiskene atadik.
		Node* e = new Node; //yeni bir Node olusturduk.
		e->data = val; //Node'nin data degiskenine atama yaptik.
		li.add(e); //Node'yi listeye ekledik.
		cout << val << " stack'den silindi." << endl; //ekrana mesaj yazdirdik.
		s.elements[s.top--] = NULL; //stack'den son veriyi sildik.
		return true; //geriye true degerini dondurduk.
	}
	else
	{
		cout << "stack'den silinemedi, stack tamamen bos!" << endl; //ekrana mesaj yazdirdik.
		return false; //geriye false degerini dondurduk.
	}
}

int main() //main fonksiyonu.
{
	stack* s = createStack(8); //8 elemanli yeni stack olusturduk.

	push(*s, 1); //stack'e veri ekledik.
	push(*s, 2);
	push(*s, 3);
	push(*s, 4);
	push(*s, 5);
	push(*s, 6);
	push(*s, 7);
	push(*s, 8);

	List li; //Yeni bir liste olusturduk.

	cout << "Kapatmak icin Enter'e basin." << endl; //ekrana mesaj yazdirdik.

	for (int i = stackSize; i > 0 ; i--)
	{
		const int a = _getch(); //Klavyeden herhangi bir tusa basilana kadar bekliyoruz.
		if (a == 13) //basilan tus enter'mi kontrolu.
		{
			cout << "Enter'e basildigi icin program sonlandi." << endl; //ekrana mesaj yazdiriyoruz.
			return 0; //eger enter'e basildiysa programi sonlandiriyoruz.
		}
		else
			pop(*s, li); //stack'den veri cikariyoruz. (cikarilan veri listeye ekleniyor)
	}

	cout << "Stack icerisinde veri kalmadigi icin program sonlandi." << endl; //ekrana mesaj yazdiriyoruz.
	return 0; //geriye 0 degerini donduruyoruz.
}
