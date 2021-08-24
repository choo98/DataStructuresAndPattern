#pragma once

template<class DataType>
class DoublyItemNode
{
public:
	typedef DoublyItemNode<DataType> itemNode;
private:
	DataType itemName;
	itemNode* fNext;
	itemNode* fPrev;
	DoublyItemNode();
public:
	static itemNode NIL;
	DoublyItemNode(const DataType& aItemName); // Constructor to allow insertion of string value later on

	void prepend(itemNode& aItemNode); // Places a node to the left side ( in front ) of another node
	void append(itemNode& aItemNode); // Places a node to the Right side ( in the backside ) of another node
	void itemNodeRemove(); // Removes a selected node when function is called

	const DataType getItemName() const;
	const itemNode* getNext() const;
	const itemNode* getPrev() const;


};
template <class DataType>
DoublyItemNode<DataType> DoublyItemNode<DataType>::NIL;

template<class DataType>
DoublyItemNode<DataType>::DoublyItemNode() // Default constructor, make next and prev pointer to point to NIL
{
	itemName = DataType();
	fNext = &NIL;
	fPrev = &NIL;
}

template<class DataType>
DoublyItemNode<DataType>::DoublyItemNode(const DataType& aItemName)
{
	this->itemName = aItemName;
	fNext = &NIL;
	fPrev = &NIL;
}

template<class DataType>
void DoublyItemNode<DataType>::prepend(itemNode& aItemNode) {

	//make this the forward pointer of aItemNode
	aItemNode.fNext = this;

	//make this the backside pointer of aItemNode
	if (fPrev != &NIL) {
		//backward pointer and make previous
		aItemNode.fPrev = fPrev;
		fPrev->fNext = &aItemNode;
	}
	//this backside pointer becomes aItemNode
	fPrev = &aItemNode;
}

template<class DataType>
void DoublyItemNode<DataType>::append(itemNode& aItemNode) {

	//make this the backside pointer of aItemNode
	aItemNode.fPrev = this;

	//make this the forward pointer of aItemNode
	if (fNext != &NIL) {
		//forward pointer and make next
		aItemNode.fNext = fNext;
		fNext->fPrev = &aItemNode;
	}
	//this forward pointer becomes aItemNode
	fNext = &aItemNode;
}

template<class DataType>
void DoublyItemNode<DataType>::itemNodeRemove()
{
	if (fNext == &NIL)
	{
		fPrev->fNext = &NIL;
		
	}
	else if (fPrev == &NIL)
	{
		fNext->fPrev = &NIL;
	}
	else
	{
		fPrev->fNext = fNext;
		fNext->fPrev = fPrev;
	}

}

template<class DataType>
const DataType DoublyItemNode<DataType>::getItemName() const
{
	return itemName;
}

template<class DataType>
const DoublyItemNode<DataType>* DoublyItemNode<DataType>::getNext() const
{
	return fNext;
}

template<class DataType>
const DoublyItemNode<DataType>* DoublyItemNode<DataType>::getPrev() const
{
	return fPrev;
}

