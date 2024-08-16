/**********************************************************************
* 
file:   pcap_main.c
*
 date:   Tue Jun 19 20:07:49 PDT 2001  
* 
Author: Martin Casado
* 
Last Modified:2001-Jun-23 12:55:45 PM
*
* 
Description: 
*
 main program to test different call back functions
* to pcap_loop();
*

* Compile with:
* gcc -Wall -pedantic pcap_main.c -lpcap (-o foo_err_something) 
*

* Usage:
* a.out (# of packets) "filter string"

*
**********************************************************************
*/

#include <pcap.h>

#include <stdio.h>

#include <stdlib.h>

#include<string.h>

#include <errno.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <arpa/inet.h>

#include <netinet/if_ether.h>

#include <net/ethernet.h>

#include <netinet/ether.h>


unsigned char sup[][4] = { "RR", "RNR", "REJ", "SREJ" };

unsigned char CR[2] = { 'C', 'R' };

unsigned char UNC[][6] =
  { "UI", "SIM", "", "SARM", "UP", "", "", "SABM", "DISC", "", "", "SARME",
"", "", "", "SABME", "SNRM", "", "", "RSET", "", "", "", "XID", "", "", "", "SNRME" };

char UNR[][6] =
  { "UI", "RIM", "", "DM", "", "", "", "", "RD", "", "", "", "UA", "", "", "",
"", "FRMR", "", "", "", "", "", "XID" };

/*
 * workhorse function
 */
int
analizaLLC (unsigned char t[], char resultado[])
{
  unsigned char valor = 0;
  int i;
  for (i = 0; i < 12; i++)
    {
      if (i == 0)
	sprintf (resultado, " %.2x ", t[i]);
      else
	{
	  if (i == 6)
	    sprintf (resultado + strlen (resultado), " %.2x ", t[i]);
	  else
	    sprintf (resultado + strlen (resultado), "%.2x ", t[i]);
	}
    }
  sprintf (resultado + strlen (resultado), " LLC");
  valor = t[16] & 3;
  switch ( valor )
    {
    case 0:			//inf
      sprintf (resultado + strlen (resultado), " informacion");
      sprintf (resultado + strlen (resultado), " %c", CR[(t[16] & 16) >> 4]);
      sprintf (resultado + strlen (resultado), " S=%.2x", t[14]);
      sprintf (resultado + strlen (resultado), " D=%.2x", t[15]);
      sprintf (resultado + strlen (resultado), " NS=%d", (t[16] & 14) >> 1);
      sprintf (resultado + strlen (resultado), " NR=%d", (t[16] & 224) >> 5);
      break;
    case 1:			//sup
      sprintf (resultado + strlen (resultado), " supervision");
      sprintf (resultado + strlen (resultado), " %c", CR[(t[16] & 16) >> 4]);
      sprintf (resultado + strlen (resultado), " S=%.2x", t[14]);
      sprintf (resultado + strlen (resultado), " D=%.2x", t[15]);
      sprintf (resultado + strlen (resultado), " %s", sup[(t[16] & 12) >> 2]);	//FALTA INTERCAMBIAR 01 Y 10
      sprintf (resultado + strlen (resultado), " NR=%d", (t[16] & 224) >> 5);

      break;
    case 3:			//un
      sprintf (resultado + strlen (resultado), " %c", CR[(t[16] & 16) >> 4]);
      sprintf (resultado + strlen (resultado), " noNumerada");
      sprintf (resultado + strlen (resultado), " S=%.2x", t[14]);
      sprintf (resultado + strlen (resultado), " D=%.2x", t[15]);
      if (((t[16] & 12) >> 2) + ((t[16] & 224) >> 3) == 3
	  || ((t[16] & 12) >> 2) + ((t[16] & 224) >> 3) == 8
	  || ((t[16] & 12) >> 2) + ((t[16] & 224) >> 3) == 1
	  || ((t[16] & 12) >> 2) + ((t[16] & 224) >> 3) == 23
	  || ((t[16] & 12) >> 2) + ((t[16] & 224) >> 3) == 17)
	{

	  if ((t[16] & 16) >> 4)
	    {			// if p/f ACTIVADO
	      sprintf (resultado + strlen (resultado), " %s",
		       UNR[((t[16] & 12) >> 2) + ((t[16] & 224) >> 3)]);
	    }
	  else
	    {
	      sprintf (resultado + strlen (resultado), " %s",
		       UNC[((t[16] & 12) >> 2) + ((t[16] & 224) >> 3)]);
	    }

	}
      else
	{
	  sprintf (resultado + strlen (resultado), " %s",
		   UNC[((t[16] & 12) >> 2) + ((t[16] & 224) >> 3)]);
	}

      break;
      default:
	 fprintf(stderr, "Caso no encontrado... %d\n", valor );
    }
  sprintf (resultado + strlen (resultado), "\n");

}

void
my_callback (u_char * args, const struct pcap_pkthdr *pkthdr, const u_char *
	     packet)
{
  char resultado[200];
  if (~packet[12] & 63)
    {
      switch (packet[12] & 192)
	{
	case 3:
	  break;
	default:
	  analizaLLC ((u_char *) packet, resultado);
	  printf ("%s", resultado);
	  break;
	}

    }
  //printf("\n");
}


int
main (int argc, char **argv)
{
  char *dev;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *descr;
  struct bpf_program fp;	/* hold compiled program     */
  bpf_u_int32 maskp;		/* subnet mask               */
  bpf_u_int32 netp;		/* ip                        */
  u_char *args = NULL;
  struct pcap_pkthdr *header;
  const unsigned char resultado[200];
  /* Options must be passed in as a string because I am lazy */
  if (argc < 1)
    {
      fprintf (stdout, "Usage: %s numpackets \"options\"\n", argv[0]);
      return 0;
    }

  /* grab a device to peak into... */
  dev = pcap_lookupdev (errbuf);
  if (dev == NULL)
    {
      printf ("%s\n", errbuf);
      exit (1);
    }

  /* ask pcap for the network address and mask of the device */
  pcap_lookupnet (dev, &netp, &maskp, errbuf);

  /* open device for reading. NOTE: defaulting to
   * promiscuous mode*/
  descr = pcap_open_live (dev, BUFSIZ, 1, -1, errbuf);
  if (descr == NULL)
    {
      printf ("pcap_open_live(): %s\n", errbuf);
      exit (1);
    }


  if (argc <= 2)
    {
      /* Lets try and compile the program.. non-optimized */
      if (pcap_compile (descr, &fp, argv[2], 0, netp) == -1)
	{
	  fprintf (stderr, "Error calling pcap_compile\n");
	  exit (1);
	}

      /* set the compiled program as the filter */
      if (pcap_setfilter (descr, &fp) == -1)
	{
	  fprintf (stderr, "Error setting filter\n");
	  exit (1);
	}
    }

  /* ... and loop */
  //pcap_next_ex(descr,&header,&resultado);
  pcap_loop (descr, atoi (argv[1]), my_callback, args);

  fprintf (stdout, "\nfinished\n");
  return 0;
}
