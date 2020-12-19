# Cpp-Algorithms[![Build Status](https://travis-ci.org/jvandemo/copy-github-labels-cli.svg?branch=master)](https://travis-ci.org/jvandemo/copy-github-labels-cli)
 ## Synopsis
 
 This is my personal project, i use it to revise all the algorithms i have learned with C/C++ - lang. Basically, in this project you will find many familliar algorithms and data structures that i have created by my own.
 
 ## 1. Backtracking
 
 From wikipedia :
 Backtracking is a general algorithm for finding all (or some) solutions to some computational problems, notably constraint satisfaction problems, that incrementally builds candidates to the solutions, and abandons each partial candidate ("backtracks") as soon as it determines that the candidate cannot possibly be completed to a valid solution.
 
 ![backtrack](https://user-images.githubusercontent.com/32448829/36640457-9dfbd5b8-1a51-11e8-994a-6bf3c4ebcf6c.gif)
 
 __Properties__
 - Easy to design a solution for problems. 
 - Many things have proceeded from backtracking, such as Machine learning, Dynamic Programing ...
 - Usually have exponential complexity.
 
 __Pseudo Code__
 ```Pascal
 X : Vector of the Answer
 procedure backtracking(i) 
 	begin
 		for(j : Candidates)
 			begin
 				j ->X_i;
 				Deleting j from Candidates;
 				if Building X is done 
 					then Print the result
 				else 
 					backtracking(i + 1);
 				//Return the candidate
 				X_i = 0;
 				Adding j back to Candidates;
 			end;
 	end;
 ```
 ### Examples in Backtracking 
 -	[x] Finding k-Permutation of N
 -	[x] Finding k-Combination of N
 -	[x] Eight Queens Problem

 Testing 123
