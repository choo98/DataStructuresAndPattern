#include "Visitor.h"
#include "Warrior.h"
#include "Archer.h"

void Visitor::Visit(BaseClass& B)
{
}

void Visitor::Visit(Warrior& W)
{
}

void Visitor::Visit(Archer& A)
{
}

void VisitorDesc::Visit(Warrior& W)
{
	cout << "*********CLASS DESCRIPTION*********" << endl;
	cout << "A Warrior is a class that lives by the Sword and Shield and Honor without these tree things a warrior can be count as dead. With a courage as brave as a lion and strong sense for justice, the Warrior class always charges head in first into danger to save the lives of innocence." << endl;
	cout << "***********************************" << endl;
}

void VisitorDesc::Visit(Archer& A)
{
	cout << "*********CLASS DESCRIPTION*********" << endl;
	cout << "An Archer is a class that utilizes the Bow and Arrow and without these two things an archer can be count as dead. With a pair of razor sharp eyes and a keen intuitive sense, the Archer class is able to survive in the woods for a long time through hunting." << endl;
	cout << "***********************************" << endl;
}
