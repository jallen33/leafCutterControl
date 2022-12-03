# leafCutterControl
## Mechanical Considerations
The design was done using Autodesk Inventor. The [zip folder](/f450_assembly.zip) contains all the CAD files and assemblies relating to the design. The zip folder also contains *.stl* files for the parts that were 3D printed. In addition, a [build file](/f450_assembly.mfp) that contains all the necessary 3D printed parts for markforged printers is available. There is also a [list](/leaf_cutter_control_part_list.xlsx) of of all the parts that need to be ordered or on hand for assembly.

A few notes before assembling:
- Part *rod_insert_m5.ipt* needs to be tapped with an M5x.8 tap
- Parts fitting into carbon fiber rods should be set with epoxy

## Drone Considerations
The assembly is mounted to a DJI F450 drone. Both the drone and the emergency release mechanism are controlled by a Futaba conroller (two seperate receivers).

## Hardware Softwawre Interface
An Arduino is used to obtain analog data from the two potentiometers and the force sensor. The two potentiometer are wired directly to the Arduino. The force sensor connect to an amplifier circuit. The amplifier circuit is then wired to the Arduino. 

### Serial Communication
The [Arduino script](/controlLL/controlLL.ino) prints the analog values to the serial monitor for serial communication. *Add any consideration from the Arduino code when finished*.
