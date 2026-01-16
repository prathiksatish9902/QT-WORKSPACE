// #include "widget.h"
#include "employee.h"
#include "employeedata.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // QApplication a(argc, argv);
    // Widget w;
    // w.show();
    Employee prathik;
    prathik.setName("prathik");

    Employee shashank = prathik;
  // 98733   // Employee shashank;
    // shashank = prathik;
    // Employee ranganath;

    std::cout<<shashank.getName().toStdString()<<std::endl;

    // return a.exec();
    return 0;
}



// problem:
//           But the problem is:


//         It only defines the copy constructor, but not the copy assignment operator.
//         This is incomplete — copy constructor and copy assignment operator should be defined as a pair to follow the Rule of 3/5/6 in C++.


//     You're doing manual copying when the compiler can do it safely and more clearly for you — and you're only doing half the job (missing assignment).
// Solution: Use = default for copy operations


// Since QSharedDataPointer handles reference counting internally and has correct semantics for copy, assignment,
// and move operations, the best practice is to default all special member functions where possible.


// Use = default to clearly indicate intent.

// Provide both copy constructor and copy assignment.

// Optionally, also default move constructor and move assignment (Rule of 5 or 6).

