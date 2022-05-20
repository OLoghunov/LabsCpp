#pragma once
#include "structures.h"

double edmonds_karp(Matrix *matx)
{
	if (!matx->size)
		throw exception("Graph is empty!");
	double maxFlow = 0;
	do {
		matx->bfs(matx->source);
		if (!matx->parentsList.GetSize()) break;
		int i = matx->parentsList.head->data;
		double minFlowInPath = INF;
		ListNode<int> cur = *matx->parentsList.head->pNext;
		while (i != matx->sink) {
			if (matx->values[i][cur.data] < minFlowInPath)
				minFlowInPath = matx->values[i][cur.data];
			i = cur.data;
			if (i != matx->sink)
				cur = *cur.pNext;
		}
		maxFlow += minFlowInPath;

		i = matx->parentsList.head->data;
		cur = *matx->parentsList.head->pNext;
		while (i != matx->sink) {
			matx->values[i][cur.data] -= minFlowInPath;
			i = cur.data;
			if (i != matx->sink)
				cur = *cur.pNext;
		}
		cout << "Optimal path found: ";
		ListNode<int>* current = matx->parentsList.head;
		cout << "[";
		while (current != nullptr)
		{
			cout << matx->names[current->data];
			if (current->pNext != nullptr) cout << " ";
			current = current->pNext;
		}
		cout << "]" << "\t\t";
		cout << "Flow through this path is: " << minFlowInPath << endl << endl;
	} while (matx->parentsList.GetSize());
	return maxFlow;
}