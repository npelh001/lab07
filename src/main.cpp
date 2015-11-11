#include <iostream>
#include "container.h"
#include "list.h"
#include "bubblesort.h"
#include "selectionsort.h"

using namespace std;

int containerMenu(Container *&);
void elementMenu(Container *);
void sortMenu(Container *);

int main(void) {
    Container * container;
    bool run = true;

    while (run) {

        switch(containerMenu(container)) {
            case 1:
                container = new List();
                break;
            case 2:
                //container = new Vector();
                break;
            case 3:
                run = false;
                return -1;
                break;
        }

        elementMenu(container);
        cout << endl;
        container->print();
        cout << endl;

        sortMenu(container);
        cout << endl;
        container->sort();
        container->print();
        cout << endl;
    }
}

int containerMenu(Container *& container) {
    int selection = 0;

    while (1) {
        cout << "Select a container:" << endl
            << "  1. List" << endl
            << "  2. Vector" << endl
            << "  3. Exit" << endl << endl
            << "        Selection: ";
        cin.clear();
        cin >> selection;
        if (selection == 1 || selection == 2 || selection == 3)
            return selection;
        cout << endl << "Error: Invalid selection!" << endl
            << "Please enter your selection as either 1 or 2." << endl
            << endl;
    }
}

void elementMenu(Container * container) {
    int element;

    cout << endl << endl 
        << "Enter an integer to store as an element in the container."
        << endl << "Enter a non-integer to end." << endl;
    cin.clear();
    cout << endl << "Element: ";
    while (cin >> element) {
        cout << "Element: ";
        container->insert(element);
    }
}

void sortMenu(Container * container) {
    int selection = 0;

    while (selection != 1 || selection != 2 || selection != 3) {
        cout << "Choose a method to sort the container." << endl
            << "  1. Bubble Sort" << endl
            << "  2. Selection Sort" << endl
            << "  3. Merge Sort" << endl << endl
            << "        Selection:";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> selection;
        if (selection == 1 || selection == 2 || selection == 3)
            break;
        cout << "Please enter a valid selection" << endl;
    }
    switch (selection) {
        case 1:
            container->set_sort(new BubbleSort());
            break;
        case 2:
            container->set_sort(new SelectionSort());
            break;
        case 3:
            //container->set_sort(new MergeSort());
            break;
    }
}
