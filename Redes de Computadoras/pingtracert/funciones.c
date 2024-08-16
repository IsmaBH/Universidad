#include "funciones.h"
/**********************************************************VARIABLES PARA LA RESOLUCION DE NOMBRES ARP********************************/
FILE *fichero;
unsigned char tramaEnv[1514];                                           //Variable donde se estructurara las tramas.
unsigned char ip[4];                                                    //Variable donde se guarda la ip de la propia computadora
unsigned char MACorigen[6];                                             //Variable donde se guarga la MAC de la propia computadora
unsigned char IpPuerta[4];	                                                //ip de la cual queremos saber la direccion MAC (Puerta de enlace)
unsigned char MacPuerta[6];                                             //Mac de la puerta de enlace.
unsigned char MACbro[6] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };       //Broadcast
unsigned char ethertype[2] = { 0x08, 0x06 };                            //Identificador ARP
unsigned char HPHP[6] = { 0x00, 0x01, 0x08, 0x00, 0x06, 0x04 };	        //Ethertype, protocolo IP longitud MAC y longitud IP
unsigned char OP[2] = { 0x00, 0x01 };	                                //Tipo de operacion
unsigned char MacDes[6] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };	//mac destino no se sabe
unsigned char CRC[4] = { 0x00, 0x00, 0x00, 0x00 };	                //cola
FILE *fichero2;
int i;
unsigned char IpDes[4];
unsigned char Mascara[4] = {0xff,0xff,0xff,0x00};
unsigned char resultado[4];
unsigned char RedID[4];
/**************************************************************************************************************************************/
/***********************************************************VARIABLES PARA LA CABECERA DE IP*******************************************/
unsigned char tramaRev[1514];
unsigned char tramaEnv2[1514];                        //Variable en la que se estructura la solicitud de Eco
unsigned char Iptype[2] = {0x08, 0x00};
unsigned char tipotam[1] = {0x45};                    //Variable que guarda el tipo y el tamañode ip
unsigned char tamtotal[1] = {46};
unsigned char SecIp1[1];
unsigned char SecIp2[1];
unsigned char Sec[2];
unsigned char offset[1] = {0x40};
unsigned char serviceProtocol[1] = {0x01};
unsigned char bufferIp[20];
/**************************************************************************************************************************************/
/********************************************************VARIABLES PARA LA CABECERA DE ICMP********************************************/
unsigned char icmptype[2] = {0x08,0x00};
unsigned char datos[18] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x44,0x69,0x65,0x67,0x6f};
unsigned char bufferICMP[26];
unsigned char EcoR[1] = {0x00};
/**************************************************************************************************************************************/

int bienvenida()
{
  int bandera = 0;
  fichero2 = fopen ("tabladeruteo.txt", "r");
  if (fseek (fichero2, 191, SEEK_SET) == 0)
   {
     fscanf (fichero2, "%hhu.%hhu.%hhu.%hhu", &RedID[0], &RedID[1], &RedID[2], &RedID[3]);
   }
  fclose (fichero2);
  printf("Ip objetivo: ");
  scanf("%hhu.%hhu.%hhu.%hhu", &IpDes[0],&IpDes[1],&IpDes[2],&IpDes[3]);
  for(i= 0; i <= 3; i++)
  {
    resultado[i] = IpDes[i] & Mascara[i];
  }
  printf("\n");
  if(!memcmp (resultado, RedID, 4))
  {
    printf("La maquina esta dentro de la red\n");
    bandera = 1;
    return bandera;
  }
  else{
    printf("Enviando a puerta de enlace\n");
    bandera = 2;
    return bandera;
  }
}

unsigned char 
randomSec(int contador)
{
   int i;
   unsigned char Sec;
   //unsigned char t;  
   struct timeval time; 
   gettimeofday(&time,NULL);
   /* Intializes random number generator */
   srand((time.tv_sec * 10000) + (time.tv_usec / 10000));

   Sec = (rand()%255 + contador);

   
   return Sec;
}

void resuelveARP(int ds, int index)
{  
  memcpy (tramaEnv + 0, MACbro, 6);
  memcpy (tramaEnv + 6, MACorigen, 6);
  memcpy (tramaEnv + 12, ethertype, 2);
  memcpy (tramaEnv + 14, HPHP, 6);
  memcpy (tramaEnv + 20, OP, 2);
  memcpy (tramaEnv + 22, MACorigen, 6);
  memcpy (tramaEnv + 28, ip, 4);
  memcpy (tramaEnv + 32, MacDes, 6);
  memcpy (tramaEnv + 38, IpPuerta, 4);
  memcpy (tramaEnv + 42, CRC, 4);
  
  enviaTrama (tramaEnv, ds, index);
  recibeTrama(ds, tramaRev, "/0x00/", "/0x00", 1);
}

int recibeTrama (int ds, unsigned char *trama,unsigned char *identificador1, unsigned char *identificador2, int ttl)
{
    unsigned char OP2[2] = { 0x00, 0x02 };
    unsigned char IpNodo[4];
    unsigned char r1[1] = {0x0b};
    unsigned char r2[1] = {0x00};
    int bandera = 0;
    int tam, i, len, Opcion;
    struct timeval start, end;
    long mtime = 0, seconds, useconds;
    gettimeofday (&start, NULL);
    tam = recvfrom (ds, trama, 1514,0, NULL, 0);
    if (!memcmp (ethertype, trama + 12, 2) && !memcmp (OP2, trama + 20, 2) && !memcmp (IpPuerta, trama + 28, 4))
	{
          memcpy(MacPuerta, trama + 6, 6);
	}else
            {
              while (mtime < 25)
                  {
	            tam = recvfrom (ds, trama, 1514,MSG_DONTWAIT, NULL, 0);
                    if(!memcmp (MACorigen, trama + 0,6) && !memcmp(r1, trama + 34,1) && !memcmp(r2, trama + 35,1) || !memcmp (IpDes, trama + 26,4))
                     { 
                       memcpy(IpNodo, trama + 26, 4);
                       printf("Ip del Nodo que respondio = %hhu.%hhu.%hhu.%hhu, ttl = %hhu \n", IpNodo[0], IpNodo[1], IpNodo[2], IpNodo[3], ttl);
                       bandera = 1;
                       //Opcion = 1;
                       if(!memcmp (IpNodo, IpDes,4))
                        {
                          Opcion = 2;
                        }
                     }
	            gettimeofday (&end, NULL);
	            seconds = end.tv_sec - start.tv_sec;
	            useconds = end.tv_usec - start.tv_usec;
	            mtime = ((seconds) * 1000 + useconds / 1000.0) + 0.5;
	            if (bandera == 1)
	               break;
                  }
            }
return Opcion;
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
      //printf ("El indice es: %d\n", index);
    }
  if (ioctl (ds, SIOCGIFHWADDR, &nic) == -1)
    {
      perror ("\nError al obtener la MAC\n");
      exit (0);
    }
  else
    {
      memcpy (MACorigen, nic.ifr_hwaddr.sa_data, 6);
      /*printf ("Direccion MAC: ");
      for (i = 0; i < 6; i++)
	{
	  printf ("%.2x:", MACorigen[i]);
	}*/
      if (ioctl (ds, SIOCGIFADDR, &nic) == -1)
	perror ("Error al obtener ip");
      else
	{
	  memcpy (ip, nic.ifr_addr.sa_data + 2, 4);
	}
        fichero = fopen ("tabladeruteo.txt", "r");
        if (fseek (fichero, 128, SEEK_SET) == 0)
         {
           fscanf (fichero, "%hhu.%hhu.%hhu.%hhu", &IpPuerta[0], &IpPuerta[1], &IpPuerta[2], &IpPuerta[3]);
         }
      fclose (fichero);
      printf ("\n");
    }
  return index;
}

void
solicitudEco (int bandera, int ds, int index, unsigned char *identificador1, unsigned char *identificador2, unsigned char *secuencia, int contador, int ttl)
{
  int cantidad;
  unsigned char ttli[1];
  unsigned char * ptr, *ptr1;
  unsigned short ckSum = 0;
  unsigned short ckSumi = 0;
  unsigned char checksum[2] = {0x00,0x00};
  unsigned char checksumic[2] = {0x00,0x00};

  ptr =(char *) &ttl;
     ptr1=ptr;
     for(&ptr; *ptr; ptr++)
       {
         ttli[(int)(ptr-ptr1)] = *ptr;
       }

  if(bandera == 1)
   {
     SecIp1[0] = randomSec(contador);
     SecIp2[0] = randomSec(contador) - 1;
     
     memcpy (tramaEnv2 + 0, MacPuerta, 6);           //Parte de la cabecera Ethernet
     memcpy (tramaEnv2 + 6, MACorigen, 6);           //Parte de la cabecera Ethernet
     memcpy (tramaEnv2 + 12, Iptype, 2);             //Parte de la cabcera Ethernet
     memcpy (tramaEnv2 + 14, tipotam, 1);            //Inicio de la cabecera de IP
     memcpy (tramaEnv2 + 17, tamtotal, 1);
     memcpy (tramaEnv2 + 18, SecIp1, 1);             //Numero de identificacion 1
     memcpy (tramaEnv2 + 19, SecIp2, 1);             //Numero de identificacion 2
     memcpy (tramaEnv2 + 20, offset, 1);             //Opciones de Ip
     memcpy (tramaEnv2 + 22, ttli, 1);                //ttl
     memcpy (tramaEnv2 + 23, serviceProtocol, 1);    //Identificador del protocolo al que le da servicio
     memcpy (tramaEnv2 + 24, checksum, 2);                  //Comprobacion del checksum (en ip deshabilitado)
     memcpy (tramaEnv2 + 26, ip, 4);                 //Direccion Ip fuente(la propia)
     memcpy (tramaEnv2 + 30, IpDes, 4);              //Direccion Ip a donde se quiere llegar Aqui termina la cabecera de IP
     memcpy(bufferIp, tramaEnv2 + 14, (int)sizeof(bufferIp));     
     ckSum = sacarchecksum(bufferIp, (int)sizeof(bufferIp));
     ptr =(char *) &ckSum;
     ptr1=ptr;
     for(&ptr; *ptr; ptr++)
       {
         checksum[(int)(ptr-ptr1)] = *ptr;
       }
     memset(tramaEnv2 + 24, checksum[1], 1);
     memset(tramaEnv2 + 25, checksum[0], 1);
     
     memcpy (tramaEnv2 + 34, icmptype, 2);                    //Aqui comienza la cabecera de ICMP con su identificador y OP code
     memcpy (tramaEnv2 + 36, checksumic, 2);                  //Checksum de ICMP.
     memcpy (tramaEnv2 + 38, identificador1, 1);              //Numero de identificacion
     memcpy (tramaEnv2 + 39, identificador2, 1);
     memcpy (tramaEnv2 + 41, secuencia, 2);                   //Numero de secuencia para ICMP
     memcpy (tramaEnv2 + 43, datos, 18);                       //datos de ICMP
     
     memcpy(bufferICMP, tramaEnv2 + 34, 26);
     ckSumi = sacarchecksum(bufferICMP, (int)sizeof(bufferICMP));
     ptr =(char *) &ckSumi;
     ptr1=ptr;
     for(&ptr; *ptr; ptr++)
       {
         checksumic[(int)(ptr-ptr1)] = *ptr;
       }
     memset(tramaEnv2 + 36, checksumic[1], 1);
     memset(tramaEnv2 + 37, checksumic[0], 1);
     enviaTrama (tramaEnv2, ds, index);
   } 

  if(bandera == 2)
   {
     SecIp1[0] = randomSec(contador);
     SecIp2[0] = randomSec(contador) - 1;
     
     memcpy (tramaEnv2 + 0, MacPuerta, 6);           //Parte de la cabecera Ethernet
     memcpy (tramaEnv2 + 6, MACorigen, 6);           //Parte de la cabecera Ethernet
     memcpy (tramaEnv2 + 12, Iptype, 2);             //Parte de la cabcera Ethernet
     memcpy (tramaEnv2 + 14, tipotam, 1);            //Inicio de la cabecera de IP
     memcpy (tramaEnv2 + 17, tamtotal, 1);
     memcpy (tramaEnv2 + 18, SecIp1, 1);             //Numero de identificacion 1
     memcpy (tramaEnv2 + 19, SecIp2, 1);             //Numero de identificacion 2
     memcpy (tramaEnv2 + 20, offset, 1);             //Opciones de Ip
     memcpy (tramaEnv2 + 22, ttli, 1);                //ttl
     memcpy (tramaEnv2 + 23, serviceProtocol, 1);    //Identificador del protocolo al que le da servicio
     memcpy (tramaEnv2 + 24, checksum, 2);                  //Comprobacion del checksum (en ip deshabilitado)
     memcpy (tramaEnv2 + 26, ip, 4);                 //Direccion Ip fuente(la propia)
     memcpy (tramaEnv2 + 30, IpDes, 4);              //Direccion Ip a donde se quiere llegar Aqui termina la cabecera de IP
     memcpy(bufferIp, tramaEnv2 + 14, (int)sizeof(bufferIp));     
     ckSum = sacarchecksum(bufferIp, (int)sizeof(bufferIp));
     ptr =(char *) &ckSum;
     ptr1=ptr;
     for(&ptr; *ptr; ptr++)
       {
         checksum[(int)(ptr-ptr1)] = *ptr;
       }
     memset(tramaEnv2 + 24, checksum[1], 1);
     memset(tramaEnv2 + 25, checksum[0], 1);
     
     memcpy (tramaEnv2 + 34, icmptype, 2);                    //Aqui comienza la cabecera de ICMP con su identificador y OP code
     memcpy (tramaEnv2 + 36, checksumic, 2);                  //Checksum de ICMP.
     memcpy (tramaEnv2 + 38, identificador1, 1);              //Numero de identificacion
     memcpy (tramaEnv2 + 39, identificador2, 1);
     memcpy (tramaEnv2 + 41, secuencia, 2);                   //Numero de secuencia para ICMP
     memcpy (tramaEnv2 + 43, datos, 18);                       //datos de ICMP
     
     memcpy(bufferICMP, tramaEnv2 + 34, 26);
     ckSumi = sacarchecksum(bufferICMP, (int)sizeof(bufferICMP));
     ptr =(char *) &ckSumi;
     ptr1=ptr;
     for(&ptr; *ptr; ptr++)
       {
         checksumic[(int)(ptr-ptr1)] = *ptr;
       }
     memset(tramaEnv2 + 36, checksumic[1], 1);
     memset(tramaEnv2 + 37, checksumic[0], 1);
     enviaTrama (tramaEnv2, ds, index);
   } 
}


unsigned short sacarchecksum (unsigned char * buff, int bufflen){
    unsigned short cksum=0;
    unsigned short acarreo=0;
    int i, suma = 0, resultado=0,temp=0;
    for(i=0; i<bufflen; i=i+2){
        temp=(buff[i]<<8)+buff[i+1];
        suma = suma+temp;
        temp=0;
    }
    acarreo=suma>>16;
    resultado = (suma&0x0000FFFF)+acarreo;
    acarreo=resultado>>16;
    resultado = (resultado&0x0000FFFF)+acarreo;
    cksum =0xffff-resultado;
    return cksum;
}

void
imprimeTrama (unsigned char *paq, int len)
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
