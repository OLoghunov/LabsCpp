#pragma once
enum class Colors { RED, BLACK };

template <typename T>
class TreeNode {
	int key;
	T data;
	Colors color;

public:
	TreeNode* pRight = nullptr;
	TreeNode* pLeft = nullptr;
	TreeNode* pParent = nullptr;

	TreeNode(int key, T data, Colors color, TreeNode<T>* pParent) {
		this->key = key;
		this->data = data;
		this->color = color;
		this->pParent = pParent;
	}

	int getKey() {
		return this->key;
	}

	void setKey(int key) {
		this->key = key;
	}

	T getData() {
		return this->data;
	}

	void setData(T data) {
		this->data = data;
	}

	Colors getColor() {
		return this->color;
	}

	void setColor(Colors color) {
		this->color = color;
	}
};
