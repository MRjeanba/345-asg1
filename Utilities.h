//
// Created by Jean-Baptiste Garibo on 2024-03-12.
//

#ifndef UTILITIES_H
#define UTILITIES_H
// Helper class to provide project wide methods:

// clear the console
/**
 * Helper method to clear the screen, depending on the OS, it will use a different command
 */
inline void Clear()
{
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; // the below commands do not work properly, so instead just print back to line many times to clean screen
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined (__APPLE__)
    system("clear");
#endif
}

#endif //UTILITIES_H
