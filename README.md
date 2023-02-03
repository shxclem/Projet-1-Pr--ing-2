# CY-Météo project Pre-ing2

#CY-Météo is a Script SHELL and C program using GnuPlot to create graph with data base from weather report.

This project is made for a school project, every part of this program is sample code which shows how to do the following :


  shell :
  
  *take the parameters which are choises by the user(temperature,pressure...)
    
  *create a file with the parameters we need and call the c program
    
    
  C :
  
  *sort information ascending or descending
  
  *create a file with the informations sorted
  
  *back to shell and call the gnuplot application

#to run the program do :

./projet_wa.sh 
and add the paramaters that you want to process. The parameters correspond to one place among France (-F), Guyane (-G), Saint-Pierre et Miquelon (-S), Antilles (-A),
Océan Indien (-O), Antarctique (-Q), one or many data(s) among wind (-w), height (-h), moisture (-m) and temperature (-t) or pressure (-p) with a mode. 
The differents modes are :

  1 : outputs the minimum, maximum, and average temperatures or pressures per station in ascending order of station number
  
  2 : outputs the average temperatures (or pressures) by date/time, sorted in chronological order. The average is done over all the stations.
  
  3 : outputs temperatures (or pressures) by date/time by station. They will be sorted first in chronological order, then in ascending order of station identifier
  
  
Also, it is possible to chose a sort among --avl --abr --tab, if you don't, then --avl will be selected by default.
Finally, you need to write the ressource file containing all the datas that will be processed, this file needs to be a .csv. This .csv needs to be in the input folder in order to work.

For example, it would be possible to execute the program in this way : bash projet_wa.sh Test1.csv -t2 -F --abr
