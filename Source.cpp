#include<iostream>
#include "VectorOps.h"
#include "GameObject.h"
#include<chrono>
#include "Physics.h"
#include<conio.h>
#include<typeinfo>
#define clrscr std::cout << "\033[2J\033[1;1H"


int main() {

	auto start = std::chrono::steady_clock::now();
	
	GameObject2D obj1("obj1"), obj2("obj2", Vector2(1.0, 2.0), 20.6, 2.1);
	GameObject3D obja, objb("obj b", Vector3(1.0, 2.3, -5.5), 1.0, 2.2, "Player1-3D"), objc("obj c", Vector3(43,22,22));
	//obja.SetTag("Player1-3D");
	//objc.SetTag("Player2-3D");
	//objc.SetPos(Vector3(1.2, 2.0, -5.6));
	obja.SetTag("Player1");
	//std::cout << obj1.GetPos();
	//obj2.SetTag("Player1");
	//obj3.SetPos(Vector2(2.0, -5.6));
	obja.SetRad(10);
	objb.SetRad(5);
	objc.SetRad(10);
	objb.SetPos(Vector3(20,20,20));
	//std::cout << obja.GetPos() << std::endl << objb.GetPos() << std::endl << std::endl;
	//std::cout << obja << std::endl << objb << std::endl << objc << std::endl << std::endl;
	//std::cout << obj1 << std::endl << obj2 << std::endl << obj3 << std::endl;
	//std::cout << std::endl << std::chrono::duration_cast<std::chrono::seconds> (std::chrono::steady_clock::now() - start).count() << std::endl;

	//objc.SetName( "Player1-3D");
	//objc.SetTag("Player1-3D");

	//std::cout << std::endl << "--------------------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
	long long int frate = 60, pauseNew, pause;
	char ch;
	Vector3 f(2, 1, 1);
	obja.AddToCollisionException("Player1-3D");
	while (true)
	{
		
		Physics::AddForce3D(obja, f);
		pauseNew = (std::chrono::steady_clock::now() - start).count();
		//std::cout << frate << std::endl;
		if (std::chrono::duration_cast<std::chrono::milliseconds> (std::chrono::steady_clock::now() - start).count() % 1000 == 0) {
			//clrscr;
			GameObject3D* x = obja.CollisionDetection3D();
			std::cout << obja.GetPos()<<"\t"<<objb.GetPos();
			std::cout << "\n";
		if (x != nullptr) {
			std::cout <<std::endl<< "caught collision with"<<std::endl << *x << std::endl << std::endl;
			std::cout << std::endl;
		}
		}
		pause = (std::chrono::steady_clock::now() - start).count();
		frate = (pauseNew - pause);
		
	}

	//GameObject3D::ListIt();
	//GameObject3D::SearchAndList("Player1-3D");

	
}

