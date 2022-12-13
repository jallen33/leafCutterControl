# leafCutterControl
## Mechanical Considerations
The design was done using Autodesk Inventor. The [zip folder](/f450_assembly.zip) contains all the CAD files and assemblies relating to the design. The zip folder also contains *.stl* files for the parts that were 3D printed. In addition, a [build file](/f450_assembly.mfp) that contains all the necessary 3D printed parts for markforged printers is available. There is also a [list](/leaf_cutter_control_part_list.xlsx) of of all the parts that need to be ordered or on hand for assembly.

A few notes before assembling:
- Part *rod_insert_m5.ipt* needs to be tapped with an M5x.8 tap after 3D printing
- Parts fitting into carbon fiber rods should be set with epoxy

## Drone Assembly
The assembly is mounted to a DJI F450 drone. Both the drone and the emergency release mechanism are controlled by a Futaba conroller (two seperate receivers).

## Hardware Software Interface
An Arduino board is used to obtain analog data from the two potentiometers and the force sensor. The two potentiometer are wired directly to the Arduino. The force sensor connect to an amplifier circuit. The amplifier circuit is then wired to the Arduino. 

### Serial Communication
The [Arduino script](/controlLL/controlLL.ino) prints the data to the serial monitor for serial communication. The [Python script](/serial_coms.py) reads the serial monitor and prints the data to the command line to be used later. The data printed is roll and pitch angles and weight from the force cell in grams.

## Future Work
Moving forward, the angles and weight values will be fed into the controller to control the drone while it executes a cutting sequence or in this case a simulated cutting sequence. In general, the data will be fed into a Rhaspberry Pi and mavros will be used to process the data. The processed data can be fed into a pixhawk contoller and used to control the drone. 
