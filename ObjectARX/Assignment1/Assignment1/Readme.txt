Steps1: Created a project using MFC library
Step2: Set up project configurations such as adding a libraries, adding additional dependencies, setting the output.arx file and so on
Step3: Set up the .def file which can access the acryx entrypoint which is the entrypoint of function 
Step4: Added required code inside pch.h file 
Step5: In .h of project file added required files and precompilation files 
Step6: In .h added the member function and entrypoint function outside class defination all methods to be included inside the .h 
Step7: In .cpp defination of the declaration of .h files
Step8: Inside .cpp file we have to define the appload unload acrxyEntrypoint and so much of things
Step9: Now save and compile the code
Step10: Now add the command registry line 
Step11: Inside that add the static function that we have defined in the cpp file
Step12: Now Build the solution
Step13: Open the .arx inside autocad
Step14: Enter the command that we recently registered
Step15: You will see the output inside autocad application
