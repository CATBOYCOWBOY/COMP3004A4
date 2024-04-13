COMP3004 Winter 2024 Final Project

Dr Vojaslav Radonjic

Team 26
  Tom Fan - 101 265 197
  Jiayu Hu - 101 253 627
  Kristian Chaves - 101 233 930
  Claire Wang - 101 266 251

_________________________________________________________________________________________________________

Compilation / running instructions

QMAKE - compile with QMake with ./comp3004a4.pro 

QT CREATOR (recommended) - open the file in QT creator, and compile with built in tools

NOTE - since we are using qcustomplot, it is recommended to use versions of QT > QT5 to run

_________________________________________________________________________________________________________

Team member contributions:

Tom

  - base class neuresetController for all controller classes 
    - design pattern used for primary neureset methods 
      (controller created my MainWindow controlls UI directly)
  - Neureset treatment process, controller for treatment logic (treatmentcontroller)
    - threaded sensor class for individual sensor logic (separate start/finish signals, values, etc)
    - generation logic for important values, methods for calculating values and generating data series
    - display for data series representing sensor readings in main window (done through qcustomplot)
    - signal event for handling logging logic, passing in log data to log controller
  - main menu controller logic
  - this readme

Jenny
  - display of logged sessions on PC side (alternate QWindow)
    - data retrieval logic from CSV
    - table display to parse out raw data from 
  - documentation including:
    - currently available sequence diagrams
    - UML class diagram
    - requirements traceability matrix
    - textual design explanation (WIP)
    - state diagrams for existing NeuresetController derived controller classes:
      - treatmentcontroller
      - timecontroller
      - logcontroller

Kristian
  - custom non QT defalt date/time picker in Neureset (TimeController)
    - display for current device time
    - initialization logic for current device time based off of host system (course VM) time
    - threaded TimeUpdater class for tracking passage of time based on Neureset device's frame of reference 
    - external API accesible by treatmentcontroller class for getting a formatted dateTime string matching
      device time
    
Claire
  - NeuresetController derived class handling all logic related to logging/storing logs on device side
    (logcontroller)
    - logic for storing logs given by treatmentcontroller to a CSV file in project source code
      - use treatmentcontroller's given signal, store logs as both an array of values (on runtime)
        and a series of recorded logs, values separated by ',', entries separated by '\n' (persistent)
    - logic for parsing persistently stored logs between instances of program into a table view, displaying
      start and ending datetime only

Shared contributions:
  - use cases

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


Compilation / running instructions

QMAKE - compile with QMake with ./comp3004a4.pro 

QT CREATOR (recommended) - open the file in QT creator, and compile with built in tools

NOTE - since we are using qcustomplot, it is recommended to use versions of QT > QT5 to run
