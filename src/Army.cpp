#include "soldier.h"
#include "army.h"


#include <stdexcept>
#include <iostream>


void Army::replaceChild_(Node* parent, Node* old_child, Node* new_child) {
	if (parent == 0) {
		return;
	}
	if (parent->left == old_child) {
		parent->left = new_child;
	} else if (parent->right == old_child) {
		parent->right = new_child;
	} else {
		throw std::runtime_error("parent does not have the child to replace");
	}
}


void Army::deleteSubtree_(Node* node) {
	if (node != 0) {
		deleteSubtree_(node->left);
		deleteSubtree_(node->right);
		replaceChild_(node->parent, node, 0);
		if (node == root_) {
			root_ = 0;
		}
		delete node;
		--size_;
	}
}


Army::~Army() {
	deleteSubtree_(root_);
}


void Army::addSoldier_(Soldier* soldier, Node* node) {
	int direction = rand() % 2;
	if (direction == 0) {
		if (node->left == 0) {
			node->left = new Node(soldier);
			node->left->parent = node;
			++size_;
		} else {
			addSoldier_(soldier, node->left);
		}
	} else {
		if (node->right == 0) {
			node->right = new Node(soldier);
			node->right->parent = node;
			++size_;
		} else {
			addSoldier_(soldier, node->right);
		}
	}
}


void Army::addSoldier(Soldier* soldier) {
	if (root_ == 0) {
		root_ = new Node(soldier);
		size_ = 1;
	} else {
		addSoldier_(soldier, root_);
	}
}


void Army::train_(Node* node) {
	if (node != 0) {
		train_(node->left);
		train_(node->right);
		new (node->soldier->action_) TrainAction(node->soldier->action_);
	}
}


void Army::train () {
	train_(root_);
	updateParameters();
}


void Army::recover_(Node* node) {
	if (node != 0) {
		recover_(node->left);
		recover_(node->right);
		new (node->soldier->action_) RecoverAction(node->soldier->action_);
	}
}


void Army::recover() {
	recover_(root_);
	updateParameters();
}


void Army::updateParameters_(Node* node) {
	if (node != 0) {
		updateParameters_(node->left);
		updateParameters_(node->right);
		node->soldier->updateParameters();
	}
}


void Army::updateParameters() {
	updateParameters_(root_);
}


Army::Node* Army::getLeaf_(Node* node) {
	if (node == 0) {
		return 0;
	}
	if (node->left == 0 && node->right == 0) {
		return node;
	} else if (node->left == 0) {
		return getLeaf_(node->right);
	} else if (node->right == 0) {
		return getLeaf_(node->left);
	} else {
		int direction = rand() % 2;
		if (direction == 0) {
			return getLeaf_(node->left);
		} else {
			return getLeaf_(node->right);
		}
	}
}


int Army::getSize() {
	return size_;
}


int Army::getHP_(Node* node) {
	if (node == 0) {
		return 0;
	} else {
		return getHP_(node->left) + getHP_(node->right) + node->soldier->health_;
	}
}


int Army::getHP() {
	return getHP_(root_);
}


void Army::fight_(Army* enemies, Node* node) {
	if (node == 0 || enemies->getSize() == 0) {
		return;
	}
	fight_(enemies, node->left);
	fight_(enemies, node->right);
	Node* enemy = enemies->getLeaf_(enemies->root_);
	if (enemy != 0) {
		node->soldier->causeDamage(enemy->soldier);
		if (!enemy->soldier->is_alive_) {
			// enemy was a leaf, so subtree is one vertex
			enemies->deleteSubtree_(enemy);
		}
	}
}


void Army::fight(Army* enemies) {
	fight_(enemies, root_);
}

