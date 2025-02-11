all:
	gcc suboChess.c init.c bitboards.c -o suboChess

clean:
	del /f /q suboChess.exe
