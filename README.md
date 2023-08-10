#File Manager Simulation Project

This project involves the creation of a file management system simulation in a terminal environment.
The system uses a tree data structure to manage files and folders.
The program includes the following functionalities:

    Display Current Folder Path
        Before executing any command, the current folder path is displayed.
        For instance, if the root folder is the current folder, it displays "->".
        If the current folder is "teste2," a subfolder of "temp,"
        which is within the root folder, the displayed path will be "-temp-teste2->".

    List Contents of a Folder
        Command: ls
        Displays all files and folders contained in the current folder.
        Files and folders are shown in alphabetical order, with folders indicated by a trailing "-".
        Example: If the "temp" folder contains files "a.txt," "www.html," and "run.exe," 
        along with subfolders "Boot" and "teste2," 
        the ls command will return the names of the items, one per line, as shown below:

        a.txt
        Boot-
        run.exe
        teste2-
        www.html

    Create a File in the Current Folder
        Command: ma <file name>
        Creates a file (terminal node) within the current folder.
        Example: ma quest.txt creates the file "quest.txt" in the current folder.

    Create a Folder in the Current Folder
        Command: mp <folder name>
        Creates an empty folder within the current folder.
        Example: mp backup creates the "backup" folder as a subfolder of the current folder.

    Navigate through Folders
        Command: cd <folder>
        Changes the current folder by entering a subfolder or accessing the parent folder (if available).
        Example: cd .. accesses the parent folder of the current folder (if it exists).
        cd teste2 accesses the "teste2" folder within the current folder (if it exists).

    Delete Files or Folders
        Command: rm <file or folder>
        Deletes a file or folder in the current directory. 
        For folders, all contents are deleted as well.
        Example: rm temp deletes the "temp" folder and its contents 
        (if the "temp" folder exists within the current folder).

    Exit the Program
        Command: ex
        Terminates the program's execution and displays the message "sistema encerrado" (system closed).
        This command serves as the stopping criterion for the loop that reads and executes commands 
        in the file manager simulation.

This project aims to simulate basic file management operations using a tree data structure and terminal commands. It provides functionalities such as navigating through folders, creating files and folders, listing contents, and deleting items. By implementing these features, the program replicates a simple file management system within a terminal environment.