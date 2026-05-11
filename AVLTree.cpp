#include "AVLTree.h"

AVLTree::AVLTree() {
    root = nullptr;
    totalNodes = 0;
}

int AVLTree::height(Node* node) {
    if (node == nullptr)
        return 0;

    return node->height;
}

int AVLTree::getBalance(Node* node) {
    if (node == nullptr)
        return 0;

    return height(node->left) - height(node->right);
}

AVLTree::Node* AVLTree::rotateRight(Node* y) {

    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLTree::Node* AVLTree::rotateLeft(Node* x) {

    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLTree::Node* AVLTree::insert(Node* node, Student student) {

    if (node == nullptr) {
        totalNodes++;
        return new Node(student);
    }

    // Orden principal: skill_score
    // BONUS: desempate por student_id

    if (student.skill_score < node->data.skill_score) {
        node->left = insert(node->left, student);
    }
    else if (student.skill_score > node->data.skill_score) {
        node->right = insert(node->right, student);
    }
    else {

        if (student.student_id < node->data.student_id) {
            node->left = insert(node->left, student);
        }
        else {
            node->right = insert(node->right, student);
        }
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Left Left
    if (balance > 1 &&
        student.skill_score < node->left->data.skill_score)
        return rotateRight(node);

    // Right Right
    if (balance < -1 &&
        student.skill_score > node->right->data.skill_score)
        return rotateLeft(node);

    // Left Right
    if (balance > 1 &&
        student.skill_score > node->left->data.skill_score) {

        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left
    if (balance < -1 &&
        student.skill_score < node->right->data.skill_score) {

        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void AVLTree::insertStudent(Student student) {
    root = insert(root, student);
}

void AVLTree::inorder(Node* node, int &position) {

    if (node != nullptr) {

        inorder(node->right, position);

        cout << position << ". "
             << node->data.full_name
             << " - Score: "
             << node->data.skill_score
             << endl;

        position++;

        inorder(node->left, position);
    }
}

void AVLTree::showRanking() {

    if (root == nullptr) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }

    int position = 1;
    inorder(root, position);
}

AVLTree::Node* AVLTree::search(Node* node, int skill_score) {

    if (node == nullptr)
        return nullptr;

    if (skill_score == node->data.skill_score)
        return node;

    if (skill_score < node->data.skill_score)
        return search(node->left, skill_score);

    return search(node->right, skill_score);
}

void AVLTree::searchBySkillScore(int score) {

    Node* result = search(root, score);

    if (result == nullptr) {

        cout << "Estudiante no encontrado.\n";
    }
    else {

        cout << "\n===== ESTUDIANTE ENCONTRADO =====\n";

        cout << "ID: " << result->data.student_id << endl;
        cout << "Nombre: " << result->data.full_name << endl;
        cout << "Carrera: " << result->data.career << endl;
        cout << "Semestre: " << result->data.semester << endl;
        cout << "GPA: " << result->data.gpa << endl;
        cout << "Skill Score: " << result->data.skill_score << endl;
    }
}

void AVLTree::showStatistics() {

    cout << "\n===== ESTADISTICAS AVL =====\n";

    cout << "Altura del arbol: "
         << height(root) << endl;

    cout << "Factor de balance de la raiz: "
         << getBalance(root) << endl;

    cout << "Cantidad de nodos insertados: "
         << totalNodes << endl;
}