#pragma once
#include "list.h"

List encode(string str)
{
	List newFilteredMap;
	newFilteredMap.mapFiller(str);
	newFilteredMap.algorithm();
	return newFilteredMap;
}

bool notEquals(Bitcode &first, Bitcode &second)
{
	if (first.getSize() != second.getSize())
		return true;
	else {
		BitNode* curThis = first.getHead();
		BitNode* curOther = second.getHead();
		while (curThis != nullptr)
		{
			if (curThis->data != curOther->data)
				return true;
			curThis = curThis->pNext;
			curOther = curOther->pNext;
		}
		return false;
	}
}

string decode(Bitcode code, List map)
{
	string str = "";
	BitNode* cur = code.getHead();
	Bitcode* symbolCode = new Bitcode;

	while (cur != nullptr)
	{
		symbolCode->push(cur->data);
		Node* mapCur = map.getHead();
		while (mapCur != nullptr && notEquals(*symbolCode, *(mapCur->bitcode)))
			mapCur = mapCur->pNext;
		if (mapCur != nullptr) {
			symbolCode->clear();
			str += mapCur->symbol;
		}
		cur = cur->pNext;
		if (cur == nullptr && mapCur == nullptr)
			throw exception("Incorrect map!");
	}
	return str;
}