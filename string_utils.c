#include "holberton.h"

/**                                                                                                                                                                       
 * _putchar - writes the character c to stdout                                                                                                                            
 * @c: an arg_list containing the character to be printed                                                                                                                 
 *                                                                                                                                                                        
 * Return: On success 1.                                                                                                                                                  
 * On error, return -1                                                                                                                                                    
 */
int _putchar(va_list c)
{
        char a = va_arg(c, int);

        return (write(1, &a, 1));
}

/**                                                                                                                                                                       
 * _putstr - writes the character c to stdout                                                                                                                             
 * @c: an arg list containing the string to be printed                                                                                                                    
 *                                                                                                                                                                        
 * Return: On success the lenght of the string printed                                                                                                                    
 * -1 on failure                                                                                                                                                          
 */
int _putstr(va_list c)
{
        char *s = va_arg(c, char *);

        return (write(1, s, _strlen(s)));
}
