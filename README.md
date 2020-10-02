[![Run on Repl.it](https://repl.it/badge/github/LBYEC2B-Project/Final-Project)](https://repl.it/github/LBYEC2B-Project/Final-Project)
Obscure Bugs:
	1:addProduct works, but for some crashes when ran twice in one session. on opening the program again, addProduct will work again until ran a second time.
		-narrowed down the problem to be in either reallocateMemory() or addProduct()
		-if in reallocate Memory you change "*size-1" to "*size-2", you can run addProduct twice before crash, but
		one of the proucts loses its name and group.
		-*size-2 seems correct, but the associated data deletion bug is a worse result, therefore *size-1 is kept until a fix is made.
	

	2:The list can be any size if provided a manually editted text file and everything will run (except addProduct() will error as described above),
	but if addProduct() is used add an entry the program will error when trying
	to add a Product after the list is _x_ entries long (_x_ is different on each computer we test this on, most commonly _x_ == 7).

Future Considerations:
-currently does not have error handling to handle wrong type inputs, but it would be an improvement to add in the future/given more time.
