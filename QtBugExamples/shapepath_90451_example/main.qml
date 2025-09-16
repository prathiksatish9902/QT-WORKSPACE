import QtQuick 2.15
import QtQuick.Shapes 1.15

Item {
  ShapePath {
    Component.onCompleted: console.log("ShapePath closed:", closed)  // 🔴 Prints: true (incorrect)
  }

  Path {
    Component.onCompleted: console.log("Path closed:", closed)       // ✅ Prints: false (correct)
  }
}



// import QtQuick 2.15
// import QtQuick.Shapes 1.15

// Item {
//   ShapePath {
//     Component.onCompleted: console.log(closed, "shapePath")
//   }

//   Path {
//     Component.onCompleted: console.log(closed, "path")
//   }
// }
