#include "AVLTree.h"

int main() {

    AVLTree rankingTree;

    int option;

    do {

        cout << "\n===== MENU AVL =====\n";
        cout << "1. Insertar estudiante\n";
        cout << "2. Mostrar ranking academico\n";
        cout << "3. Buscar por skill_score\n";
        cout << "4. Mostrar estadisticas AVL\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> option;

        switch(option) {

        case 1: {

                Student s;

                cin.ignore();

                cout << "ID estudiante: ";
                cin >> s.student_id;

                cin.ignore();

                cout << "Nombre completo: ";
                getline(cin, s.full_name);

                cout << "Carrera: ";
                getline(cin, s.career);

                cout << "Semestre: ";
                cin >> s.semester;

                cout << "GPA: ";
                cin >> s.gpa;

                cout << "Skill Score: ";
                cin >> s.skill_score;

                rankingTree.insertStudent(s);

                cout << "Estudiante insertado correctamente.\n";

                break;
        }

        case 2:

            cout << "\n===== RANKING ACADEMICO =====\n";
            rankingTree.showRanking();

            break;

        case 3: {

                int score;

                cout << "Ingrese skill_score a buscar: ";
                cin >> score;

                rankingTree.searchBySkillScore(score);

                break;
        }

        case 4:

            rankingTree.showStatistics();

            break;

        case 5:

            cout << "Saliendo del sistema...\n";

            break;

        default:

            cout << "Opcion invalida.\n";
        }

    } while(option != 5);

    return 0;
}