#include "Queue.h"
#include "function.h"

int main() {
  char infix[100];
  Queue que;
  string option;
  int choice, input;

  //Option screen
  cout << "Pick What You Would Like To Test: " << endl;
  cout << "A - Test Infix to Postfix Conversion" << endl;
  cout << "B - Test Queue" << endl;
  cout << "Q - Quit" << endl << endl;

  // option to choose what to test out
  cout << "Option:";
  cin >> option;

  cout << endl << endl;

  // loops back again until the user wants to quit the program
  while (option != "Q") {

    // if the user chooses option A, it will test out the Infix to Postfix Conversion
    if (option == "A" or option == "a") {
      cout << "Enter an infix expression: ";
      cin >> infix;

      if (isBalanced(infix)) {
        string postfix = infixToPostfix(infix);
        cout << "Postfix expression: " << postfix << endl;
      } else {
        cout << "Invalid expression! Parentheses are not balanced." << endl;
      }

    }

    // if the user chooses option B, it will test out the Queue
    else if (option == "B" or option == "b") {
      cout << "What would you like to do?: " << endl;
      cout << "1 - Enqueue" << endl;
      cout << "2 - Dequeue" << endl;
      cout << "3 - Check Size" << endl;
      cout << "4 - Check Front Element" << endl;
      cout << "5 - Check if Queue Empty" << endl;
      cout << "6 - Quit" << endl << endl;

      cout << "Choice: ";
      cin >> choice;

      // it will loop until the user chooses to quit
      while (choice != 6){
        // enqueues the user input
        if (choice == 1) {
          cout << "What would you like to add? (Input has to be an integer): ";
          cin >> input;
          que.enqueue(input);
        }

        // dequeues the queue
        if (choice == 2) {
          que.dequeue();
          cout << "Dequeued!" << endl;
        }

        // returns the queue size
        if (choice == 3) {
          cout << "Queue size: " << que.size() << endl;
        }

        // returns the front element of the queue
        if (choice == 4) {
          cout << "Front element: " << que.peek() << endl;
        }

        // returns true if the queue is empty, false if it is not
        if (choice == 5) {
          cout << "Is the queue empty? " << (que.isEmpty() ? "Yes" : "No") << endl;
        }

        // prints out the options until the user chooses to quit
        cout << endl << endl;
        cout << "What would you like to do?: " << endl;
        cout << "1 - Enqueue" << endl;
        cout << "2 - Dequeue" << endl;
        cout << "3 - Check Size" << endl;
        cout << "4 - Check Front Element" << endl;
        cout << "5 - Check if Queue Empty" << endl;
        cout << "6 - Quit" << endl << endl;

        cout << "Choice: ";
        cin >> choice;

        if (choice == 6) {
          break;
        }

      }
    }

    // prints out the options until the user chooses to quit
    cout << endl << endl;
    cout << "Pick What You Would Like To Test: " << endl;
    cout << "A - Test Infix to Postfix Conversion" << endl;
    cout << "B - Test Queue" << endl;
    cout << "Q - Quit" << endl << endl;

    cout << "Option: ";
    cin >> option;
    cout << endl << endl;
    
    if (option == "Q" or option == "q") {
      break;
    }
  }

  return 0;
}
