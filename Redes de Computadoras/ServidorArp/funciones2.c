#include "funciones.h"

unsigned char tramaEnv[1514];
unsigned char tramaRev[1514];
int contador = 0;
unsigned char MACT[6];
unsigned char ip[4];
unsigned char MACorigen[6];
unsigned char MACbro[6] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
unsigned char ethertype[2] = { 0x08, 0x06 };
unsigned char HPHP[6] = { 0x00, 0x01, 0x08, 0x00, 0x06, 0x04 };	//Ethertype, protocolo IP longitud MAC y longitud IP
unsigned char OP[2] = { 0x00, 0x01 };	//Tipo de operacion
unsigned char MacDes[6] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };	//mac destino no se sabe
unsigned char CRC[4] = { 0x00, 0x00, 0x00, 0x00 };	//cola
unsigned char OP2[2] = { 0x00, 0x02 };

unsigned char IpDes[4];		//ip de la cual queremos saber la direccion MAC

void
Serverup (MYSQL * con, MYSQL_ROW row, MYSQL_RES * res)
{
  int packet_socket, indice;
  packet_socket = socket (AF_PACKET, SOCK_RAW, htons (ETH_P_ALL));
  if (packet_socket == -1)
    {
      perror ("\nError al abrir el socket\n");
      exit (0);
    }
  else
    {
      printf ("\nExito al abrir el socket\n");
      indice = obtenerDatos2 (packet_socket);
      while (1)
	{
	  escucha (packet_socket, tramaRev, con, indice, row, res);
	}
    }
}

unsigned char
traducir1 (char MAC)
{
  switch (MAC)
    {
    case '0':
      return 0x00;
    case '1':
      return 0x10;
    case '2':
      return 0x20;
    case '3':
      return 0x30;
    case '4':
      return 0x40;
    case '5':
      return 0x50;
    case '6':
      return 0x60;
    case '7':
      return 0x70;
    case '8':
      return 0x80;
    case '9':
      return 0x90;
    case 'a':
      return 0xa0;
    case 'b':
      return 0xb0;
    case 'c':
      return 0xc0;
    case 'd':
      return 0xd0;
    case 'e':
      return 0xe0;
    case 'f':
      return 0xf0;
    }
}

unsigned char
traducir2 (char MAC)
{
  switch (MAC)
    {
    case '0':
      return 0x00;
    case '1':
      return 0x01;
    case '2':
      return 0x02;
    case '3':
      return 0x03;
    case '4':
      return 0x04;
    case '5':
      return 0x05;
    case '6':
      return 0x06;
    case '7':
      return 0x07;
    case '8':
      return 0x08;
    case '9':
      return 0x09;
    case 'a':
      return 0x0a;
    case 'b':
      return 0x0b;
    case 'c':
      return 0x0c;
    case 'd':
      return 0x0d;
    case 'e':
      return 0x0e;
    case 'f':
      return 0x0f;
    }
}

unsigned char
Sumahex (unsigned char num1, unsigned char num2)
{
  unsigned char num3;
  num3 = num1 + num2;
  return num3;
}

void
escucha (int ds, unsigned char *trama, MYSQL * con, int index, MYSQL_ROW row,
	 MYSQL_RES * res)
{
  unsigned char IpWin[4] = { 0x00, 0x00, 0x00, 0x00 };	//Direccion Ip que manda windows en ARPGRAT
  unsigned char MacAux[6];	//Mac sacada de la trama
  unsigned char IpAux[4];	//Ip sacada de la trama
  unsigned char MacDefault[6] = { 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc };
  unsigned char IP[8];		//Ip copiada desde la base de datos
  unsigned char num1, num2, num3;
  char MAC[17];			//Mac copiada desde la base de datos
  unsigned char Mac[6];		//Mac para la estructura de la ARPGRAT(reply)
  unsigned char Ip[4];		//Ip para la estructura de la ARǴRAT(reply)
  char consulta0[1024];
  char consulta1[1024];
  int tam, i, j, len;

  tam = recvfrom (ds, trama, 1514, 0, NULL, 0);

  if (tam == -1)
    printf ("\nNo se recivio nada");
  else
    {
      if (!memcmp (ethertype, trama + 12, 2))
	{
	  if (!memcmp (trama + 28, trama + 38, 4)
	      || !memcmp (IpWin, trama + 28, 4))
	    {
	      memcpy (MacAux, trama + 22, 6);
	      memcpy (IpAux, trama + 38, 4);
	      fprintf (stdout, "IP que solicito: %hhu.%hhu.%hhu.%hhu\n",
		       IpAux[0], IpAux[1], IpAux[2], IpAux[3]);
	      fprintf (stdout,
		       "MAC que solicito: %.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n",
		       MacAux[0], MacAux[1], MacAux[2], MacAux[3], MacAux[4],
		       MacAux[5]);
	      sprintf (consulta0,
		       "SELECT IP_RESIDTRADA, MAC_ASOCIADA FROM red WHERE IP_RESIDTRADA = '%hhu.%hhu.%hhu.%hhu' AND MAC_ASOCIADA = '%.2x:%.2x:%.2x:%.2x:%.2x:%.2x';",
		       IpAux[0], IpAux[1], IpAux[2], IpAux[3], MacAux[0], MacAux[1], MacAux[2], MacAux[3], MacAux[4],MacAux[5]);
	      if (mysql_query (con, consulta0) == 0)
		{
		  res = mysql_use_result (con);
		  if ((row = mysql_fetch_row (res)) != 0)
		    {
		      fprintf (stdout, "\nConexion establecida\n");
		      //exit(0);
		    }
		  else
		    {
		      sprintf (consulta1,
			       "SELECT MAC_ASOCIADA FROM red WHERE MAC_ASOCIADA = '%.2x:%.2x:%.2x:%.2x:%.2x:%.2x';",
			       MacDefault[0], MacDefault[1], MacDefault[2],
			       MacDefault[3], MacDefault[4], MacDefault[5]);
		      if (mysql_query (con, consulta1) == 0)
			{
			  res = mysql_use_result (con);
			  while ((row = mysql_fetch_row (res)) != NULL)
			    {
			      strcpy (MAC, row[0]);
			    }
			  fprintf (stdout, "Mac del defensor: %s\n", MAC);
			  len = strlen (MAC);

			  for (i = 0, j = 0; i <= len; i++)
			    {
			      if (i == 0 || i == 3 || i == 6 || i == 9 || i == 12 || i == 15)
				{
				  num1 = traducir1 (MAC[i]);
				}
			      else
				{
				  if (i == 1 || i == 4 || i == 7 || i == 10 || i == 13 || i == 16)
				    {
				      num2 = traducir2 (MAC[i]);
				    }
				  else
				    {
				      if (i == 2 || i == 5 || i == 8 || i == 11 || i == 14 || i == 17)
					{
					  num3 = Sumahex(num1, num2);
                                          memcpy (&Mac[j], &num3, 1);
                                          j++;                                           
					}
				    }
				}

			    }
			  GARP (trama, tramaEnv, Mac);
			  enviaTrama (tramaEnv, ds, index);
			  GARPB (trama, tramaEnv, Mac);
			  enviaTrama (tramaEnv, ds, index);
			  fprintf (stdout, "\nConexion denegada\n");
			}
		    }
		}
	    }
	  else
	    escucha (ds, trama, con, index, row, res);
	}
    }
}

char
GARP (unsigned char *trama, unsigned char *tramaEnv, unsigned char *Mac)
{
  memcpy (tramaEnv + 0, trama + 6, 6);	//Encabezado MAC: Direccion Destino
  memcpy (tramaEnv + 6, Mac, 6);	//Encabezado MAC: Direccion Fuente
  memcpy (tramaEnv + 12, ethertype, 2);	//Mensaje ARP: Tipo
  memcpy (tramaEnv + 14, HPHP, 6);	//Mensaje ARP: Longitud
  memcpy (tramaEnv + 20, OP2, 2);	//Mensaje ARP: Opcode
  memcpy (tramaEnv + 22, Mac, 6);	//Sender Hardware Address 
  memcpy (tramaEnv + 28, trama + 28, 4);	//Sender Protocol Address
  memcpy (tramaEnv + 32, trama + 6, 6);	//Target Hardware Address
  memcpy (tramaEnv + 38, trama + 28, 4);	//Target Protocol Address
  memcpy (tramaEnv + 42, CRC, 4);	//Cola
}

char
GARPB (unsigned char *trama, unsigned char *tramaEnv, unsigned char *Mac)
{
  memcpy (tramaEnv + 0, MACbro, 6);	//Encabezado MAC: Direccion Destino
  memcpy (tramaEnv + 6, Mac, 6);	//Encabezado MAC: Direccion Fuente
  memcpy (tramaEnv + 12, ethertype, 2);	//Mensaje ARP: Tipo
  memcpy (tramaEnv + 14, HPHP, 6);	//Mensaje ARP: Longitud
  memcpy (tramaEnv + 20, OP, 2);	//Mensaje ARP: Opcode
  memcpy (tramaEnv + 22, Mac, 6);	//Sender Hardware Address 
  memcpy (tramaEnv + 28, trama + 28, 4);	//Sender Protocol Address
  memcpy (tramaEnv + 32, MACbro, 6);	//Target Hardware Address
  memcpy (tramaEnv + 38, trama + 28, 4);	//Target Protocol Address
  memcpy (tramaEnv + 42, CRC, 4);	//Cola
}

void
inicio (MYSQL * con)
{
  int packet_socket, indice;
  packet_socket = socket (AF_PACKET, SOCK_RAW, htons (ETH_P_ALL));
  if (packet_socket == -1)
    {
      perror ("\nError al abrir el socket\n");
      exit (0);
    }
  else
    {
      printf ("\nExito al abrir el socket\n");
      indice = obtenerDatos (packet_socket);
      while (contador <= 255)
	{
	  cambiaIP ();
	  estructuraTrama (tramaEnv);
	  enviaTrama (tramaEnv, packet_socket, indice);
	  recibeTrama (packet_socket, tramaRev, con);
	  contador++;
	}
    }
  close (packet_socket);
}

void
cambiaIP ()
{
  unsigned char octeto;
  octeto = IpDes[3] + 1;
  IpDes[3] = octeto;
}

void
recibeTrama (int ds, unsigned char *trama, MYSQL * con)
{
  char consulta[1024];
  unsigned char OP2[2] = {
    0x00, 0x02
  };
  int bandera = 0;
  int tam, i;
  struct timeval start, end;
  long mtime = 0, seconds, useconds;
  gettimeofday (&start, NULL);

  while (mtime < 300)
    {
      tam = recvfrom (ds, trama, 1514, MSG_DONTWAIT, NULL, 0);

      if (!memcmp (ethertype, trama + 12, 2) && !memcmp (OP2, trama + 20, 2)
	  && !memcmp (IpDes, trama + 28, 4))
	{
	  printf ("La Ip ");
	  printf ("%hhu.%hhu.%hhu.%hhu", IpDes[0], IpDes[1], IpDes[2],
		  IpDes[3]);
	  printf ("Esta en la red  ");
	  memcpy (MACT, trama + 6, 6);
	  sprintf (consulta,
		   "INSERT INTO red VALUES('%d.%d.%d.%d','%.2x:%.2x:%.2x:%.2x:%.2x:%.2x')",
		   IpDes[0], IpDes[1], IpDes[2], IpDes[3], MACT[0], MACT[1],
		   MACT[2], MACT[3], MACT[4], MACT[5]);
	  if (mysql_query (con, consulta) == 0)
	    {
	      fprintf (stdout, "\nDatos insertados con exito\n");
	    }
	  bandera = 1;
	}
      gettimeofday (&end, NULL);
      seconds = end.tv_sec - start.tv_sec;
      useconds = end.tv_usec - start.tv_usec;
      mtime = ((seconds) * 1000 + useconds / 1000.0) + 0.5;
      if (bandera == 1)
	break;
    }
  printf ("Elapsed time: %ld miliseconds\n", mtime);
}

void
enviaTrama (unsigned char *trama, int ds, int index)
{
  int tam;
  struct sockaddr_ll interfaz;
  memset (&interfaz, 0x00, sizeof (interfaz));
  interfaz.sll_family = AF_PACKET;
  interfaz.sll_protocol = htons (ETH_P_ALL);
  interfaz.sll_ifindex = index;
  tam =
    sendto (ds, trama, 60, 0, (struct sockaddr *) &interfaz,
	    sizeof (interfaz));
  if (tam == -1)
    perror ("\nError al enviar\n");
}

char
estructuraTrama (unsigned char *trama)
{
  memcpy (trama + 0, MACbro, 6);
  memcpy (trama + 6, MACorigen, 6);
  memcpy (trama + 12, ethertype, 2);
  memcpy (trama + 14, HPHP, 6);
  memcpy (trama + 20, OP, 2);
  memcpy (trama + 22, MACorigen, 6);
  memcpy (trama + 28, ip, 4);
  memcpy (trama + 32, MacDes, 6);
  memcpy (trama + 38, IpDes, 4);
  memcpy (trama + 42, CRC, 4);
}

int
obtenerDatos (int ds)
{

  struct ifreq nic;
  int index, i;
  printf ("\nInserta el nombre: ");
  scanf ("%s", nic.ifr_name);
  if (ioctl (ds, SIOCGIFINDEX, &nic) == -1)
    {
      perror ("\nError al obtener indice\n");
      exit (0);
    }
  else
    {
      index = nic.ifr_ifindex;
      printf ("El indice es: %d\n", index);
    }
  if (ioctl (ds, SIOCGIFHWADDR, &nic) == -1)
    {
      perror ("\nError al obtener la MAC\n");
      exit (0);
    }
  else
    {
      memcpy (MACorigen, nic.ifr_hwaddr.sa_data, 6);
      printf ("Direccion MAC: ");
      for (i = 0; i < 6; i++)
	{
	  printf ("%.2x:", MACorigen[i]);
	}
      if (ioctl (ds, SIOCGIFADDR, &nic) == -1)
	perror ("Error al obtener ip");
      else
	{
	  memcpy (ip, nic.ifr_addr.sa_data + 2, 4);
	}
      printf ("\n");
      printf ("Introduzca la IP destino:");
      scanf ("%hhu.%hhu.%hhu.%hhu", &IpDes[0], &IpDes[1], &IpDes[2],
	     &IpDes[3]);
      printf ("\n");
    }
  return index;
}
