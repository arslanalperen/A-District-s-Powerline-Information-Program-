# A District's Powerline Information Program 

**<h1>Project Objective</h1>**

To write a program that provides step-down transformer center information, customer information, line information, number of lines, total line length, total number of customers, number of customers according to customer types, identification number of the step-down transformer center and coordinate information in the distribution network of the electrical energy system by using geographic information system data.  

**<h1>Description of Problem</h1>**  

The problem given to me to solve is to get the step-down transformer center, customer and line information of the program from the .txt file, where the information is written according to a certain systematic, and to save this information in the correct form and use it in certain operations to output to the script and .txt file.  

**<h1>Description of Method</h1>**  

The first method I applied to solve the problem was to calculate how many step-down transformer center, customer and line information there are in the .txt file. I found out how many there are by counting the number of lines of step-down transformer center, customer and line information by putting certain conditions. Then, using this information and certain string functions, I saved the information from the .txt file to the relevant struct array structures. This is how I solved the first part of the problem for me. In the second part, I had to do the actions that were requested from me with this information. Usually I needed to output to .txt file. For the distance calculation, I used a general distance calculation function. Using this function, I also calculated and printed different types of desired distances in several places.  

**<h1>User's Guide</h1>**  

My first advice to the user who will use the program is to put the project file in a folder. Since 2 .txt files will be created when the program is run, it would be better to have the files in a folder for more efficient use. In fact, the system of the program is to read the .txt file containing the general information, use this information in certain operations and write it to another .txt file. What is requested from the user is the id of the customer and line information to be checked. After the user enters this information, the program will close with a warning that the printing process has been completed, if the operations have been completed without any problems. The program will create two .txt files in the folder it is in. In the file named Sonuclar.txt, information such as the number of step-down transformer center, number of customers, number of lines, step-down transformer center information, customer and line information requested by the user will be written. In the second file named musteri_kus_ucusu_mesafe, the air distance between each customer and step-down transformer center in the system will be written one by one. There are no possible limitations in the program. If the user enters the wrong id information, the program will warn the relevant .txt file that the customer was not found in the relevant id. The most likely reason for the program to give an error may be that the .txt file requested to be retrieved information has been entered in a way that does not comply with the program's information reading algorithm. To minimize this error, line counting and certain string functions are used, but if the files are corrupted, the program may fail.  

**<h1>Results of the Solution</h1>**  

When the program is run, the id of the line and customers to be controlled will be requested from the user as in the image below.  

![Imag _1](/images/gorsel1.png)  

When the program finishes running, it creates two .txt files. Most of the information requested is written in the section called Sonuclar. If there is no customer belonging to the id entered by the user, we will see an image like the one below.  

![Imag _2](/images/gorsel2.png)  

If the existing customer and line id in the system is entered, a visual like the one below is taken.  

![Imag _4](/images/gorsel4.png)  

In the second .txt file created by the program, the air distance between each customer and the step-down transformer center will be written.  

![Imag _3](/images/gorsel3.png)  

**<h1>Flowchart of the Program</h1>**  

![Flowchart](/images/Flowchart.png)  

**<h1>Conclusion and Remarks</h1>**  

My program is running fine. Even though it was written in a certain order from the .txt file, it was quite difficult to take thousands of data and save that data in the structures they are related to correctly. He had a really hard time trying to do this job the right way. I had to search as many sources as possible, regardless of Turkish or English. In fact, I may have forgotten to write many of them in the bibliography with the excitement of the research. In fact, I can say that the project taught me how to do research, as in the projects given this semester. I think that's the most important thing I've learned. I learned dozens of local and foreign forums, what other people did, what suggestions they got against the problems they encountered, how they overcame those problems, and how I could adapt those suggestions to my own code, since of course they are not exactly the same problems. I learned many things. I learned many functions especially related to string functions and how to use them. But as I said, most importantly, when I encounter problems, I can say that I have learned to a large extent how to do research to overcome them.
I can say that the program is very user friendly. As explained in the user guide, the user is expected to just collect all the data and code files in the same folder. The program will run smoothly as long as there is no corruption in the data files. If changes are made to the names of the txt files, these changes must also be made to the code.  

**<h1>References</h1>**  

•	Kodlakafa.com  
•	Alldatasheet.com  
•	Stackoverflow.com  
•	Algoritmaornekleri.com  
•	Arduinolibraries.com  
•	Github.com  
•	Sanatsalbilgi.com  
•	Theengineeringprojects.com  
•	Rapidtables.com  
•	Koddefteri.com  
•	Erhanulman.com  
•	Forum.donanimhaber.com  
•	Cagataycebi.com  
•	Forum.csharpnedir.com  
•	En.wikipedi0.org  
•	Hayaletveyap.com  
•	Grafiboyz.blogcu.com  
•	Aliozcan.org  
•	Gelecegiyazanlar.turkcell.com.tr  
•	Iucoders.com  
•	Sanalkurs.net  
•	Buraksenyurt.com  
•	Microcore.com  
•	Link24in.wordpress.com  
•	Soyunmezoglubaris.blogspot.com  
•	Motorobit.com  
•	Kodumundunyasi.net  
