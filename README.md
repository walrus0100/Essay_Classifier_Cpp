Essay Classifier in C++
Overview

This is an essay classifier program using a perceptron in C++. The program takes in essays as inputs and generates a heat map to classify each essay based on common words. I used this program to find essays that were writen with GPT.



Input Format

The essay classifier program expects input essays in plain text format, with each essay represented by a separate file. The essays should be stored in a folder named "input" in the same directory as the executable.

Output

The program generates a log file with heuristics for each file.

log.txt:
Points Collected: 67		        	//fingerprint size ./main debug  will output.f file and train model
Total Words: 393				//word count
Total Sentences: 18			       //total sentences
Largest sentence size : 29		       // large sentence count in words
Loaded Model has 4950 indexed data points      //loaded model size also a check that the data is loaded
=============Error_Rate============
Found 20 sets of indexed data!		           // sets of equal size of the in file fingerprint that will be compared
 fMax: 1.933333				   	     //detector peak of infile
 ErrorMAX: 3.691614			   	    //error detector peak denotes high GPT activity
 RMax: 375 :  :0.003748:   :705 total error points //random element display make sure we have a working error collector
Processing time: 8.035203 seconds.

rbreak .*() empty parameter 
rbreak .* all funtions




