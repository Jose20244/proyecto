#ifndef AVLTREE_H
#define AVLTREE_H

#include "Student.h"

class AVLTree {
private:

    struct Node {
        Student data;
        Node* left;
        Node* right;
        int height;

        Node(Student s) {
            data = s;
            left = nullptr;
            right = nullptr;
            height = 1;
        }
    };

    Node* root;
    int totalNodes;

    int height(Node* node);
    int getBalance(Node* node);

    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);

    Node* insert(Node* node, Student student);

    void inorder(Node* node, int &position);

    Node* search(Node* node, int skill_score);

public:
    AVLTree();

    void insertStudent(Student student);

    void showRanking();

    void searchBySkillScore(int score);

    void showStatistics();
};

#endif