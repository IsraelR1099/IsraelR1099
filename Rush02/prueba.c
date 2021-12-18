/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:54:29 by irifarac          #+#    #+#             */
/*   Updated: 2021/12/18 15:37:20 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int	ft_strlen(char *str); //Funcion para contar los caracteres

int	main(int argc, char *argv[])
{
	int	fd;
	char	buf[4];
//	char	buf2[4] = "bien";
	ssize_t numero;

	fd = open("/Users/irifarac/Ejercicios/Rush02/diccionario", O_RDWR);

	for (int i = 0; i < argc; i++)
	{
		write(fd, argv, ft_strlen(*argv));
	}
	if (fd == -1)//Si no abre archivo da error
	{
		printf("Error al abrir el archivo");
	}
	else
	{
	//	for (int i = 0; i < argc; i++) //Funcion para leer archivo y almacenar el argumento del usuario en una array 
		{
		numero = read(fd, buf, 10);
		//write(fd, buf2, strlen(buf2));
	//	write(fd, &argv, ft_strlen(*argv));
			printf("Hecho\n");
		
		close(fd);
		}

		if (numero == 0)
		{
			printf("archivo vacio \n");
		}
		else
		{
			printf("Numero de caracteres es %d, contenido: %s \n", (int)numero, buf);
		}
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	nbr;

	nbr = 0;
	while (str[nbr] != '\0')
	{
		nbr++;
	}
	return (nbr);
}
