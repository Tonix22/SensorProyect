#include <comunication.hpp>
#include <message_wrap.hpp>
#include <string>
using namespace std;

/*  The server runs forever. */

extern string send_command;

int server_socket (const char *url)
{
    int sock = nn_socket (AF_SP, NN_REP);
    assert (sock >= 0);

    if (nn_bind (sock, url) < 0) 
    {
        fprintf (stderr, "nn_bind: %s\n", nn_strerror (nn_errno ()));
        nn_close (sock);
        return (-1);
    }

    while (1)
    {
        char *buf = NULL;
        int bytes = nn_recv (sock, &buf, NN_MSG, 0);
        assert (bytes >= 0);
        if (message_process(buf) == true)
        {
            const char *d = get_response();
            printf("response %s\r\n",d);
            //printf ("SERVER: RECEIVED DATE REQUEST\n");
            //char *d = get_time_stap();
            int sz_d = strlen(d) + 1; // '\0' end of string
            //printf ("SERVER: SENDING DATE %s\n", d);
            bytes = nn_send (sock, d, sz_d, 0);
            assert (bytes == sz_d);
        }
    
        nn_freemsg (buf);
    }
    return nn_shutdown (sock, 0);
  
}

int client_socket (const char *url)
{
    char *buf = NULL;
    int bytes = -1;
    
    int sock = nn_socket (AF_SP, NN_REQ);
    assert (sock >= 0);
    assert (nn_connect (sock, url) >= 0);
    printf ("CLIENT: SENDING DATE REQUEST %s\n", DATE);
    bytes = nn_send (sock, send_command.c_str(), send_command.size(), 0);
    assert (bytes == send_command.size());
    bytes = nn_recv (sock, &buf, NN_MSG, 0);
    assert (bytes >= 0);
    printf ("CLIENT: RECEIVED DATE %s\n", buf);
    nn_freemsg (buf);
    return nn_shutdown (sock, 0);
}
