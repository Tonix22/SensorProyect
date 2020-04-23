#include <comunication.hpp>
#include <string>
#include <unordered_set>
using namespace std;

/*  The server runs forever. */
unordered_set<string> cmd;

char *get_time_stap ()
{
  time_t raw = time (&raw);
  struct tm *info = localtime (&raw);
  char *text = asctime (info);
  text[strlen(text)-1] = '\0'; // remove '\n'
  return text;
}

void init_commands()
{
    cmd.insert(DATE);
    cmd.insert(QUERY);
    cmd.insert(TEMP);
    cmd.insert(HUMIDTY);
    cmd.insert(BOTH);
    cmd.insert(TIMEQUERY); // GO TO SEARCH TO SQL DATABASE
}

bool message_process(char* msg)
{
    char *token = strtok(msg, " ");
    bool valid_param = false;
    if(cmd.find(token) != cmd.end())
    {
        cout << "SERVER: RECEIVED DATE REQUEST" << std::endl;
        valid_param =true;
        while (token != NULL) 
        { 
            printf("parameters: %s\n", token); 
            token = strtok(NULL, " "); 
        }  
    }

    return valid_param;
}


int server (const char *url)
{
    int sock = nn_socket (AF_SP, NN_REP);
    assert (sock >= 0);

    //binding
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
            printf ("SERVER: RECEIVED DATE REQUEST\n");
            char *d = get_time_stap();
            int sz_d = strlen(d) + 1; // '\0' end of string
            printf ("SERVER: SENDING DATE %s\n", d);
            bytes = nn_send (sock, d, sz_d, 0);
            assert (bytes == sz_d);
        }
    
        nn_freemsg (buf);
    }
    return nn_shutdown (sock, 0);
  
}

int client (const char *url, int argc, char const *argv[])
{
    char *buf = NULL;
    int bytes = -1;
    string send_command;
    if(argc == 4 )
    {
        send_command= argv[2];
        send_command+= " ";
        send_command+=argv[3];
    }
    else if (argc == 5)
    {
        send_command=  argv[2];
        send_command+=  " ";
        send_command+= argv[3];
        send_command+=  " ";
        send_command+= argv[4];
    }
    else 
    {
      std::cout << argc << std::endl;
    }
    
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
