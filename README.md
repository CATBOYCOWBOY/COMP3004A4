# COMP3004 Winter 2024 Final Project

Dr Vojaslav Radonjic
April 2024

Team 26
- Tom Fan - 101 265 197
- Jiayu Hu - 101 253 627
- Kristian Chaves - 101 233 930
- Claire Wang - 101 266 251

## Compilation / running instructions

- QMAKE: compile with QMake with ./comp3004a4.pro   

- QT CREATOR (recommended): open the file in QT creator, and compile with built in tools  

### NOTES
- since we are using `QCustomPlot`, it is recommended to use versions of QT > QT5 to run

## Team member contributions  
Tom
- base class `neuresetController` for all controller classes 
- design pattern used for primary neureset methods 
    (controller created my MainWindow controlls UI directly)
- Neureset treatment process, controller for treatment logic (`treatmentcontroller`)
- threaded sensor class for individual sensor logic (separate start/finish signals, values, etc)
- generation logic for important values, methods for calculating values and generating data series
- display for data series representing sensor readings in main window (done through qcustomplot)
- signal event for handling logging logic, passing in log data to log controller
- main menu controller logic
- this readme

Jiayu
- display of logged sessions on PC side (alternate QWindow)
- data retrieval logic from CSV
- table display to parse out raw data from 
- documentation including:
- currently available sequence diagrams
- UML class diagram
- requirements traceability matrix
- textual design explanation (WIP)
- state diagrams for existing NeuresetController derived controller classes:
    - `treatmentcontroller`
    - `timecontroller`
    - `LogController`

Kristian
- custom non QT defalt date/time picker in Neureset (`TimeController`)
- display for current device time
- initialization logic for current device time based off of host system (course VM) time
- threaded `TimeUpdater` class for tracking passage of time based on Neureset device's frame of reference 
- external API accesible by `treatmentcontroller` class for getting a formatted dateTime string matching
    device time
    
Claire
- LogsController (NeuresetController derived class) handling all logic related to logging/storing logs on device side
- logic for storing logs given by `treatmentcontroller` to a CSV file in project source code
      - use `treatmentcontroller`'s given signal, store logs as both an array of values (on runtime) and as a series of recorded logs, using comma-separated values, entries separated by '\n' (persistent)
- logic for parsing persistently stored logs between instances of program into a table view, displaying start and ending datetime only
- logic to write logs to the Neureset device's disk and to the computer view separately

Shared contributions:
- use cases


## Demonstration videos (on Google Drive):

[Use case 1 (treatment with Neureset device)](https://drive.google.com/file/d/1aC1XOalPdHg1itX7LROPzSrxLoyKUewF/view?usp=sharing)

[Use case 2 (date/time setting with Neureset controls)](https://drive.google.com/file/d/1hrMTkTmXFpbrRNbAxvaT84RfbEEjeAbD/view?usp=sharing)

[Use case 3 (viewing session logs with Neureset controls)](https://drive.google.com/file/d/19O3U7r47JcTYsfz9R-N9iKQvGweuV5c-/view?usp=sharing)

[Use case 4 (Neureset device detects low battery)](https://drive.google.com/file/d/1c0qOYUTOmEKZ9tVbmHxQOmbPcyc4a_Pu/view?usp=sharing)

[Use case 5 (Neureset device detects disconnection on sensors)](https://drive.google.com/file/d/1fqOcrxpg3P8ojCt34S_V8yYnEaQrtlB2/view?usp=sharing)


## Files included with submission:  
Source code:
### SOURCES (.cpp)
- CustomWidgets/ledlight.cpp
- LogsController.cpp
- computerview.cpp
- eegsensor.cpp
- main.cpp
- mainwindow.cpp
- qcustomplot.cpp
- timecontroller.cpp
- timeupdater.cpp
- menucontroller.cpp
- neuresetcontroller.cpp
- treatmentcontroller.cpp

### HEADERS (.h)
- CustomWidgets/ledlight.h 
- LogsController.h 
- computerview.h 
- constants.h 
- eegsensor.h 
- mainwindow.h 
- constants.h 
- qcustomplot.h 
- timecontroller.h 
- timeupdater.h 
- menucontroller.h 
- neuresetController.h 
- treatmentcontroller.h 

### Other:
- COMP3004A4.pro
- resources.qrc

#### Session Log files 
If desired, copy the starter data from these files into the corresponding files under the `build-COMP3004A4` debug folder that is created when the project is built  
- data.csv 
- logs.csv

### Assets:
- downarrow.png
- menu.png
- pauseIcon.png
- playIcon.jpg
- stopButton.jpg
- upArrow.png

