COMP3004 Winter 2024 Final Project

Team 26
  Tom Fan - 101 265 197
  Jenny Hu
  Kristian Chaves
  Claire Wang - 101 266 251

_________________________________________________________________________________________________________

Compilation / running instructions

QMAKE - compile with QMake with ./comp3004a4.pro 

QT CREATOR (recommended) - open the file in QT creator, and compile with built in tools

NOTE - since we are using qcustomplot, it is recommended to use versions of QT > QT5 to run

_________________________________________________________________________________________________________

Team member contributions:

Tom

Jenny

Kristian

Claire

_________________________________________________________________________________________________________

Demonstration videos (on Google Drive):


Use case 1 (treatment with Neureset device) 
  - https://drive.google.com/file/d/1II94uPCGE-7swlNzrQ4Ou3Q3GY3elMff/view?usp=drive_link

Use case 2 (date/time setting with Neureset controls)
  - https://drive.google.com/file/d/1pqJCH5Q59a5ZfVl6nxMOzkUps5X4u6TP/view?usp=drive_link

Use case 4 (Nereset device detects low battery)
  - https://drive.google.com/file/d/1q2VVnA8TEAi1e7G0VGog9Gf00qoKhF_P/view?usp=drive_link

Use case 5 (Neureset device detects disconnection on sensors)
  - https://drive.google.com/file/d/1wDbwU1CLw2m0fQ_MFoCKEasLN4EYipx3/view?usp=drive_link

Note - in draft version, logging session data on device side is still WIP. Will be ready in final version

_________________________________________________________________________________________________________


Files included with submission:
  Source code:
    headers:
      - computerview.h
      - constants.h
      - eegsensor.h
      - Logs.h
      - mainwindow.h
      - menucontroller.h
      - neuresetController.h
      - qcustomplot.h
      - Session.h
      - timecontroller.h
      - timeupdater.h
      - treatmentcontroller.h

    c++ files:
      - computerview.cpp
      - eegsensor.cpp
      - Logs.cpp
      - main.cpp
      - mainwindow.cpp
      - menucontroller.cpp
      - neuresetcontroller.cpp
      - qcustomplot.cpp
      - Session.cpp
      - timecontroller.cpp
      - timeupdater.cpp
      - treatmentcontroller.cpp

    other:
      - comp3004a4.pro
      - comp3004a4.pro.user
      - resources.qrc
    
    assets:
      - downarrow.png
      - menu.png
      - pauseIcon.png
      - playIcon.jpg
      - stopButton.jpg
      - upArrow.png

