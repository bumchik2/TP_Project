#pragma once


#include "soldier.h"


class Army {
public:
	void addSoldier(Soldier* soldier);

	int getSize();
	int getHP();

	void train();
	void recover();
	void updateParameters();

	void fight(Army* enemies);

	~Army();
private:
	class Node {
	public:
		Node(Soldier* soldier = 0): soldier(soldier), parent(0), left(0), right(0) { }
		Soldier* soldier;
		Node* parent;
		Node* left;
		Node* right;
	};
	Node* root_ = 0;
	int size_ = 0;

	int getHP_(Node* node);

	void addSoldier_(Soldier* soldier, Node* node);

	void train_(Node* node);
	void recover_(Node* node);
	void updateParameters_(Node* node);

	void deleteSubtree_(Node* node);
	void replaceChild_(Node* parent, Node* old_child, Node* new_child);

	void fight_(Army* enemies, Node* node);

	Node* getLeaf_(Node* node);
};

