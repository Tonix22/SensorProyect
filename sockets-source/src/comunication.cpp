#include <comunication.hpp>

using namespace std;

/*  The server runs forever. */

char *date ()
{
  time_t raw = time (&raw);
  struct tm *info = localtime (&raw);
  char *text = asctime (info);
  text[strlen(text)-1] = '\0'; // remove '\n'
  return text;
}

int server (const char *url)
{
    int sz_date = strlen (DATE) + 1; // '\0' too
    int sock = nn_socket (AF_SP, NN_REP);
    assert (sock >= 0);
    if (nn_bind (sock, url) < 0) {
        fprintf (stderr, "nn_bind: %s\n", nn_strerror (nn_errno ()));
        nn_close (sock);
        return (-1);
    }
    while (1)
    {
        char *buf = NULL;
        int bytes = nn_recv (sock, &buf, NN_MSG, 0);
        assert (bytes >= 0);
        if (strncmp (DATE, buf, sz_date) == 0)
        {
            printf ("SERVER: RECEIVED DATE REQUEST\n");
            char *d = date();
            int sz_d = strlen(d) + 1; // '\0' too
            printf ("SERVER: SENDING DATE %s\n", d);
            bytes = nn_send (sock, d, sz_d, 0);
            assert (bytes == sz_d);
        }   
        nn_freemsg (buf);
    }
  return nn_shutdown (sock, 0);
  
}

int client (const char *url)
{
  int sz_date = strlen(DATE) + 1; // '\0' too
  char *buf = NULL;
  int bytes = -1;
  int sock = nn_socket (AF_SP, NN_REQ);
  assert (sock >= 0);
  assert (nn_connect (sock, url) >= 0);
  printf ("CLIENT: SENDING DATE REQUEST %s\n", DATE);
  bytes = nn_send (sock, DATE, sz_date, 0);
  assert (bytes == sz_date);
  bytes = nn_recv (sock, &buf, NN_MSG, 0);
  assert (bytes >= 0);
  printf ("CLIENT: RECEIVED DATE %s\n", buf);
  nn_freemsg (buf);
  return nn_shutdown (sock, 0);
}
