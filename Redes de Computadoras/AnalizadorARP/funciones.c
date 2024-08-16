#include "funciones.h"

unsigned char IpT[4];
unsigned char MACT[6];
unsigned char ip[4];
unsigned char MACorigen[6];
unsigned char MACbro[6] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
unsigned char ethertype[2] = { 0x08, 0x06 };
unsigned char HPHP[6] = { 0x00, 0x01, 0x08, 0x00, 0x06, 0x04 };	//Ethertype, protocolo IP longitud MAC y longitud IP
unsigned char OP[2] = { 0x00, 0x01 };	//Tipo de operacion
unsigned char MacDes[6] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };	//mac destino no se sabe
unsigned char CRC[4] = { 0x00, 0x00, 0x00, 0x00 };	//cola

unsigned char IpDes[4];		//ip de la cual queremos saber la direccion MAC


/*void
agrega (MYSQL * con, char* IpT, char* MACT)
{
  char consulta[1024];
  sprintf (consulta, "INSERT INTO red VALUES('%s','%s')", IpT, MACT);
  if (mysql_query (con, consulta) == 0)
    {
      /*fprintf (stdout, "\nDatos insertados con exito\n");
    }
}*/

  void cambiaIP ()
  {
    unsigned char octeto;
    octeto = IpDes[3] + 1;
    IpDes[3] = octeto;
  }

  void imprimeTrama (unsigned char *paq, int len)
  {
    int i;
    for (i = 0; i < len; i++)
      {
	if (i % 16 == 0)
	  printf ("\n");
	printf ("%.2x ", paq[i]);
      }
    printf ("\n");
  }

  void recibeTrama (int ds, unsigned char *trama, MYSQL *con)
  {
    char consulta[1024];
    unsigned char OP2[2] = { 0x00, 0x02 };
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
	    memcpy (IpT, trama + 38, 4);
	    memcpy (MACT, trama + 6, 6);
            sprintf (consulta, "INSERT INTO red VALUES('%d.%d.%d.%d','%.2x:%.2x:%.2x:%.2x:%.2x:%.2x')", IpDes[0],IpDes[1],IpDes[2],IpDes[3], MACT[0], MACT[1], MACT[2], MACT[3],MACT[4], MACT[5]);
            if (mysql_query (con, consulta) == 0)
               {
                 fprintf (stdout, "\nDatos insertados con exito\n");
               }
	    /*agrega (con, IpT, MACT);*/
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

  void enviaTrama (unsigned char *trama, int ds, int index)
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

  char estructuraTrama (unsigned char *trama, char *mensaje)
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

  int obtenerDatos (int ds)
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
